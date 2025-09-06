#include "testadaimport.h"

#include "codeimport/adaimport.h"
#include "import_utils.h"

#include "umlobject.h"
#include "umldoc.h"

#include "umlmodel/umlenum.h"
#include "umlmodel/umlclassifier.h"
#include "umlmodel/umloperation.h"
#include "umlmodel/umlattribute.h"

#include <QtTest/QtTest>

#include <umlapp.h>

class TestableAdaImport : public AdaImport {
public:
    explicit TestableAdaImport(void* doc) {}

    bool parse(const QStringList &tokens) {
        m_source = tokens;
        m_srcIndex = 0;
        return parseStmt();
    }

    void setCurrentClass(UMLClassifier *klass) { m_klass = klass; }
    UMLClassifier* getCurrentClass() const { return m_klass; }
    const QStringList& getSource() const { return m_source; }
    int getSourceIndex() const { return m_srcIndex; }

    void addClassDefinedInThisScope(UMLClassifier* klass) {
        if (!m_classesDefinedInThisScope.contains(klass)) {
            m_classesDefinedInThisScope.append(klass); // use append instead of insert
        }
    }

    UMLPackage* getCurrentScope() const { return m_scope.isEmpty() ? nullptr : m_scope.last(); }
};

// ------------------------------------------------------------------
// Tests
// ------------------------------------------------------------------

void TestAdaImport::initTestCase()
{
    if (!UMLApp::app()) {
        UMLApp *app = new UMLApp(); // singleton gets set inside constructor
        app->setup();
    }
}

void TestAdaImport::cleanupTestCase()
{
    delete UMLApp::app();  // tears down UMLApp and UMLDoc
}

void TestAdaImport::test_import_file()
{
    QStringList fileList;
    fileList <<  QLatin1Literal(CMAKE_CURRENT_SOURCE_DIR "/test.ada");
    ClassImport *classImporter = ClassImport::createImporterByFileExt(fileList.front());
    classImporter->setRootPath(QLatin1Literal(CMAKE_CURRENT_SOURCE_DIR));
    classImporter->importFiles(fileList);
    delete classImporter;

    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    UMLObject *pkg = doc->findUMLObject("MyPkg", UMLObject::ot_Package, nullptr);

}

void TestAdaImport::test_parse_with_clause()
{
    UMLDoc doc;
    TestableAdaImport importer(&doc);

    QVERIFY(importer.parse(QStringList() << "with" << "Ada.Text_IO" << ";"));
    QCOMPARE(importer.getSourceIndex(), 2);
}

void TestAdaImport::test_parse_package_declaration()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    QVERIFY(importer.parse(QStringList() << "package" << "MyPkg" << "is" << ";"));

    UMLObject *pkg = doc->findUMLObject("MyPkg", UMLObject::ot_Package, nullptr);
    QVERIFY(pkg != nullptr);
    QCOMPARE(pkg->name(), QString("MyPkg"));
}

void TestAdaImport::test_parse_subtype()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    QVERIFY(importer.parse(QStringList() << "subtype" << "Index" << "is" << "Integer" << ";"));

    UMLObject *subtype = doc->findUMLObject("Index", UMLObject::ot_UMLObject, nullptr);
    QVERIFY(subtype != nullptr);
}

void TestAdaImport::test_parse_enum_type()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    QStringList tokens = QStringList() << "type" << "Color" << "is"
                                       << "(" << "Red" << "," << "Green" << "," << "Blue" << ")" << ";";
    QVERIFY(importer.parse(tokens));

    UMLObject *enumObj = doc->findUMLObject("Color", UMLObject::ot_Enum, nullptr);
    QVERIFY(enumObj != nullptr);

    UMLEnum *enumType = enumObj->asUMLEnum();
    QVERIFY(enumType != nullptr);
    QCOMPARE(enumType->enumLiterals().size(), 3);
    QCOMPARE(enumType->enumLiterals()[0]->name(), QString("Red"));
    QCOMPARE(enumType->enumLiterals()[1]->name(), QString("Green"));
    QCOMPARE(enumType->enumLiterals()[2]->name(), QString("Blue"));
}

