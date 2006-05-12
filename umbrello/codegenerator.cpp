/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2004-2006                                               *
 *   Umbrello UML Modeller Authors <uml-devel@ uml.sf.net>                 *
 ***************************************************************************/

/*  This code generated by:
 *      Author : thomas
 *      Date   : Thu Jun 19 2003
 */

// own header
#include "codegenerator.h"

// system includes
#include <cstdlib> //to get the user name

// qt includes
#include <qdatetime.h>
#include <qregexp.h>
#include <qdir.h>
#include <qtextstream.h>

// kde includes
#include <kdebug.h>
#include <klocale.h>
#include <kmessagebox.h>
#include <kdialogbase.h>
#include <kapplication.h>

// app includes
#include "dialogs/overwritedialogue.h"
#include "dialogs/codeviewerdialog.h"
#include "codegenerators/simplecodegenerator.h"
#include "attribute.h"
#include "associationwidget.h"
#include "classifier.h"
#include "classifiercodedocument.h"
#include "codedocument.h"
#include "codegenerationpolicy.h"
#include "operation.h"
#include "uml.h"
#include "umldoc.h"
#include "umlobject.h"
#include "umlview.h"
#include "umlattributelist.h"
#include "umloperationlist.h"
#include "model_utils.h"

// Constructors/Destructors
//

CodeGenerator::CodeGenerator ()
        : QObject (UMLApp::app()->getDocument())
{
    initFields(UMLApp::app()->getDocument());
    CodeGenerationPolicy *commonPolicy = UMLApp::app()->getCommonPolicy();
    connect(commonPolicy,SIGNAL(modifiedCodeContent()),this,SLOT(syncCodeToDocument()));
}

// FIX
// hmm. this should be pure virtual so that implemented in sub-class
CodeGenerator::CodeGenerator (QDomElement & element )
        : QObject (UMLApp::app()->getDocument()) {
    initFields(UMLApp::app()->getDocument());
    loadFromXMI(element); // hmm. cant call this here.. its 'pure' virtual
}

CodeGenerator::~CodeGenerator ( ) {
    // destroy all owned codedocuments
    CodeDocument *doc;
    for (CodeDocumentListIt it(m_codedocumentVector);
                     (doc = it.current()) != NULL; ++it)
        delete doc;
    m_codedocumentVector.clear();
}

//
// Methods
//


// Accessor methods
//

QString CodeGenerator::getUniqueID(CodeDocument * codeDoc)
{

    QString id = codeDoc->getID();

    // does this document already exist? then just return its present id
    if (!id.isEmpty() && findCodeDocumentByID(id))
        return id;

    // approach now differs by whether or not its a classifier code document
    ClassifierCodeDocument * classDoc = dynamic_cast<ClassifierCodeDocument*>(codeDoc);
    if(classDoc) {
        UMLClassifier *c = classDoc->getParentClassifier();
        id = ID2STR(c->getID()); // this is supposed to be unique already..
    } else {

        QString prefix = "doc";
        QString id = prefix + "_0";
        int number = lastIDIndex;
        for ( ; findCodeDocumentByID(id); number++) {
            id = prefix + "_" + QString::number(number);
        }
        lastIDIndex = number;
    }

    return id;
}

CodeDocument * CodeGenerator::findCodeDocumentByID( const QString &tag ) {
    //if we already know to which file this class was written/should be written, just return it.
    CodeDocument * doc = (CodeDocument*)NULL;
    if((doc = m_codeDocumentDictionary.find(tag)))
        return doc;

    return doc;
}

bool CodeGenerator::addCodeDocument ( CodeDocument * doc )
{
    QString tag = doc->getID();

    // assign a tag if one doesnt already exist
    if(tag.isEmpty())
    {
        tag = getUniqueID(doc);
        doc->setID(tag);
    }

    if(m_codeDocumentDictionary.find(tag))
        return false; // return false, we already have some object with this tag in the list
    else
        m_codeDocumentDictionary.insert(tag, doc);

    m_codedocumentVector.append(doc);
    return true;
}

