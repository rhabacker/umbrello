/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2006-2014                                               *
 *   Umbrello UML Modeller Authors <umbrello-devel@kde.org>                *
 ***************************************************************************/

// own header
#include "pythonimport.h"

// app includes
#include "attribute.h"
#include "classifier.h"
#include "codeimpthread.h"
#include "debug_utils.h"
#include "enum.h"
#include "import_utils.h"
#include "operation.h"
#include "package.h"
#include "uml.h"
#include "umldoc.h"
#include "umlpackagelist.h"

// qt includes
#include <QRegExp>

/**
 * Constructor.
 */
PythonImport::PythonImport(CodeImpThread* thread)
  : NativeImportBase(QLatin1String("#"), thread)
{
    setMultiLineComment(QLatin1String("\"\"\""), QLatin1String("\"\"\""));
    initVars();
}

/**
 * Destructor.
 */
PythonImport::~PythonImport()
{
}

/**
 * Reimplement operation from NativeImportBase.
 */
void PythonImport::initVars()
{
    m_srcIndentIndex = 0;
    m_srcIndent[m_srcIndentIndex] = 0;
    m_braceWasOpened = false;
    m_isStatic = false;
}

/**
 * Reimplement operation from NativeImportBase.
 * In addition to handling multiline comments, this method transforms
 * changes in leading indentation into braces (opening brace for increase
 * in indentation, closing brace for decrease in indentation) in m_source.
 * Removal of Python's indentation sensitivity simplifies subsequent
 * processing using Umbrello's native import framework.
 * @param line   the line to preprocess
 * @return success status of operation
 */
bool PythonImport::preprocess(QString& line)
{
    if (NativeImportBase::preprocess(line))
        return true;
    // Handle single line comment
    int pos = line.indexOf(m_singleLineCommentIntro);
    if (pos != -1) {
        QString cmnt = line.mid(pos);
        m_source.append(cmnt);
        m_srcIndex++;
        if (pos == 0)
            return true;
        line = line.left(pos);
        line.remove(QRegExp(QLatin1String("\\s+$")));
    }
    // Transform changes in indentation into braces a la C++/Java/Perl/...
    pos = line.indexOf(QRegExp(QLatin1String("\\S")));
    if (pos == -1)
        return true;
    bool isContinuation = false;
    int leadingWhite = line.left(pos).count(QRegExp(QLatin1String("\\s")));
    if (leadingWhite > m_srcIndent[m_srcIndentIndex]) {
        if (m_srcIndex == 0) {
            uError() << "internal error";
            return true;
        }
        if (m_braceWasOpened) {
            m_srcIndent[++m_srcIndentIndex] = leadingWhite;
            m_braceWasOpened = false;
        } else {
            isContinuation = true;
        }
    } else {
        while (m_srcIndentIndex > 0 && leadingWhite < m_srcIndent[m_srcIndentIndex]) {
            m_srcIndentIndex--;
            m_source.append(QLatin1String("}"));
            m_srcIndex++;
        }
    }

    if (m_braceWasOpened && m_srcIndentIndex == 0) {
        m_source.append(QLatin1String("}"));
        m_srcIndex++;
    }

    if (line.endsWith(QLatin1Char(':'))) {
        line.replace(QRegExp(QLatin1String(":$")), QLatin1String("{"));
        m_braceWasOpened = true;
    } else {
        m_braceWasOpened = false;
    }
    if (!isContinuation && !m_braceWasOpened)
        line += QLatin1Char(';');
    return false;  // The input was not completely consumed by preprocessing.
}

/**
 * Implement abstract operation from NativeImportBase.
 * @param word   whitespace delimited item
 */
void PythonImport::fillSource(const QString& word)
{
    QString lexeme;
    const uint len = word.length();
    for (uint i = 0; i < len; ++i) {
        const QChar& c = word[i];
        if (c.isLetterOrNumber() || c == QLatin1Char('_') || c == QLatin1Char('.')) {
            lexeme += c;
        } else {
            if (!lexeme.isEmpty()) {
                m_source.append(lexeme);
                m_srcIndex++;
                lexeme.clear();
            }
            m_source.append(QString(c));
            m_srcIndex++;
        }
    }
    if (!lexeme.isEmpty()) {
        m_source.append(lexeme);
        m_srcIndex++;
    }
}

/**
 * Return an amount of spaces that corresponds to @param level
 * @return spaces of indentation
 */
QString PythonImport::indentation(int level)
{
    QString spaces;
    for (int i = 0; i < level; ++i) {
        spaces += QLatin1String("  ");
    }
    return spaces;
}

/**
 * Skip ahead to outermost closing brace.
 * @return  body contents skipped
 */
QString PythonImport::skipBody()
{
    /* During input preprocessing, changes in indentation were replaced by
       braces, and a semicolon was appended to each line ending.
       In order to return the body, we try to reconstruct the original Python
       syntax by reverting those changes.
     */
    QString body;
    if (m_source[m_srcIndex] != QLatin1String("{"))
        skipStmt(QLatin1String("{"));
    bool firstTokenAfterNewline = true;
    int braceNesting = 0;
    QString token;
    while (!(token = advance()).isNull()) {
        if (token == QLatin1String("}")) {
            if (braceNesting <= 0)
                break;
            braceNesting--;
            body += QLatin1Char('\n');
            firstTokenAfterNewline = true;
        } else if (token == QLatin1String("{")) {
            braceNesting++;
            body += QLatin1String(":\n");
            firstTokenAfterNewline = true;
        } else if (token == QLatin1String(";")) {
            body += QLatin1Char('\n');
            firstTokenAfterNewline = true;
        } else {
            if (firstTokenAfterNewline) {
                body += indentation(braceNesting);
                firstTokenAfterNewline = false;
            } else if (body.contains(QRegExp(QLatin1String("\\w$"))) &&
                       token.contains(QRegExp(QLatin1String("^\\w")))) {
                body += QLatin1Char(' ');
            }
            body += token;
        }
    }
    return body;
}