void TestAdaImport::test_parse_function_with_parameters()
{
    UMLDoc *doc = UMLApp::app()->document();
    QVERIFY(doc != nullptr);

    TestableAdaImport importer(doc);

    // Create the class where the function will be added
    UMLClassifier *klass = Import_Utils::createUMLObject(
                               UMLObject::ot_Class, "C", importer.getCurrentScope())
                               ->asUMLClassifier();
    QVERIFY(klass != nullptr);
    importer.setCurrentClass(klass);
    importer.addClassDefinedInThisScope(klass);

    // Create a dummy parameter type class to avoid collision with built-in datatypes
    UMLClassifier *intClass = Import_Utils::createUMLObject(
                                  UMLObject::ot_Class, "MyInt", importer.getCurrentScope())
                                  ->asUMLClassifier();
    QVERIFY(intClass != nullptr);
    importer.addClassDefinedInThisScope(intClass);

    // Tokens representing a function with one parameter of type MyInt
    QStringList tokens = QStringList()
                         << "function" << "Foo" << "("
                         << "x" << ":" << "MyInt" << ")"
                         << "return" << "Boolean" << ";";
    QVERIFY(importer.parse(tokens));

    // Verify that the operation was created
    QList<UMLOperation *> ops = klass->getOperationsList();
    QVERIFY(!ops.isEmpty());

    UMLOperation *op = ops[0];
    QVERIFY(op != nullptr);
    QCOMPARE(op->name(), QString("Foo"));

    // Verify the parameter
    QCOMPARE(op->getParameterList().size(), 1);
    QCOMPARE(op->getParameterList()[0]->name(), QString("x"));
    QCOMPARE(op->getParameterList()[0]->getType()->name(), QString("MyInt"));
}

void TestAdaImport::test_parse_function_multiple_parameters()
{
    UMLDoc *doc = UMLApp::app()->document();
    QVERIFY(doc != nullptr);

    TestableAdaImport importer(doc);

    // Create the class where the function will be added
    UMLClassifier *klass = Import_Utils::createUMLObject(
                               UMLObject::ot_Class, "C", importer.getCurrentScope())
                               ->asUMLClassifier();
    QVERIFY(klass != nullptr);
    importer.setCurrentClass(klass);
    importer.addClassDefinedInThisScope(klass);

    // Create dummy parameter type classes
    UMLClassifier *intClassX = Import_Utils::createUMLObject(
                                   UMLObject::ot_Class, "MyIntX", importer.getCurrentScope())
                                   ->asUMLClassifier();
    UMLClassifier *intClassY = Import_Utils::createUMLObject(
                                   UMLObject::ot_Class, "MyIntY", importer.getCurrentScope())
                                   ->asUMLClassifier();
    importer.addClassDefinedInThisScope(intClassX);
    importer.addClassDefinedInThisScope(intClassY);

    // Tokens representing a function with two parameters
    QStringList tokens = QStringList()
                         << "function" << "Add" << "("
                         << "x" << ":" << "MyIntX" << ","
                         << "y" << ":" << "MyIntY" << ")"
                         << "return" << "Integer" << ";";
    QVERIFY(importer.parse(tokens));

    // Verify that the operation was created
    QList<UMLOperation *> ops = klass->getOperationsList();
    QVERIFY(!ops.isEmpty());

    UMLOperation *op = ops[0];
    QVERIFY(op != nullptr);
    QCOMPARE(op->name(), QString("Add"));

    // Verify the parameters
    QCOMPARE(op->getParameterList().size(), 2);
    QCOMPARE(op->getParameterList()[0]->name(), QString("x"));
    QCOMPARE(op->getParameterList()[0]->getType()->name(), QString("MyIntX"));
    QCOMPARE(op->getParameterList()[1]->name(), QString("y"));
    QCOMPARE(op->getParameterList()[1]->getType()->name(), QString("MyIntY"));
}

void TestAdaImport::test_parse_attribute_declaration()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    UMLClassifier *klass = Import_Utils::createUMLObject(
                               UMLObject::ot_Class, "C", nullptr)->asUMLClassifier();
    importer.setCurrentClass(klass);

    QStringList tokens = QStringList() << "myAttr" << ":" << "Integer" << ":=" << "42" << ";";
    QVERIFY(importer.parse(tokens));

    UMLAttribute *attr = klass->getAttributeList()[0];
    QVERIFY(attr != nullptr);
    QCOMPARE(attr->name(), QString("myAttr"));
    QCOMPARE(attr->baseTypeStr(), QString("Integer"));
    QCOMPARE(attr->getInitialValue(), QString("42"));
}

void TestAdaImport::test_parse_generic_package()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    QStringList tokens = QStringList() << "generic" << "package" << "MyGeneric" << "is" << ";";
    QVERIFY(importer.parse(tokens));

    UMLObject *pkg = doc->findUMLObject("MyGeneric", UMLObject::ot_Package, nullptr);
    QVERIFY(pkg != nullptr);
    QCOMPARE(pkg->name(), QString("MyGeneric"));
}

void TestAdaImport::test_parse_with_clause_skipped()
{
    UMLDoc *doc = UMLApp::app()->document();  // Use the singleton document
    QVERIFY(doc != nullptr);
    TestableAdaImport importer(doc);

    QStringList tokens = QStringList() << "with" << "System" << ";";
    QVERIFY(importer.parse(tokens));

    QCOMPARE(importer.getSourceIndex(), 2);

    UMLObject *sys = doc->findUMLObject("System", UMLObject::ot_Package, nullptr);
    QVERIFY(sys == nullptr);
}

QTEST_MAIN(TestAdaImport)
#include "testadaimport.moc"
