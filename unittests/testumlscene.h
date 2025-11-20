/*
    SPDX-FileCopyrightText: 2025 Umbrello UML Modeller Authors <umbrello-devel@kde.org>
    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#pragma once

#include "testbase.h"

class TestUMLScene: public TestBase
{
    Q_OBJECT
private Q_SLOTS:
    void test_createAutoAssignments();
    void test_updateAutoAssignments();
};
