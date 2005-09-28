
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
 *      Date   : Fri Jun 20 2003
 */

#include <kdebug.h>
#include "codeoperation.h"

#include "codedocument.h"
#include "codegenerator.h"
#include "classifiercodedocument.h"

#include "umldoc.h"
#include "umlobject.h"

// Constructors/Destructors
//

CodeOperation::CodeOperation ( ClassifierCodeDocument * doc , UMLOperation * parentOp, const QString & body, const QString & comment)
        : CodeMethodBlock ( doc, parentOp, body, comment)
{
    init(parentOp);
}

CodeOperation::~CodeOperation ( ) { }

//
// Methods
//

// Accessor methods
//

/**
 * Add a Parameter object to the m_parameterVector List
 */
/*
void CodeOperation::addParameter ( CodeParameter * add_object ) {
	m_parameterVector.append(add_object);
}
*/

/**
 * Remove a Parameter object from m_parameterVector List
 */
/*
void CodeOperation::removeParameter ( CodeParameter * remove_object ) {
	m_parameterVector.remove(remove_object);
}
*/

/**
 * Get the list of Parameter objects held by m_parameterVector
 * @return QPtrList<CodeParameter *> list of Parameter objects held by
 * m_parameterVector
 */
/*
QPtrList<CodeParameter> CodeOperation::getParameterList ( ) {
	return m_parameterVector;
}
*/

/**
 * Get the parent UMLOperation of this codeoperation.
 */
UMLOperation * CodeOperation::getParentOperation( ) {
    return (UMLOperation*) getParentObject();
}

// Other methods
//

/** Save the XMI representation of this object
 */
void CodeOperation::saveToXMI ( QDomDocument & doc, QDomElement & root ) {
    QDomElement blockElement = doc.createElement( "codeoperation" );

    // set attributes
    setAttributesOnNode(doc, blockElement);

    root.appendChild( blockElement );
}

/**
 * load params from the appropriate XMI element node.
 */
void CodeOperation::loadFromXMI ( QDomElement & root )
{
    setAttributesFromNode(root);
}

QString CodeOperation::findTag (UMLOperation * op) {
    return QString("operation_" + ID2STR(op->getID()));
}

/** set attributes of the node that represents this class
 * in the XMI document.
 */
void CodeOperation::setAttributesOnNode ( QDomDocument & doc, QDomElement & elem)
{

    CodeMethodBlock::setAttributesOnNode(doc,elem); // superclass

}

/** set the class attributes of this object from
 * the passed element node.
 */
void CodeOperation::setAttributesFromNode ( QDomElement & element)
{

    CodeMethodBlock::setAttributesFromNode(element); // superclass

    // now set local attributes

    // oops..this is done in the parent class "ownedcodeblock".
    // we simply need to record the parent operation here
    // m_parentOperation->disconnect(this); // always disconnect from current parent

    QString idStr = element.attribute("parent_id","-1");
    Uml::IDType id = STR2ID(idStr);
    UMLObject * obj = getParentDocument()->getParentGenerator()->getDocument()->findObjectById(id);
    UMLOperation * op = dynamic_cast<UMLOperation*>(obj);

    if(op)
        init(op);
    else
        kdError()<<"ERROR: could'nt load code operation because of missing UMLoperation, corrupt savefile?"<<endl;

}

void CodeOperation::setAttributesFromObject(TextBlock * obj)
{

    CodeMethodBlock::setAttributesFromObject(obj);

    CodeOperation * op = dynamic_cast<CodeOperation*>(obj);
    if(op)
        init((UMLOperation*) op->getParentObject());

}

void CodeOperation::init (UMLOperation * parentOp)
{

    m_canDelete = false; // we cant delete these with the codeeditor, delete the UML operation instead.
    setTag(CodeOperation::findTag(parentOp));

    // not needed.. done by parent "ownedcodeblock" class
    //  connect(parentOp,SIGNAL(modified()),this,SLOT(syncToParent()));

}

void CodeOperation::updateContent() {
    // Empty. Unlike codeaccessor methods for most (all?) languages
    // we dont auto-generate content for operations
}


#include "codeoperation.moc"