/**
 * Remove a CodeDocument object from m_codedocumentVector List
 */
bool CodeGenerator::removeCodeDocument ( CodeDocument * remove_object ) {
    QString tag = remove_object->getID();
    if(!(tag.isEmpty()))
        m_codeDocumentDictionary.remove(tag);
    else
        return false;

    m_codedocumentVector.remove(remove_object);
    return true;
}

/**
 * Get the list of CodeDocument objects held by m_codedocumentVector
 * @return QPtrList<CodeDocument *> list of CodeDocument objects held by
 * m_codedocumentVector
 */
CodeDocumentList * CodeGenerator::getCodeDocumentList ( ) {
    return &m_codedocumentVector;
}

// the vanilla version
CodeViewerDialog * CodeGenerator::getCodeViewerDialog ( QWidget* parent, CodeDocument *doc,
        Settings::CodeViewerState state)
{
    return new CodeViewerDialog(parent, doc, state);
}

// Other methods
//

void CodeGenerator::loadFromXMI (QDomElement & qElement ) {

    // dont do anything for simple (compatability) code generators
    if(dynamic_cast<SimpleCodeGenerator*>(this))
        return;

    //now look for our particular child element
    QDomNode node = qElement.firstChild();
    QDomElement element = node.toElement();
    QString langType = Model_Utils::progLangToString( getLanguage() );

    if (qElement.tagName() != "codegenerator"
            || qElement.attribute("language", "UNKNOWN") != langType)
        return;
    // got our code generator element, now load
    // codedocuments
    QDomNode codeDocNode = qElement.firstChild();
    QDomElement codeDocElement = codeDocNode.toElement();
    while( !codeDocElement.isNull() ) {

        QString docTag = codeDocElement.tagName();
        if( docTag == "codedocument" ||
                docTag == "classifiercodedocument"
          ) {
            QString id = codeDocElement.attribute( "id", "-1" );
            CodeDocument * codeDoc = findCodeDocumentByID(id);
            if(codeDoc)
                codeDoc->loadFromXMI(codeDocElement);
            else {
                kdWarning()<<" loadFromXMI: missing code document w/ id:"<<id<<", plowing ahead with pre-generated one."<<endl;
            }
        } else
            kdWarning()<<" loadFromXMI : got strange codegenerator child node:"<<docTag<<", ignoring."<<endl;

        codeDocNode = codeDocElement.nextSibling();
        codeDocElement = codeDocNode.toElement();
    }
}

void CodeGenerator::saveToXMI ( QDomDocument & doc, QDomElement & root ) {
    QString langType = Model_Utils::progLangToString( getLanguage() );
    QDomElement docElement = doc.createElement( "codegenerator" );
    docElement.setAttribute("language",langType);

    CodeDocumentList * docList = getCodeDocumentList();
    for (CodeDocument * codeDoc = docList->first(); codeDoc; codeDoc= docList->next())
        codeDoc->saveToXMI(doc, docElement);

    root.appendChild( docElement );
}

/**
 * Initialize this code generator from its parent UMLDoc. When this is called, it will
 * (re-)generate the list of code documents for this project (generator) by checking
 * for new objects/attributes which have been added or changed in the documnet. One or more
 * CodeDocuments will be created/overwritten/amended as is appropriate for the given language.
 *
 * In this 'generic' version a ClassifierCodeDocument will exist for each and
 * every classifier that exists in our UMLDoc. IF when this is called, a code document
 * doesnt exist for the given classifier, then we will created and add a new code
 * document to our generator.
 *
 * IF you want to add non-classifier related code documents at this step,
 * you will need to overload this method in the appropriate
 * code generatator (see JavaCodeGenerator for an example of this).
 */
