/*
    SPDX-FileCopyrightText: 2025 Umbrello UML Modeller Authors <umbrello-devel@kde.org>
    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#include "testumlscene.h"

// app include
#include "umlattribute.h"
#include "umlclassifier.h"
#include "umldoc.h"
#include "umlfolder.h"
#include "umlscene.h"
#include "umlview.h"

#include <umldatatype.h>

//-----------------------------------------------------------------------------

void TestUMLScene::test_createAutoAssignments()
{
    UMLDoc *doc = UMLApp::app()->document();
    doc->newDocument();
    UMLPackage *package = doc->rootFolder(Uml::ModelType::Logical)->asUMLPackage();
    UMLScene *scene = doc->views().front()->umlScene();

    QSharedPointer<UMLClassifier> classA = QSharedPointer<UMLClassifier>(new UMLClassifier(QStringLiteral("classA")));
    classA->setUMLPackage(package);
    QSharedPointer<UMLClassifier> classB = QSharedPointer<UMLClassifier>(new UMLClassifier(QStringLiteral("classB")));
    classB->setUMLPackage(package);
    QSharedPointer<UMLAttribute> attr = QSharedPointer<UMLAttribute>(new UMLAttribute(classA.data(), QStringLiteral("attr")));
    attr->setType(classB.data());
    classA->addAttribute(attr.data());

    QCOMPARE(scene->associationList().size(), 0);

    qDebug() << "# add first widget";
    scene->setCreateObject(true);
    scene->slotObjectCreated(classA.data());
    QCOMPARE(scene->widgetList().size(), 1);
    QCOMPARE(scene->associationList().size(), 0);

    qDebug() << "# add second widget, should create association widget";
    scene->setCreateObject(true);
    scene->slotObjectCreated(classB.data());
    QCOMPARE(scene->associationList().size(), 1);
    // two class widgets, one floating text widget
    QCOMPARE(scene->widgetList().size(), 3);
}

void TestUMLScene::test_updateAutoAssignments()
{
    UMLDoc *doc = UMLApp::app()->document();
    doc->newDocument();
    UMLPackage *package = doc->rootFolder(Uml::ModelType::Logical)->asUMLPackage();
    UMLScene *scene = doc->views().front()->umlScene();

    QSharedPointer<UMLClassifier> classA = QSharedPointer<UMLClassifier>(new UMLClassifier(QStringLiteral("classA")));
    classA->setUMLPackage(package);
    QSharedPointer<UMLClassifier> classB = QSharedPointer<UMLClassifier>(new UMLClassifier(QStringLiteral("classB")));
    classB->setUMLPackage(package);
    QSharedPointer<UMLAttribute> attr = QSharedPointer<UMLAttribute>(new UMLAttribute(classA.data(), QStringLiteral("attr")));
    attr->setType(classB.data());
    classA->addAttribute(attr.data());

    qDebug() << "# add first widget";
    scene->setCreateObject(true);
    scene->slotObjectCreated(classA.data());

    qDebug() << "# add second widget, should create association widget";
    scene->setCreateObject(true);
    scene->slotObjectCreated(classB.data());

    QCOMPARE(scene->associationList().size(), 1);
    // two class widgets, one floating text widget
    QCOMPARE(scene->widgetList().size(), 3);

    qDebug() << "# remove classB from using as type, should remove association widget";
    UMLDatatype *type = doc->findDatatype(QStringLiteral("double"));
    attr->setType(type->asUMLObject());
    scene->autoUpdateAssociationWidgets(classA.data());

    //scene->updateContainment(classA.data());
    QCOMPARE(scene->associationList().size(), 0);
}

QTEST_MAIN(TestUMLScene)
