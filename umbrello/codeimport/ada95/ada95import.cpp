#include "ada95import.h"

#include "../import_utils.h"

// #ifdef emit
// #undef emit
// #endif

#include <antlr4-runtime/antlr4-runtime.h>

#include "Ada95Lexer.h"
#include "Ada95Parser.h"
#include "Ada95ParserBaseListener.h"

#include <QtDebug>

// #include <fstream>
// #include <iostream>

using namespace antlr4;

class LexerErrorListener : public antlr4::BaseErrorListener
{
public:
    bool hadError = false;

    void syntaxError(antlr4::Recognizer * /*recognizer*/,
                     antlr4::Token * /*offendingSymbol*/,
                     size_t /*line*/,
                     size_t /*charPositionInLine*/,
                     const std::string &msg,
                     std::exception_ptr /*e*/) override
    {
        std::cerr << "lexer error: " << msg << std::endl;
        hadError = true;
    }
};

class ParserErrorListener : public antlr4::BaseErrorListener {
public:
    bool hadError = false;
    void syntaxError(antlr4::Recognizer * /*recognizer*/,
                     antlr4::Token* /*offendingSymbol*/,
                     size_t /*line*/, size_t /*charPositionInLine*/,
                     const std::string &msg,
                     std::exception_ptr /*e*/) override
    {
        std::cerr << "parse error: " << msg << std::endl;
        hadError = true;
    }
};

QDebug &operator <<(QDebug &d, const std::string &s)
{
    d << QString::fromStdString(s);
    return d;
}

QDebug &operator <<(QDebug &d, const antlr4::ParserRuleContext *ctx)
{
    d << ctx->start->getText();
    if (ctx->stop != ctx->start)
        d << ctx->stop->getText();
    return d;
}

QDebug &operator <<(QDebug &d, const std::vector<Ada95Parser::NameContext*> &name)
{
    d << name.size();
    for (auto *n : name) {
        d << n->start->getText();
    }
    return d;
}


class Ada95ModelBuilder : public Ada95ParserBaseListener
{
public:
    explicit Ada95ModelBuilder(NativeImportBase* importer)
        : m_importer(importer)
    {
    }
/*
    void enterAccess_type_definition(Ada95Parser::Access_type_definitionContext *ctx) override
    {
        if (m_currentTypeName.isEmpty())
            return;

        QString targetType;

        if (ctx->access_to_object_definition())
        {
            auto subtype = ctx->access_to_object_definition()->subtype_indication();
            if (subtype)
                targetType = QString::fromStdString(subtype->getText());
        }

        if (!targetType.isEmpty())
        {
            // Create association: User_Access → User_Data
            Import_Utils::createAssociation(
                m_currentTypeName,
                targetType,
                m_importer->currentScope()
            );
        }
    }
*/
    void enterCompilation_unit(Ada95Parser::Compilation_unitContext *ctx) override
    {
        qDebug() << __FUNCTION__
                 << ctx
                    ;
    }
#if 0
    void enterComponent_declaration(Ada95Parser::Component_declarationContext *ctx) override
    {
        if (!m_currentClass)
            return;

        auto names = ctx->defining_identifier_list();
        auto type = ctx->component_definition()->subtype_indication();

        QString typeName = type ? QString::fromStdString(type->getText()) : QLatin1String("unknown");

        for (auto id : names->defining_identifier())
        {
            QString attrName = QString::fromStdString(id->getText());

            UMLAttribute *attr = new UMLAttribute(
                attrName,
                UMLType(typeName)
            );

            m_currentClass->asUMLClassifier()->addAttribute(attr);
        }
    }
#endif

    void enterFull_type_declaration(Ada95Parser::Full_type_declarationContext *ctx) override
    {
        auto nameCtx = ctx->defining_identifier();
        if (!nameCtx)
            return;

        m_currentTypeName = QString::fromStdString(nameCtx->getText());

        // Create UML class
        m_currentClass = Import_Utils::createUMLObjectHierarchy(
            UMLObject::ot_Class,
            m_currentTypeName,
            m_importer->currentScope()->asUMLPackage()
        );
    }

    void exitFull_type_declaration(Ada95Parser::Full_type_declarationContext *) override
    {
        m_currentClass = nullptr;
        m_currentTypeName.clear();
    }

    void enterGeneric_instantiation(Ada95Parser::Generic_instantiationContext *ctx) override
    {
        QString instanceName = QString::fromStdString(
            ctx->defining_program_unit_name()->getText()
        );

        QString genericName = QString::fromStdString(
            ctx->name()->getText()
        );

        QStringList parameters;

        if (ctx->generic_actual_part())
        {
            for (auto assoc : ctx->generic_actual_part()->generic_association())
            {
                parameters << QString::fromStdString(
                    assoc->getText()
                );
            }
        }

        // Create UML representation
        UMLObject *cls = Import_Utils::createUMLObjectHierarchy(
            UMLObject::ot_Class,
            instanceName,
            m_importer->currentScope()->asUMLPackage()
        );

        cls->setStereotype(QLatin1String("instantiation"));

        // Dependency to template
        Import_Utils::createInstantiation(instanceName, genericName, m_importer->currentScope());

        // Optional: store template parameters
    }

#if 0
    virtual void enterIdentifier(Ada95Parser::IdentifierContext *ctx) override
    {
        qDebug() << __FUNCTION__
                 //<< ctx
                 << ctx->IDENTIFIER_()->getText()
                    ;
        if (ctx->IDENTIFIER_()->getText() == std::string("pr"))
            qDebug() << "found";
    }
#endif