void CodeGenerator::initFromParentDocument( ) {

    // Walk through the document converting classifiers into
    // classifier code documents as needed (e.g only if doesnt exist)
    UMLClassifierList concepts = UMLApp::app()->getDocument()->getClassesAndInterfaces();
    for (UMLClassifier *c = concepts.first(); c; c = concepts.next())
    {

        // Doesnt exist? Then build one.
        CodeDocument * codeDoc = findCodeDocumentByClassifier(c);
        if (!codeDoc)
        {
            // codeDoc = (CodeDocument*) newClassifierCodeDocument(c);
            codeDoc = newClassifierCodeDocument(c);
            addCodeDocument(codeDoc); // this will also add a unique tag to the code document
        }
    }

}

/**
 * Force a synchronize of this code generator, and its present contents, to that of the parent UMLDocument.
 * "UserGenerated" code will be preserved, but Autogenerated contents will be updated/replaced
 * or removed as is apppropriate.
 */
void CodeGenerator::syncCodeToDocument ( ) {
    for (CodeDocument * doc = m_codedocumentVector.first(); doc; doc=m_codedocumentVector.next())
        doc->synchronize();
}

// in this 'vanilla' version, we only worry about adding classifier
// documents
void CodeGenerator::checkAddUMLObject (UMLObject * obj) {
    if (!obj)
        return;

    UMLClassifier * c = dynamic_cast<UMLClassifier*>(obj);
    if(c) {
        CodeDocument * cDoc = newClassifierCodeDocument(c);
        addCodeDocument(cDoc);
    }
}

void CodeGenerator::checkRemoveUMLObject (UMLObject * obj)
{

    if (!obj)
        return;

    UMLClassifier * c = dynamic_cast<UMLClassifier*>(obj);
    if(c) {
        ClassifierCodeDocument * cDoc = (ClassifierCodeDocument*) findCodeDocumentByClassifier(c);
        if (cDoc)
            removeCodeDocument(cDoc);
    }

}

/**
 * @return      CodeDocument
 * @param       classifier
 */
CodeDocument * CodeGenerator::findCodeDocumentByClassifier ( UMLClassifier * classifier ) {
    return findCodeDocumentByID(ID2STR(classifier->getID()));
}


/**
 * Write out all code documents to file as appropriate.
 */
void CodeGenerator::writeCodeToFile ( )
{
    writeListedCodeDocsToFile(&m_codedocumentVector);
}

void CodeGenerator::writeCodeToFile ( UMLClassifierList & concepts) {
    CodeDocumentList docs;
    docs.setAutoDelete(false);

    for (UMLClassifier *concept= concepts.first(); concept; concept= concepts.next())
    {
        CodeDocument * doc = findCodeDocumentByClassifier(concept);
        if(doc)
            docs.append(doc);
    }

    writeListedCodeDocsToFile(&docs);
}

// Main method. Will write out passed code documents to file as appropriate.
void CodeGenerator::writeListedCodeDocsToFile ( CodeDocumentList * docs ) {

    // iterate thru all code documents
    for (CodeDocument *doc = docs->first(); doc; doc = docs->next())
    {

        // we need this so we know when to emit a 'codeGenerated' signal
        ClassifierCodeDocument * cdoc = dynamic_cast<ClassifierCodeDocument *>(doc);
        bool codeGenSuccess = false;

        // we only write the document, if so requested
        if(doc->getWriteOutCode())
        {
            QString filename = findFileName(doc);
            // check that we may open that file for writing
            QFile file;
            if ( openFile(file,filename) ) {
                QTextStream stream(&file);
                stream<<doc->toString()<<endl;
                file.close();
                codeGenSuccess = true; // we wrote the code OK
            } else {
                kdWarning() << "Cannot open file :"<<filename<<" for writing " << endl;
            }
        }

        if(cdoc)
            emit codeGenerated(cdoc->getParentClassifier(), codeGenSuccess);

    }

}

/**
 * Create a new Code document belonging to this package.
 * @return      CodeDocument
 */
CodeDocument * CodeGenerator::newCodeDocument ( ) {
    CodeDocument * newCodeDoc = new CodeDocument ();
    return newCodeDoc;
}

/**
 * @return      QString
 * @param       file
 */

QString CodeGenerator::getHeadingFile( const QString &file ) {
    return UMLApp::app()->getCommonPolicy()->getHeadingFile(file);
}

