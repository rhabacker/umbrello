/*
    SPDX-FileCopyrightText: 2025 Ralf Habacker <ralf.habacker@freenet.de>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef TEST_ADAIMPORT_H
#define TEST_ADAIMPORT_H

#include <QObject>

class TestAdaImport : public QObject {
    Q_OBJECT
protected Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

private Q_SLOTS:
    void test_import_file();

private:
    void test_parse_with_clause();
    void test_parse_package_declaration();
    void test_parse_subtype();
    void test_parse_enum_type();
    void test_parse_function_with_parameters();
    void test_parse_attribute_declaration();
    void test_parse_generic_package();
    void test_parse_function_multiple_parameters();
    void test_parse_with_clause_skipped();
};

#endif // TEST_ADAIMPORT_H
