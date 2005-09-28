
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
 *      Date   : Tue Jun 24 2003
 */

#include <kdebug.h>
#include <qregexp.h>

#include "javaantcodedocument.h"
#include "javacodegenerator.h"

#include "xmlcodecomment.h"
#include "xmlelementcodeblock.h"


// Constructors/Destructors
//

JavaANTCodeDocument::JavaANTCodeDocument ( JavaCodeGenerator * gen )
        : CodeDocument ( (CodeGenerator *)gen )
{
    setFileName("build"); // default name
    setFileExtension(".xml");
    setID("ANTDOC"); // default id tag for this type of document
}

JavaANTCodeDocument::~JavaANTCodeDocument ( ) { }

//
// Methods
//

// Other methods
//

/**
 * create a new CodeBlockWithComments object belonging to this CodeDocument.
 * @return      CodeBlockWithComments
 */
/*
CodeBlockWithComments * JavaANTCodeDocument::newCodeBlockWithComments ( ) {
        return new XMLElementCodeBlock(this,"empty");
}
*/

/**
 * create a new CodeBlockWithComments object belonging to this CodeDocument.
 * @return      CodeBlockWithComments
 */
CodeComment * JavaANTCodeDocument::newCodeComment ( ) {
    return new XMLCodeComment(this);
}

HierarchicalCodeBlock * JavaANTCodeDocument::newHierarchicalCodeBlock ( ) {
    return new XMLElementCodeBlock(this,"empty");
}

// Sigh. NOT optimal. The only reason that we need to have this
// is so we can create the XMLNodes, if needed.
// would be better if we could create a handler interface that each
// codeblock used so all we have to do here is add the handler
void JavaANTCodeDocument::loadChildTextBlocksFromNode ( QDomElement & root)
{

    QDomNode tnode = root.firstChild();
    QDomElement telement = tnode.toElement();
    bool loadCheckForChildrenOK = false;
    while( !telement.isNull() ) {
        QString nodeName = telement.tagName();

        if( nodeName == "textblocks" ) {

            QDomNode node = telement.firstChild();
            QDomElement element = node.toElement();

            // if there is nothing to begin with, then we dont worry about it
            loadCheckForChildrenOK = element.isNull() ? true : false;

            while( !element.isNull() ) {
                QString name = element.tagName();

                if( name == "codecomment" ) {
                    CodeComment * block = newCodeComment();
                    block->loadFromXMI(element);
                    if(!addTextBlock(block))
                    {
                        kdError()<<"Unable to add codeComment to :"<<this<<endl;
                        block->deleteLater();
                    } else
                        loadCheckForChildrenOK= true;
                } else
                    if( name == "codeaccessormethod" ||
                            name == "ccfdeclarationcodeblock"
                      ) {
                        QString acctag = element.attribute("tag","");
                        // search for our method in the
                        TextBlock * tb = findCodeClassFieldTextBlockByTag(acctag);
                        if(!tb || !addTextBlock(tb))
                        {
                            kdError()<<"Unable to add codeclassfield child method to:"<<this<<endl;
                            // DONT delete
                        } else
                            loadCheckForChildrenOK= true;

                    } else
                        if( name == "codeblock" ) {
                            CodeBlock * block = newCodeBlock();
                            block->loadFromXMI(element);
                            if(!addTextBlock(block))
                            {
                                kdError()<<"Unable to add codeBlock to :"<<this<<endl;
                                block->deleteLater();
                            } else
                                loadCheckForChildrenOK= true;
                        } else
                            if( name == "codeblockwithcomments" ) {
                                CodeBlockWithComments * block = newCodeBlockWithComments();
                                block->loadFromXMI(element);
                                if(!addTextBlock(block))
                                {
                                    kdError()<<"Unable to add codeBlockwithcomments to:"<<this<<endl;
                                    block->deleteLater();
                                } else
                                    loadCheckForChildrenOK= true;
                            } else
                                if( name == "header" ) {
                                    // do nothing.. this is treated elsewhere
                                } else
                                    if( name == "hierarchicalcodeblock" ) {
                                        HierarchicalCodeBlock * block = newHierarchicalCodeBlock();
                                        block->loadFromXMI(element);
                                        if(!addTextBlock(block))
                                        {
                                            kdError()<<"Unable to add hierarchicalcodeBlock to:"<<this<<endl;
                                            block->deleteLater();
                                        } else
                                            loadCheckForChildrenOK= true;
                                    } else
                                        if( name == "codeoperation" ) {
                                            // find the code operation by id
                                            QString id = element.attribute("parent_id","-1");
                                            UMLObject * obj = getParentGenerator()->getDocument()->findObjectById(STR2ID(id));
                                            UMLOperation * op = dynamic_cast<UMLOperation*>(obj);
                                            if(op) {
                                                CodeOperation * block = newCodeOperation(op);
                                                block->loadFromXMI(element);
                                                if(addTextBlock(block))
                                                    loadCheckForChildrenOK= true;
                                                else
                                                {
                                                    kdError()<<"Unable to add codeoperation to:"<<this<<endl;
                                                    block->deleteLater();
                                                }
                                            } else
                                                kdError()<<"Unable to find operation create codeoperation for:"<<this<<endl;
                                        } else
                                            if( name == "xmlelementblock" ) {
                                                QString xmltag = element.attribute("nodeName","UNKNOWN");
                                                XMLElementCodeBlock * block = new XMLElementCodeBlock(this,xmltag);
                                                block->loadFromXMI(element);
                                                if(!addTextBlock(block))
                                                {
                                                    kdError()<<"Unable to add XMLelement to Java ANT document:"<<this<<endl;
                                                    block->deleteLater();
                                                } else
                                                    loadCheckForChildrenOK= true;
                                            }
                /*
                                                // only needed for extreme debuging conditions (E.g. making new codeclassdocument loader)
                                                else
                                                        kdDebug()<<" LoadFromXMI: Got strange tag in text block stack:"<<name<<", ignorning"<<endl;
                */

                node = element.nextSibling();
                element = node.toElement();
            }
            break;
        }

        tnode = telement.nextSibling();
        telement = tnode.toElement();
    }

    if(!loadCheckForChildrenOK)
    {
        CodeDocument * test = dynamic_cast<CodeDocument*>(this);
        if(test)
        {
            kdWarning()<<" loadChildBlocks : unable to initialize any child blocks in doc: "<<test->getFileName()<<" "<<this<<endl;
        } else {
            HierarchicalCodeBlock * hb = dynamic_cast<HierarchicalCodeBlock*>(this);
            if(hb)
                kdWarning()<<" loadChildBlocks : unable to initialize any child blocks in Hblock: "<<hb->getTag()<<" "<<this<<endl;
            else
                kdDebug()<<" loadChildBlocks : unable to initialize any child blocks in UNKNOWN OBJ:"<<this<<endl;
        }
    }

}