/**
 * @return      QString
 * @param       codeDoc
 * @param       name
 */
QString CodeGenerator::overwritableName( QString name, const QString &extension ) {

    CodeGenerationPolicy *pol = UMLApp::app()->getCommonPolicy();
    QDir outputDirectory = pol->getOutputDirectory();

    if (!outputDirectory.exists(name + extension)) {
        return name + extension;
    }

    int suffix;
    OverwriteDialogue overwriteDialogue( name, outputDirectory.absPath(),
                                         m_applyToAllRemaining, kapp -> mainWidget() );
    switch (pol->getOverwritePolicy()) {  //if it exists, check the OverwritePolicy we should use
    case CodeGenerationPolicy::Ok:              //ok to overwrite file
        name = name + extension;
        break;
    case CodeGenerationPolicy::Ask:            //ask if we can overwrite
        switch(overwriteDialogue.exec()) {
        case KDialogBase::Yes:  //overwrite file
            if ( overwriteDialogue.applyToAllRemaining() ) {
                pol->setOverwritePolicy(CodeGenerationPolicy::Ok);
                name = name + extension;
            } else {
                m_applyToAllRemaining = false;
            }
            break;
        case KDialogBase::No: //generate similar name
            suffix = 1;
            while( outputDirectory.exists(name + "__" + QString::number(suffix) + extension) ) {
                suffix++;
            }
            name = name + "__" + QString::number(suffix) + extension;
            if ( overwriteDialogue.applyToAllRemaining() ) {
                pol->setOverwritePolicy(CodeGenerationPolicy::Never);
            } else {
                m_applyToAllRemaining = false;
            }
            break;
        case KDialogBase::Cancel: //don't output anything
            if ( overwriteDialogue.applyToAllRemaining() ) {
                pol->setOverwritePolicy(CodeGenerationPolicy::Cancel);
            } else {
                m_applyToAllRemaining = false;
            }
            return NULL;
            break;
        }

        break;
    case CodeGenerationPolicy::Never: //generate similar name
        suffix = 1;
        while( outputDirectory.exists(name + "__" + QString::number(suffix) + extension) ) {
            suffix++;
        }
        name = name + "__" + QString::number(suffix) + extension;
        break;
    case CodeGenerationPolicy::Cancel: //don't output anything
        return NULL;
        break;
    }

    return name;

}


/**
 * @return      bool
 * @param       file
 * @param       name
 */
bool CodeGenerator::openFile (QFile & file, const QString &fileName ) {
    //open files for writing.
    if(fileName.isEmpty()) {
        kdWarning() << "cannot find a file name" << endl;
        return false;
    } else {
        QDir outputDirectory = UMLApp::app()->getCommonPolicy()->getOutputDirectory();
        file.setName(outputDirectory.absFilePath(fileName));
        if(!file.open(IO_WriteOnly)) {
            KMessageBox::sorry(0,i18n("Cannot open file %1 for writing. Please make sure the folder exists and you have permissions to write to it.").arg(file.name()),i18n("Cannot Open File"));
            return false;
        }
        return true;
    }

}


/**
 * @return      QString
 * @param       name
 */
QString CodeGenerator::cleanName ( const QString &name ) {
    QString retval = name;
    retval.replace(QRegExp("\\W"), "_");
    return retval;
}