    void enterPackage_specification(Ada95Parser::Package_specificationContext *ctx) override
    {
        addPackage(ctx->defining_program_unit_name()->getText());
    }

    void enterPackage_declaration(Ada95Parser::Package_declarationContext *ctx) override
    {
        qDebug() << __FUNCTION__
                 << ctx
                    ;
    }

    void enterPackage_body(Ada95Parser::Package_bodyContext *ctx) override
    {
        addPackage(ctx->defining_program_unit_name()->getText());
    }

    // void exitPackage_specification(...) override
    // {
    //     m_importer->popScope();
    // }

#if 0
    void enterRecord_type_definition(Ada95Parser::Record_type_definitionContext *ctx) override
    {
        if (!m_currentClass)
            return;

        QString name = QString::fromStdString(ctx->defining_program_unit_name()->getText()).replace(QLatin1Char(' '), QString());
        m_currentClass = Import_Utils::resolveType(name, currentScope());
        // Optional: mark as struct/class stereotype
        Import_Utils::applyStereotype(m_currentClass, QLatin1String("record"));
    }
#endif
    void enterUse_package_clause(Ada95Parser::Use_package_clauseContext * ctx) override
    {
        qDebug() << __FUNCTION__
                 << ctx
                 << ctx->name()
                    ;
    }

    void enterWith_clause(Ada95Parser::With_clauseContext *ctx) override
    {
        qDebug() << __FUNCTION__
                 << ctx
                 << ctx->name()
                    ;
    }

private:
    void addPackage(const std::string &rawName)
    {
        QString name = QString::fromStdString(rawName).replace(QLatin1Char(' '), QString());
        if (name.isEmpty())
            return;
        Import_Utils::createUMLObjectHierarchy(UMLObject::ot_Package, name, m_importer->currentScope()->asUMLPackage());
    }

    NativeImportBase* m_importer;
    UMLObject *m_currentClass{nullptr};
    QString m_currentTypeName;
};


// -------------------- Ada95Import --------------------

Ada95Import::Ada95Import(CodeImpThread* thread)
    : NativeImportBase(QStringLiteral("--"), thread)
{
}

Ada95Import::~Ada95Import() = default;

bool Ada95Import::parseFile(const QString &filename)
{
    QFile inputFile(filename);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        log(filename, QStringLiteral("Unable to open file for Ada95 import"));
        return false;
    }

    const QByteArray data = inputFile.readAll();
    ANTLRInputStream input(data.constData(), static_cast<size_t>(data.size()));
    Ada95Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    Ada95Parser parser(&tokens);
    parser.setBuildParseTree(true);

    Ada95Parser::CompilationContext *tree = nullptr;
    try {
        tree = parser.compilation();
    } catch (const std::exception &) {
        log(filename, QStringLiteral("Ada95 parser failed while parsing the file"));
        return false;
    }

    if (parser.getNumberOfSyntaxErrors() > 0 || !tree) {
        log(filename, QStringLiteral("Ada95 parser reported syntax errors"));
        return false;
    }

    Ada95ModelBuilder listener(this);
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return true;
}

#if 0
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

bool Ada95Import::_parseFile(const QString& fileName)
{
    qDebug() << "parsing" << fileName;

    std::ifstream stream;
    stream.open(fileName.toStdString());
    ANTLRInputStream input(stream);
    Ada95Lexer lexer(&input);

    // Attach custom lexer error listener
    LexerErrorListener lexErrorListener;
    lexer.removeErrorListeners();
    lexer.addErrorListener(&lexErrorListener);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (auto t : tokens.getTokens()) {
        std::cout << "TOKEN: " << t->toString() << std::endl;
    }

    if (lexErrorListener.hadError) {
       std::cerr << "Lexer failed on file: " << fileName.toStdString() << std::endl;
       return false;
    }

    Ada95Parser parser(&tokens);

    ParserErrorListener parserListener;
    parser.removeErrorListeners();
    parser.addErrorListener(&parserListener);

    tree::ParseTree* tree = parser.compilation();
    //std::cout << tree->toStringTree() << std::endl;

    if (parserListener.hadError)
    {
        std::cerr << "Parser error in file " << fileName.toStdString() << std::endl;
        return false;
    }

    antlr4::tree::ParseTreeWalker walker;
    UmbrelloParserListener extractor;
    walker.walk(&extractor, tree);

    // Ada95FullVisitor visitor;
    // visitor.visit(tree);

    return true;
}
#endif