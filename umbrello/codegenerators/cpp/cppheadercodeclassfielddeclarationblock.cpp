/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2003      Brian Thomas <thomas@mail630.gsfc.nasa.gov>   *
 *   copyright (C) 2004-2014                                               *
 *   Umbrello UML Modeller Authors <umbrello-devel@kde.org>                *
 ***************************************************************************/

#include "cppheadercodeclassfielddeclarationblock.h"

#include "cppcodeclassfield.h"
#include "cppheadercodedocument.h"
#include "debug_utils.h"

CPPHeaderCodeClassFieldDeclarationBlock::CPPHeaderCodeClassFieldDeclarationBlock (CodeClassField * parent)
        : CodeClassFieldDeclarationBlock (parent)
{
    setOverallIndentationLevel(1);
}

CPPHeaderCodeClassFieldDeclarationBlock::~CPPHeaderCodeClassFieldDeclarationBlock ()
{
}

void CPPHeaderCodeClassFieldDeclarationBlock::updateContent()
{
    UMLObject *umlparent = CodeClassFieldDeclarationBlock::getParentObject();
    if (umlparent == 0) {
        return;
    }

    CodeClassField * cf = getParentClassField();
    CPPCodeClassField * hcppcf = dynamic_cast<CPPCodeClassField*>(cf);

    // Check for dynamic casting failure!
    if (hcppcf == 0)
    {
        uError() << "hcppcf: invalid dynamic cast";
        return;
    }

    // Set the comment
    QString notes = umlparent->doc();
    getComment()->setText(notes);
    if (notes.isEmpty())
        getComment()->setWriteOutText(false);
    else
        getComment()->setWriteOutText(true);

    // Set the body
    QString staticValue = umlparent->isStatic() ? QLatin1String("static ") : QString();
    QString typeName = hcppcf->getTypeName();
    QString fieldName = hcppcf->getFieldName();

    // Ugh. Sloppy exception.
    if (!cf->parentIsAttribute() && !cf->fieldIsSingleValue())
        typeName = hcppcf->getListFieldClassName();

    QString body = staticValue + QLatin1Char(' ') + typeName + QLatin1Char(' ') + fieldName + QLatin1Char(';');
    setText(body);
}