QString CodeGenerator::findFileName ( CodeDocument * codeDocument ) {

    //else, determine the "natural" file name
    QString name;

    // Get the path name
    QString path = codeDocument->getPath();

    // if path is given add this as a directory to the file name
    if (!path.isEmpty()) {
        path.replace(QRegExp("::"), "/"); // Simple hack!
        name = path + "/" + codeDocument->getFileName();
        path = "/" + path;
    } else {
        name = codeDocument->getFileName();
    }

    // Convert all "::" to "/" : Platform-specific path separator
    name.replace(QRegExp("::"), "/"); // Simple hack!

    // if a path name exists check the existence of the path directory
    if (!path.isEmpty()) {
        QDir outputDirectory = UMLApp::app()->getCommonPolicy()->getOutputDirectory();
        QDir pathDir(outputDirectory.absPath() + path);

        // does our complete output directory exist yet? if not, try to create it
        if (!pathDir.exists())
        {
            // ugh. dir separator here is UNIX specific..
            QStringList dirs = QStringList::split("/",pathDir.absPath());
            QString currentDir = "";

            QStringList::iterator end(dirs.end());
            for (QStringList::iterator dir(dirs.begin()); dir != end; ++dir)
            {
                currentDir += "/" + *dir;
                if (! (pathDir.exists(currentDir)
                        || pathDir.mkdir(currentDir) ) )
                {
                    KMessageBox::error(0, i18n("Cannot create the folder:\n") +
                                       pathDir.absPath() + i18n("\nPlease check the access rights"),
                                       i18n("Cannot Create Folder"));
                    return NULL;

                }
            }
        }
    }

    name.simplifyWhiteSpace();
    name.replace(QRegExp(" "),"_");

    return overwritableName( name, codeDocument->getFileExtension() );
}

void CodeGenerator::findObjectsRelated(UMLClassifier *c, UMLClassifierList &cList) {
    UMLClassifier *temp;
    UMLDoc *umldoc = UMLApp::app()->getDocument();
    UMLView *view = umldoc->getCurrentView();

    if(!view)
        return;

    AssociationWidgetList associations;
    associations.setAutoDelete(false);
    view->getWidgetAssocs(c,associations);

    //associations
    for(AssociationWidget *a = associations.first(); a ; a = associations.next()) {
        temp = 0;
        switch(a->getAssocType()) {
        case Uml::at_Generalization:
        case Uml::at_Realization:
            // only the "b" end is seen by the "a" end, not other way around
            if(a->getWidgetID(Uml::B)!=c->getID())
                temp =(UMLClassifier*) umldoc->findObjectById(a->getWidgetID(Uml::B));
            break;
        case Uml::at_UniAssociation:
            // What the hell are these things? My assumption is that they are
            // a sloppy way to specify aggregations, adding an "arrow" for
            // "navagability", whatever that is.
            // These typically DONT have a rolename specified. Oh well, we
            // shall include it. The individual code generators will need to know
            // what to do with a "role-less" uni-associated classifier. -b.t.
            /* if(a->getWidgetID(Uml::A)!=c->getID()){
            //                                  temp = (UMLClassifier*)umldoc->findObjectById(a->getWidgetID(Uml::A));
                // Remove the link from child->base, since it breaks
                // C++ code generation.
            }
            else */
            if(a->getWidgetID(Uml::B)!=c->getID()){
                temp = (UMLClassifier*)umldoc->findObjectById(a->getWidgetID(Uml::B));
            }
            break;
        case Uml::at_Aggregation:
        case Uml::at_Composition:
        case Uml::at_Association_Self:
        case Uml::at_Association:
            // add related objects ONLY if the rolename is NOT empty
            if(a->getWidgetID(Uml::A)!=c->getID() && !a->getRoleName(Uml::A).isEmpty())
                temp = (UMLClassifier*)umldoc->findObjectById(a->getWidgetID(Uml::A));
            else if(a->getWidgetID(Uml::B)!=c->getID() && !a->getRoleName(Uml::B).isEmpty())
                temp =(UMLClassifier*) umldoc->findObjectById(a->getWidgetID(Uml::B));
            break;
        default: /* all others.. like for state diagrams..we currently dont use */
            break;
        }

        // now add in list ONLY if its not already there
        if(temp  && !cList.containsRef(temp))
            cList.append(temp);

    }

    //operations
    UMLOperationList opl(c->getOpList());
    for(UMLOperation *op = opl.first(); op ; op = opl.next()) {
        temp =0;
        //check return value
        temp =(UMLClassifier*) umldoc->findUMLClassifier(op->getTypeName());
        if(temp && !cList.containsRef(temp))
            cList.append(temp);
        //check parameters
        UMLAttributeList *atl = op->getParmList();
        for (UMLAttribute *at = atl->first(); at; at = atl->next()) {
            temp = (UMLClassifier*)umldoc->findUMLClassifier(at->getTypeName());
            if(temp && !cList.containsRef(temp))
                cList.append(temp);
        }

    }

    //attributes
    if (!c->isInterface()) {
        UMLAttributeList atl = c->getAttributeList();
        for (UMLAttribute *at = atl.first(); at; at = atl.next()) {
            temp=0;
            temp =(UMLClassifier*) umldoc->findUMLClassifier(at->getTypeName());
            if(temp && !cList.containsRef(temp))
                cList.append(temp);
        }
    }


}

