
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/*  This code generated by:
 *      Author : thomas
 *      Date   : Mon Sep 1 2003
 */

#include "cppheadercodeoperation.h"

#include "cppcodegenerator.h"
#include "cppheadercodedocument.h"
#include "cppcodedocumentation.h"

// Constructors/Destructors
//

CPPHeaderCodeOperation::CPPHeaderCodeOperation ( CPPHeaderCodeDocument * doc, UMLOperation *parent, const QString & body, const QString & comment )
        : CodeOperation ((ClassifierCodeDocument*)doc, parent, body, comment)
{
    init(doc);
}

CPPHeaderCodeOperation::~CPPHeaderCodeOperation ( ) { }

// Other methods
//

// we basically just want to know whether or not to print out
// the body of the operation.
// In C++ if the operations are inline, then we DO print out
// the body text.
void CPPHeaderCodeOperation::updateContent( )
{
    CPPCodeGenerationPolicy * policy = (CPPCodeGenerationPolicy*) getParentDocument()->getParentGenerator()->getPolicy();
    bool isInlineMethod = policy->getOperationsAreInline( );

    if(isInlineMethod)
        setText(""); // change whatever it is to "";

}

// we basically want to update the doc and start text of this method
void CPPHeaderCodeOperation::updateMethodDeclaration()
{

    bool isInterface = ((ClassifierCodeDocument*)getParentDocument())->parentIsInterface();
    UMLOperation * o = getParentOperation();

    CPPCodeGenerationPolicy * policy = (CPPCodeGenerationPolicy*) getParentDocument()->getParentGenerator()->getPolicy();
    bool isInlineMethod = policy->getOperationsAreInline( );

    QString endLine = getNewLineEndingChars();

    // first, the comment on the operation, IF its autogenerated/empty
    QString comment = o->getDoc();
    if(comment.isEmpty() && getContentType() == CodeBlock::AutoGenerated)
    {
        UMLAttributeList* paramaters = o->getParmList();
        for(UMLAttributeListIt iterator(*paramaters); iterator.current(); ++iterator) {
            comment += endLine + "@param " + iterator.current()->getName() + " ";
            comment += iterator.current()->getDoc();
        }
        getComment()->setText(comment);
    }

    // no return type for constructors
    QString methodReturnType = o->getTypeName();
    QString methodName = o->getName();
    QString paramStr = QString("");

    // assemble parameters
    UMLAttributeList * list = getParentOperation()->getParmList();
    int nrofParam = list->count();
    int paramNum = 0;
    for(UMLAttribute* parm = list->first(); parm; parm=list->next())
    {
        QString rType = parm->getTypeName();
        QString paramName = parm->getName();
        QString initialValue = parm->getInitialValue();
        paramStr += rType + " " + paramName;
        if(!initialValue.isEmpty())
            paramStr += "=" + initialValue;

        paramNum++;

        if (paramNum != nrofParam )
            paramStr  += ", ";
    }

    // if an operation isn't a constructor or a destructor and it has no return type
    if (o->isLifeOperation())         // constructor/destructor has no type
        methodReturnType = "";
    else if (methodReturnType.isEmpty())  // this operation should be 'void'
        methodReturnType = QString("void");

    // set start/end method text
    QString prototype = methodReturnType+" "+methodName+" ("+paramStr+")";

    QString startText;
    QString endText;

    applyStereotypes (prototype, o, isInlineMethod, isInterface, startText, endText);

    setStartMethodText(prototype+startText);
    setEndMethodText(endText);
}

int CPPHeaderCodeOperation::lastEditableLine() {
    ClassifierCodeDocument * doc = (ClassifierCodeDocument*)getParentDocument();
    UMLOperation * o = getParentOperation();
    if(doc->parentIsInterface() || o->getAbstract())
        return -1; // very last line is NOT editable as its a one-line declaration w/ no body in
    // an interface.
    return 0;
}

void CPPHeaderCodeOperation::init (CPPHeaderCodeDocument * doc )
{

    // lets not go with the default comment and instead use
    // full-blown cpp documentation object instead
    setComment(new CPPCodeDocumentation(doc));

    // these things never change..
    setOverallIndentationLevel(1);

    setText("");
    setStartMethodText("");
    setEndMethodText("");

    updateMethodDeclaration();
    updateContent();

}

void CPPHeaderCodeOperation::applyStereotypes (QString& prototype, UMLOperation * pOp,
                                               bool inlinePolicy, bool interface,
                                               QString& start, QString& end)
{
    // if the class is an interface, all methods will be declared as pure
    // virtual functions
    start = (inlinePolicy ? " {" : ";");
    end = (inlinePolicy ? "}" : "");
    if (interface || pOp->getAbstract()) {
       // constructor can't be virtual or abstract
       if (!pOp->isLifeOperation()) {
           prototype = "virtual " + prototype + " = 0";
           if (inlinePolicy) {
               start = ";";
               end = "";
           }
       }
    } // constructors could not be declared as static
    else if (pOp->getStatic() && !pOp->isLifeOperation()) {
       prototype = "static " + prototype;
    }
    // apply the stereotypes
    if (!pOp->getStereotype().isEmpty()) {
        if ((pOp->getStereotype() == "friend") || (pOp->getStereotype(false) == "virtual")) {
            if (!pOp->isLifeOperation() && !(interface || pOp->getAbstract()) && !pOp->getStatic())
                prototype = pOp->getStereotype() + " " + prototype; 
        }
    }
}

#include "cppheadercodeoperation.moc"
