/*
    SPDX-FileCopyrightText: 2020 Ralf Habacker <ralf.habacker@freenet.de>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#include "testscene.h"

#include "object_factory.h"
#include "umlclassifier.h"
#include "umldatatype.h"
#include "umlfolder.h"
#include "widgetbase.h"
#include "umlscene.h"
#include "umlview.h"
#include "umlwidget.h"

#include <associationwidget.h>

void TestScene::test_autoAssociations()
{

    UMLFolder folder(QStringLiteral("folder"));
    UMLDoc *doc = new UMLDoc;
    doc->init();
    UMLDatatype *dataType = doc->findDatatype(QStringLiteral("double"));
    UMLView *view = doc->createDiagram(&folder, Uml::DiagramType::Class, QStringLiteral("class diagram"));
    doc->setCurrentRoot(Uml::ModelType::Logical);

    UMLPackage *root = new UMLPackage;
    UMLClassifier* classA = Object_Factory::createNewUMLObject(UMLObject::ot_Class, QStringLiteral("classA"), root)->asUMLClassifier();
    UMLAttribute* attr = Object_Factory::createChildObject(classA, UMLObject::ot_Attribute)->asUMLAttribute();
    UMLClassifier* classB = Object_Factory::createNewUMLObject(UMLObject::ot_Class, QStringLiteral("classB"), root)->asUMLClassifier();
    attr->setType(classB);

    AssociationWidgetList awl = view->umlScene()->associationList();
    QCOMPARE(awl.size(), 1);
    qDebug() << awl.front();
    attr->setType(dataType);
    QCOMPARE(view->umlScene()->associationList().size(), 0);
}

QTEST_MAIN(TestScene)
