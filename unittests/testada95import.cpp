#include "testada95import.h"

#include "codeimport/ada95/ada95import.h"

#include "umlobject.h"
#include "umlapp.h"
#include "umldoc.h"

#include <QtTest/QtTest>

// ------------------------------------------------------------------
// Tests
// ------------------------------------------------------------------

void TestAda95Import::initTestCase()
{
    if (!UMLApp::app()) {
        UMLApp *app = new UMLApp(); // singleton gets set inside constructor
        app->setup();
    }
}

void TestAda95Import::cleanupTestCase()
{
    delete UMLApp::app();  // tears down UMLApp and UMLDoc
}

#define EXAMPLES_DIR CMAKE_SOURCE_DIR "/3rdparty/grammars-v4/ada/ada95/examples/"

void TestAda95Import::test_import_file()
{
    QStringList fileList;
    fileList << QLatin1String(EXAMPLES_DIR "pkg1.ads");
    fileList << QLatin1String(EXAMPLES_DIR "pkg1.adb");
    Ada95Import classImporter;
    classImporter.setRootPath(QLatin1String(EXAMPLES_DIR));
    classImporter.importFiles(fileList);

    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    UMLObject *pkg = doc->findUMLObject(QLatin1String("MyPkg"), UMLObject::ot_Package, nullptr);
}


QTEST_MAIN(TestAda95Import)
#include "testada95import.moc"
