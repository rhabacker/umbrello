
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
 *      Date   : Tue Aug 19 2003
 */
#include <kdebug.h>
#include "ownedcodeblock.h"

#include "association.h"
#include "classifier.h"
#include "umldoc.h"
#include "umlobject.h"
#include "umlrole.h"

#include "codedocument.h"
#include "codegenerator.h"

// Constructors/Destructors
//

OwnedCodeBlock::OwnedCodeBlock ( UMLObject * parent )
	: QObject ( (QObject*)parent, "anOwnedCodeBlock" )
{
	initFields(parent);
}

OwnedCodeBlock::~OwnedCodeBlock ( ) { 
/*
	if(m_parentObject)
		m_parentObject->disconnect(this);
*/
}

//
// Methods
//

void OwnedCodeBlock::release () {
	if(m_parentObject)
	m_parentObject->disconnect(this);
	m_parentObject = 0;
}

/**
 * Get the value of m_parentObject
 * @return the value of m_parentObject
 */
UMLObject * OwnedCodeBlock::getParentObject () {
        return m_parentObject;
}

// Other methods
//

void OwnedCodeBlock::setAttributesFromObject (TextBlock * obj) {

        OwnedCodeBlock * oc = dynamic_cast<OwnedCodeBlock*>(obj);
        if(oc)
        {
                m_parentObject->disconnect(this);
                initFields(oc->getParentObject());
        }
}

/** set attributes of the node that represents this class
  * in the XMI document.
  */
void OwnedCodeBlock::setAttributesOnNode(QDomDocument& /*doc*/, QDomElement& elem) {

        // set local class attributes
	// setting ID's takes special treatment
        // as UMLRoles arent properly stored in the XMI right now.
        // (change would break the XMI format..save for big version change )
        UMLRole * role = dynamic_cast<UMLRole*>(m_parentObject);
        if(role)
	{
        	elem.setAttribute("parent_id",QString::number(role->getParentAssociation()->getID()));
                elem.setAttribute("role_id",role->getRoleID());
	}
        else
	{
        	elem.setAttribute("parent_id",QString::number(m_parentObject->getID()));
                elem.setAttribute("role_id","-1");
	}

}

 /** set the class attributes of this object from
  * the passed element node.
  */
void OwnedCodeBlock::setAttributesFromNode ( QDomElement & elem) {

        // set local attributes, parent object first
        int id = elem.attribute("parent_id","-1").toInt();

	// always disconnect from current parent
        getParentObject()->disconnect(this);

       // now, what is the new object we want to set?
        UMLObject * obj = getParentDocument()->getParentGenerator()->getDocument()->findUMLObject(id);
        if(obj)
	{

	        // FIX..one day.
	        // Ugh. This is UGLY, but we have to do it this way because UMLRoles
	        // dont go into the document list of UMLobjects, and have the same
	        // ID as their parent UMLAssociations. So..the drill is then special
	        // for Associations..in that case we need to find out which role will
	        // serve as the parametger here. The REAL fix, of course, would be to
	        // treat UMLRoles on a more even footing, but im not sure how that change
	        // might ripple throughout the code and cause problems. Thus, since the
	        // change appears to be needed for only this part, I'll do this crappy
	        // change instead. -b.t.
	        UMLAssociation * assoc = dynamic_cast<UMLAssociation*>(obj);
	        if(assoc) {
	                // In this case we init with indicated role child obj.
	                UMLRole * role = 0;
	                int role_id = elem.attribute("role_id","-1").toInt();
			// compatibility w/ older save files, make go away soon
			if(role_id > 1) 
			{
	                	if(assoc->getUMLRoleA()->getID() == role_id)
	                        	role = assoc->getUMLRoleA();
	                	else if(assoc->getUMLRoleB()->getID() == role_id)
	                        	role = assoc->getUMLRoleB();
	                	else // this will cause a crash
	                        	kdError()<<"ERROR! corrupt save file? cant get proper UMLRole for codeparameter:"<<id<<" w/role_id:"<<role_id<<endl;
			} else {

	                	if(role_id == 0) 
	                        	role = assoc->getUMLRoleA();
	                	else if(role_id == 1) 
	                        	role = assoc->getUMLRoleB();
	                	else // this will cause a crash
	                        	kdError()<<"ERROR! corrupt save file? cant get proper UMLRole for codeparameter:"<<id<<" w/role_id:"<<role_id<<endl;
			}

	                // init using UMLRole obj
			initFields ( role ); 
	        } else
			initFields ( obj); // just the regular approach

	}
	else
		kdError()<<"ERROR: can't load ownedcodeblock: parentUMLObject w/id:"<<id<<" not found, corrupt save file?"<<endl;

}

void OwnedCodeBlock::initFields(UMLObject * parent ) 
{

	m_parentObject = parent;

	// one reason for being: set up the connection between
        // this code block and the parent UMLObject..when the parent
        // signals a change has been made, we automatically update
        // ourselves
        connect(m_parentObject, SIGNAL(modified()), this, SLOT(syncToParent()));
}

/**
 */
void OwnedCodeBlock::syncToParent ( ) {
	updateContent();
}

#include "ownedcodeblock.moc"
