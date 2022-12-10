/*
    SPDX-License-Identifier: GPL-2.0-or-later

    SPDX-FileCopyrightText: 2003 Brian Thomas <thomas@mail630.gsfc.nasa.gov>
    SPDX-FileCopyrightText: 2004-2022 Umbrello UML Modeller Authors <umbrello-devel@kde.org>
*/

#include "cppheadercodeoperation.h"

#include "cppcodegenerator.h"
#include "cppcodegenerationpolicy.h"
#include "cppheadercodedocument.h"
#include "cppcodedocumentation.h"
#include "uml.h"

CPPHeaderCodeOperation::CPPHeaderCodeOperation
 (CPPHeaderCodeDocument * doc, UMLOperation *parent, const QString & body, const QString & comment)
        : CodeOperation (doc, parent, body, comment)
{
    // lets not go with the default comment and instead use
    // full-blown cpp documentation object instead
    setComment(new CPPCodeDocumentation(doc));

    // these things never change..
    setOverallIndentationLevel(1);

    setText(QString());
    setStartMethodText(QString());
    setEndMethodText(QString());
}

CPPHeaderCodeOperation::~CPPHeaderCodeOperation()
{
}

// we basically just want to know whether or not to print out
// the body of the operation.
// In C++ if the operations are inline, then we DO print out
// the body text.
void CPPHeaderCodeOperation::updateContent()
{
    CodeGenPolicyExt *pe = UMLApp::app()->policyExt();
    CPPCodeGenerationPolicy * policy = dynamic_cast<CPPCodeGenerationPolicy*>(pe);
    bool isInlineMethod = policy->getOperationsAreInline();

    if(isInlineMethod)
        setText(QString()); // change whatever it is to "";
}

// we basically want to update the doc and start text of this method
void CPPHeaderCodeOperation::updateMethodDeclaration()
{
    ClassifierCodeDocument *ccd = dynamic_cast<ClassifierCodeDocument*>(getParentDocument());
    Q_ASSERT(ccd);
    bool isInterface = ccd->parentIsInterface();
    UMLOperation * o = getParentOperation();

    CodeGenPolicyExt *pe = UMLApp::app()->policyExt();
    CPPCodeGenerationPolicy * policy = dynamic_cast<CPPCodeGenerationPolicy*>(pe);
    Q_ASSERT(policy);
    bool isInlineMethod = policy->getOperationsAreInline();
    QString tag = policy->getDocToolTag();

    QString endLine = getNewLineEndingChars();

    // first, the comment on the operation, IF its autogenerated/empty
    QString comment = o->doc();
    if(comment.isEmpty() && contentType() == CodeBlock::AutoGenerated)
    {
        UMLAttributeList parameters = o->getParmList();
        foreach (UMLAttribute* currentAtt, parameters) {
            comment += endLine + tag + QStringLiteral("param ") + currentAtt->name() + QLatin1Char(' ');
            comment += currentAtt->doc();
        }
        getComment()->setText(comment);
    }

    // no return type for constructors
    QString methodReturnType = o->getTypeName();
    QString methodName = o->name();
    QString paramStr;

    // assemble parameters
    UMLAttributeList list = getParentOperation()->getParmList();
    int nrofParam = list.count();
    int paramNum = 0;
    foreach (UMLAttribute* parm, list) {
        QString rType = parm->getTypeName();
        QString paramName = parm->name();
        QString initialValue = parm->getInitialValue();
        paramStr += rType + QLatin1Char(' ') + paramName;
        if(!initialValue.isEmpty())
            paramStr += QLatin1Char('=') + initialValue;

        paramNum++;

        if (paramNum != nrofParam)
            paramStr  += QStringLiteral(", ");
    }

    // if an operation isn't a constructor or a destructor and it has no return type
    if (o->isLifeOperation())         // constructor/destructor has no type
        methodReturnType = QString();
    else if (methodReturnType.isEmpty())  // this operation should be 'void'
        methodReturnType = QString(QStringLiteral("void"));

    // set start/end method text
    QString prototype = methodReturnType + QLatin1Char(' ') + methodName + QStringLiteral(" (") + paramStr + QLatin1Char(')');

    QString startText;
    QString endText;

    applyStereotypes (prototype, o, isInlineMethod, isInterface, startText, endText);

    setStartMethodText(prototype + startText);
    setEndMethodText(endText);
}

int CPPHeaderCodeOperation::lastEditableLine()
{
    ClassifierCodeDocument * doc = dynamic_cast<ClassifierCodeDocument*>(getParentDocument());
    UMLOperation * o = getParentOperation();
    if(doc->parentIsInterface() || o->isAbstract())
        return -1; // very last line is NOT editable as its a one-line declaration w/ no body in
    // an interface.
    return 0;
}

void CPPHeaderCodeOperation::applyStereotypes (QString& prototype, UMLOperation * pOp,
                                               bool inlinePolicy, bool interface,
                                               QString& start, QString& end)
{
    // if the class is an interface, all methods will be declared as pure
    // virtual functions
    start = (inlinePolicy ? QStringLiteral(" {") : QStringLiteral(";"));
    end = (inlinePolicy ? QStringLiteral("}") : QString());
    if (pOp->getConst())
        prototype += QStringLiteral(" const");
    if (pOp->getOverride())
        prototype += QStringLiteral(" override");
    if (interface || pOp->isAbstract()) {
       // constructor can't be virtual or abstract
       if (!pOp->isLifeOperation()) {
           prototype = QStringLiteral("virtual ") + prototype + QStringLiteral(" = 0");
           if (inlinePolicy) {
               start = QLatin1Char(';');
               end = QString();
           }
       }
    } // constructors could not be declared as static
    else if (pOp->isStatic() && !pOp->isLifeOperation()) {
       prototype = QStringLiteral("static ") + prototype;
    }
    // apply the stereotypes
    if (!pOp->stereotype().isEmpty()) {
        if ((pOp->stereotype() == QStringLiteral("friend")) || (pOp->stereotype(false) == QStringLiteral("virtual"))) {
            if (!pOp->isLifeOperation() && !(interface || pOp->isAbstract()) && !pOp->isStatic())
                prototype = pOp->stereotype() + QLatin1Char(' ') + prototype;
        }
    }
}