/**
 * Implement abstract operation from NativeImportBase.
 * @return success status of operation
 */
bool PythonImport::parseStmt()
{
    const int srcLength = m_source.count();
    const QString& keyword = m_source[m_srcIndex];
    if (keyword == QLatin1String("class")) {
        const QString& name = advance();
        UMLObject *ns = Import_Utils::createUMLObject(UMLObject::ot_Class, name,
                                                      currentScope(), m_comment);
        pushScope(m_klass = static_cast<UMLClassifier*>(ns));
        m_comment.clear();
        if (advance() == QLatin1String("(")) {
            while (m_srcIndex < srcLength - 1 && advance() != QLatin1String(")")) {
                const QString& baseName = m_source[m_srcIndex];
                Import_Utils::createGeneralization(m_klass, baseName);
                if (advance() != QLatin1String(","))
                    break;
            }
        }
        if (m_source[m_srcIndex] != QLatin1String("{")) {
            skipStmt(QLatin1String("{"));
        }
        log(QLatin1String("class ") + name);
        return true;
    }
    if (keyword == QLatin1String("@")) {
        const QString& annotation = m_source[++m_srcIndex];
        uDebug() << "annotation:" << annotation;
        if (annotation == QLatin1String("staticmethod"))
            m_isStatic = true;
        return true;
    }
    if (keyword == QLatin1String("def")) {
        if (m_klass == NULL) {
            // skip functions outside of a class
            skipBody();
            return true;
        }

        if (!m_klass->hasDoc() && !m_comment.isEmpty()) {
            m_klass->setDoc(m_comment);
            m_comment = QString();
        }

        QString name = advance();
        Uml::Visibility::Enum visibility = Uml::Visibility::Public;
        if (name.startsWith(QLatin1String("__"))) {
            visibility = Uml::Visibility::Private;
            name.remove(0, 2);
        } else if (name.startsWith(QLatin1String("_"))) {
            visibility = Uml::Visibility::Protected;
            name.remove(0, 1);
        }
        // operation
        UMLOperation *op = Import_Utils::makeOperation(m_klass, name);
        if (advance() != QLatin1String("(")) {
            uError() << "importPython def " << name << ": expecting \"(\"";
            skipBody();
            return true;
        }
        bool firstParam = true;
        while (m_srcIndex < srcLength && advance() != QLatin1String(")")) {
            const QString& parName = m_source[m_srcIndex];
            if (firstParam) {
                if (parName.compare(QLatin1String("self"), Qt::CaseInsensitive) != 0) {
                    m_isStatic = true;
                    Import_Utils::addMethodParameter(op, QLatin1String("string"), parName);
                }
                firstParam = false;
            } else {
                /*UMLAttribute *att =*/ Import_Utils::addMethodParameter(op, QLatin1String("string"), parName);
            }
            if (advance() != QLatin1String(","))
                break;
        }
        Import_Utils::insertMethod(m_klass, op, visibility, QLatin1String("string"),
                                   m_isStatic, false /*isAbstract*/, false /*isFriend*/,
                                   false /*isConstructor*/, m_comment);
        m_isStatic = false;
        op->setSourceCode(skipBody());

        if (!op->hasDoc() && !m_comment.isEmpty()) {
            op->setDoc(m_comment);
            m_comment = QString();
        }
        log(QLatin1String("def ") + name);

        return true;
    }

    if (lookAhead() == QLatin1String("=")) {
        QString variable = keyword;
        advance();
        QString value = advance();
        Uml::Visibility::Enum visibility = Uml::Visibility::Public;
        if (variable.startsWith(QLatin1String("__"))) {
            visibility = Uml::Visibility::Private;
            variable.remove(0, 2);
        } else if (variable.startsWith(QLatin1String("_"))) {
            visibility = Uml::Visibility::Protected;
            variable.remove(0, 1);
        }
        QString type;
        if (value == QLatin1String("[")) {
            if (lookAhead() == QLatin1String("]")) {
                advance();
                type = QLatin1String("list");
                value = QLatin1String("");
            }
        } else if (value == QLatin1String("{")) {
            if (lookAhead() == QLatin1String("}")) {
                advance();
                type = QLatin1String("dict");
                value = QLatin1String("");
            }
        } else if (value.startsWith(QLatin1String("\""))) {
            type = QLatin1String("string");
        } else if (value.contains(QLatin1String("."))) {
            type = QLatin1String("float");
        } else if (value == QLatin1String("True") || value == QLatin1String("False")) {
            type = QLatin1String("bool");
        } else if (!value.isEmpty()) {
            type = QLatin1String("int");
        }

        UMLObject* o = Import_Utils::insertAttribute(m_klass, visibility, variable,
                                                     type, m_comment, false);
        UMLAttribute* a = dynamic_cast<UMLAttribute*>(o);
        a->setInitialValue(value);
        log(QLatin1String("attribute ") + variable);
        return true;
    }

    if (keyword == QLatin1String("}")) {
        if (scopeIndex()) {
            m_klass = dynamic_cast<UMLClassifier*>(popScope());
        }
        else
            uError() << "parsing: too many }";
        return true;
    }
    return false;  // @todo parsing of attributes
}