/**
 * Format an output document.
 * @return      QString
 * @param       text
 * @param       lineprefix
 * @param       linewidth
 */
QString CodeGenerator::formatDoc(const QString &text, const QString &linePrefix, int lineWidth) {
    QString output;

    const QString endLine = UMLApp::app()->getCommonPolicy()->getNewLineEndingChars();
    QStringList lines = QStringList::split(endLine, text);
    for (QStringList::ConstIterator lit = lines.begin(); lit != lines.end(); ++lit) {
        QString input = *lit;
        input.remove( QRegExp("\\s+$") );
        if (input.length() < (uint)lineWidth) {
            output += linePrefix + input + endLine;
            continue;
        }
        int index;
        while ((index = input.findRev(" ", lineWidth)) >= 0) {
            output += linePrefix + input.left(index) + endLine; // add line
            input.remove(0, index + 1); //and remove processed string, including
            // white space
        }
        if (!input.isEmpty())
            output += linePrefix + input + endLine;
    }
    return output;
}

void CodeGenerator::initFields ( UMLDoc * doc ) {

    m_document = doc;
    m_codeDocumentDictionary.setAutoDelete(false);
    m_codedocumentVector.setAutoDelete(false);
    m_applyToAllRemaining = true;
    lastIDIndex = 0;

    // initial population of our project generator
    // CANT Be done here because we would call pure virtual method
    // of newClassifierDocument (bad!).
    // We should only call from the child
    // initFromParentDocument();

    connect(doc,SIGNAL(sigObjectCreated(UMLObject*)),this,SLOT(checkAddUMLObject(UMLObject*)));
    connect(doc,SIGNAL(sigObjectRemoved(UMLObject*)),this,SLOT(checkRemoveUMLObject(UMLObject*)));
    CodeGenerationPolicy *commonPolicy = UMLApp::app()->getCommonPolicy();
    connect(commonPolicy,SIGNAL(modifiedCodeContent()),this,SLOT(syncCodeToDocument()));

}

// these are utility methods for accessing the default
// code gen policy object and should go away when we
// finally implement the CodeGenDialog class -b.t.
void CodeGenerator::setForceDoc(bool f) {
    UMLApp::app()->getCommonPolicy()->setCodeVerboseDocumentComments(f);
}

bool CodeGenerator::forceDoc() const {
    return UMLApp::app()->getCommonPolicy()->getCodeVerboseDocumentComments();
}

void CodeGenerator::setForceSections(bool f) {
    UMLApp::app()->getCommonPolicy()->setCodeVerboseSectionComments(f);
}

bool CodeGenerator::forceSections() const {
    return UMLApp::app()->getCommonPolicy()->getCodeVerboseSectionComments();
}

QStringList CodeGenerator::defaultDatatypes()  {
    return QStringList();
    //empty by default, override in your code generator
}

bool CodeGenerator::isReservedKeyword(const QString & keyword) {

    const QStringList keywords = reservedKeywords();

    return keywords.contains(keyword);
}

const QStringList CodeGenerator::reservedKeywords() const {
    static QStringList emptyList;

    return emptyList;
}

void CodeGenerator::createDefaultStereotypes()  {
    //empty by default, override in your code generator
    //e.g.  m_document->createDefaultStereotypes("constructor");
}

#include "codegenerator.moc"