/** set the class attributes of this object from
 * the passed element node.
 */
void JavaANTCodeDocument::setAttributesFromNode ( QDomElement & root)
{

    // superclass save
    CodeDocument::setAttributesFromNode(root);

    // now set local attributes
    // setPackage(root.attribute("package",""));

}

/**
 * load params from the appropriate XMI element node.
 */
void JavaANTCodeDocument::loadFromXMI ( QDomElement & root ) {
    setAttributesFromNode(root);
}

/** set attributes of the node that represents this class
 * in the XMI document.
 */
void JavaANTCodeDocument::setAttributesOnNode ( QDomDocument & doc, QDomElement & docElement)
{

    // superclass call
    CodeDocument::setAttributesOnNode(doc,docElement);

    // now set local attributes/fields
    //FIX
}

/**
 * Save the XMI representation of this object
 */
void JavaANTCodeDocument::saveToXMI ( QDomDocument & doc, QDomElement & root ) {
    QDomElement docElement = doc.createElement( "codedocument" );

    setAttributesOnNode(doc, docElement);

    root.appendChild( docElement );
}

// we add in our code blocks that describe how to generate
// the project here...
void JavaANTCodeDocument::updateContent( ) {
    // FIX : fill in more content based on classes
    // which exist
    CodeBlockWithComments * xmlDecl = getCodeBlockWithComments("xmlDecl","",0);
    xmlDecl->setText("<?xml version=\"1.0\"?>");
    addTextBlock(xmlDecl);

    XMLElementCodeBlock * rootNode = new XMLElementCodeBlock(this, "project", "Java ANT build document");
    rootNode->setTag("projectDecl");
    addTextBlock(rootNode);

    // <project name="XDF" default="help" basedir=".">
    //HierarchicalCodeBlock * projDecl = xmlDecl->getHierarchicalCodeBlock("projectDecl", "Java ANT build document", 1);

    // set some global properties for the build
    /*
      <!-- set global properties for this build -->
      <!-- paths -->
      <property name="docApi.dir"  value="docs/api"/>
      <property name="path" value="gov/nasa/gsfc/adc/xdf"/>
      <property name="src" value="src/${path}/"/>
      <property name="top" value="."/>
      <property name="build" value="${top}/gov"/>
      <property name="buildDir" value="${path}"/>
      <!-- compiler directives -->
      <property name="build.compiler" value="modern"/>
      <property name="useDeprecation" value="no"/>
      <property name="jarname" value="${project}.jar"/>
    */

}

// We overwritten by Java language implementation to get lowercase path
QString JavaANTCodeDocument::getPath ( )
{

    QString path = getPackage();

    // Replace all white spaces with blanks
    path.simplifyWhiteSpace();

    // Replace all blanks with underscore
    path.replace(QRegExp(" "), "_");

    path.replace(QRegExp("\\."),"/");
    path.replace(QRegExp("::"), "/");

    path.lower();

    return path;

}


#include "javaantcodedocument.moc"
