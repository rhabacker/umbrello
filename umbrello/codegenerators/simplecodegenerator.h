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
 *      Date   : Sep Mon 1 2003
 *
 *  copyright (C) 2004
 *  Umbrello UML Modeller Authors <uml-devel@ uml.sf.net>
 */


#ifndef SIMPLECODEGENERATOR_H
#define SIMPLECODEGENERATOR_H

#include <qstring.h>
#include <qmap.h>

#include "../codegenerator.h"
#include "../umlnamespace.h"

class UMLDoc;
class UMLAttribute;
class CodeBlockWithComments;

/**
  * A simple code generator interface designed to work with
  * the existing codewriters.
  */
class SimpleCodeGenerator : public CodeGenerator
{
    Q_OBJECT
public:

    // Constructors/Destructors
    //

    /**
     * Empty Constructor
     */
    SimpleCodeGenerator (UMLDoc * doc, const char * name = 0,
                         bool createDirHierarchyForPackages = true);

    /**
     * Empty Destructor
     */
    virtual ~SimpleCodeGenerator ( );

    // Public attribute accessor methods
    //

    virtual bool isType (QString & type) = 0;
    virtual QString getLanguage() = 0;

    void writeCodeToFile ( UMLClassifierList & concepts);
    void writeCodeToFile ( );

    /**
             * call this method to generate code for a UMLClassifier
             * @param c the class you want to generate code for.
             */
    virtual void writeClass(UMLClassifier *c) = 0;

    /**
     * This is implemented only because we HAVE to.
     * @return  ClassifierCodeDocument
     * @param   classifier 
     * @param   this This package generator object.
     */
    CodeDocument * newClassifierCodeDocument (UMLClassifier * classifier);

protected:

    // compatability methods..
    QString findFileName(UMLClassifier* concept, QString ext);
    QString overwritableName(UMLClassifier* concept, QString name, const QString &ext);
    bool hasDefaultValueAttr(UMLClassifier *c);
    bool hasAbstractOps(UMLClassifier *c);

    /**
     * Returns the current indent string based on m_indentLevel and m_indentation.
     */
    QString getIndent ();

    /**
     * Maps UMLObjects to filenames. Used for finding out which file
     * each class was written to.
     */
    QMap<UMLClassifier*,QString> *m_fileMap;

    // the parent document
    UMLDoc *m_doc;

    /**
     * For some code generators, it does not make much sense to create a
     * directory for each package because that would lead to a rather
     * sparsely populated directory tree (maximum of just one source file
     * per directory.)
     */
    bool m_createDirHierarchyForPackages;

    /* Old Attributes writers will look for */
    QDir m_outputDirectory;
    CodeGenerationPolicy::OverwritePolicy m_overwrite;
    CodeGenerationPolicy::ModifyNamePolicy m_modname;
    QDir m_headingFiles;
    bool m_forceDoc;
    bool m_forceSections;
    bool m_includeHeadings;
    QString m_indentation;
    int m_indentLevel;
    QString m_endl;

    // override parent method..we need special handling
    void initFromParentDocument( );

private:

    void initFields ( UMLDoc * doc) ;

public slots:

    void syncCodeToDocument ( );

};

#endif // SIMPLECODEGENERATOR_H
