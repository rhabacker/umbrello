/*
    SPDX-FileCopyrightText: 2025 Ralf Habacker <ralf.habacker@freenet.de>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#pragma once

#include <QObject>

class TestAda95Import : public QObject {
    Q_OBJECT
protected Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

private Q_SLOTS:
    void test_import_file();
};
