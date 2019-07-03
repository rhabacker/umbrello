/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2014                                               *
 *   Umbrello UML Modeller Authors <umbrello-devel@kde.org>                *
 ***************************************************************************/

// own header
#include "generaloptionpage.h"

// local includes
#include "dialog_utils.h"
#include "optionstate.h"

// kde includes
#include <KComboBox>
#if QT_VERSION < 0x050000
#include <KDialog>
#include <KIntSpinBox>
#endif
#include <KLineEdit>
#include <KLocalizedString>

// qt includes
#include <QCheckBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#if QT_VERSION >= 0x050000
#include <QSpinBox>
#endif

/**
 * Constructor.
 * @param parent   the parent (wizard) of this wizard page
 */
GeneralOptionPage::GeneralOptionPage(QWidget* parent)
  : DialogPageBase(parent)
{
    Settings::OptionState &optionState = Settings::optionState();
#if QT_VERSION >= 0x050000
    int spacingHint = 2;
#else
    int spacingHint = static_cast<KDialog*>(parent)->spacingHint();
#endif

    QVBoxLayout *topLayout = new QVBoxLayout(this);

    // Set up undo setting
    m_GeneralWidgets.miscGB = new QGroupBox(i18nc("miscellaneous group box", "Miscellaneous"));
    topLayout->addWidget(m_GeneralWidgets.miscGB);

    QGridLayout * miscLayout = new QGridLayout(m_GeneralWidgets.miscGB);
    miscLayout->setSpacing(spacingHint);
    miscLayout->setMargin(fontMetrics().height());

    m_GeneralWidgets.undoCB = new QCheckBox(i18n("Enable undo"), m_GeneralWidgets.miscGB);
    m_GeneralWidgets.undoCB->setChecked(optionState.generalState.undo);
    miscLayout->addWidget(m_GeneralWidgets.undoCB, 0, 0);

    m_GeneralWidgets.tabdiagramsCB = new QCheckBox(i18n("Use tabbed diagrams"), m_GeneralWidgets.miscGB);
    m_GeneralWidgets.tabdiagramsCB->setChecked(optionState.generalState.tabdiagrams);
    miscLayout->addWidget(m_GeneralWidgets.tabdiagramsCB, 0, 1);
#ifdef ENABLE_NEW_CODE_GENERATORS
    m_GeneralWidgets.newcodegenCB = new QCheckBox(i18n("Use new C++/Java/Ruby generators"), m_GeneralWidgets.miscGB);
    m_GeneralWidgets.newcodegenCB->setChecked(optionState.generalState.newcodegen);
    miscLayout->addWidget(m_GeneralWidgets.newcodegenCB, 1, 0);
#endif
    m_GeneralWidgets.angularLinesCB = new QCheckBox(i18n("Use angular association lines"), m_GeneralWidgets.miscGB);
    m_GeneralWidgets.angularLinesCB->setChecked(optionState.generalState.angularlines);
    miscLayout->addWidget(m_GeneralWidgets.angularLinesCB, 1, 1);

    m_GeneralWidgets.footerPrintingCB = new QCheckBox(i18n("Turn on footer and page numbers when printing"), m_GeneralWidgets.miscGB);
    m_GeneralWidgets.footerPrintingCB->setChecked(optionState.generalState.footerPrinting);
    miscLayout->addWidget(m_GeneralWidgets.footerPrintingCB, 2, 0);
    
    m_GeneralWidgets.layoutTypeL = new QLabel(i18n("Create new association lines as:"), m_GeneralWidgets.miscGB);
    miscLayout->addWidget(m_GeneralWidgets.layoutTypeL, 3, 0);
    m_GeneralWidgets.layoutTypeKB = new KComboBox(m_GeneralWidgets.miscGB);
#if QT_VERSION < 0x050000
    m_GeneralWidgets.layoutTypeKB->setCompletionMode(KGlobalSettings::CompletionPopup);
#endif
    miscLayout->addWidget(m_GeneralWidgets.layoutTypeKB, 3, 1);
    for (int layoutTypeNo = 1; layoutTypeNo < 5; ++layoutTypeNo) {
        Uml::LayoutType::Enum lt = Uml::LayoutType::fromInt(layoutTypeNo);
        insertLayoutType(Uml::LayoutType::toString(lt), layoutTypeNo - 1);
    }
    m_GeneralWidgets.layoutTypeKB->setCurrentIndex((int)optionState.generalState.layoutType-1);
    
    topLayout->addWidget(m_GeneralWidgets.miscGB);

    //setup autosave settings
    m_GeneralWidgets.autosaveGB = new QGroupBox(i18n("Autosave"));
    topLayout->addWidget(m_GeneralWidgets.autosaveGB);

    QGridLayout * autosaveLayout = new QGridLayout(m_GeneralWidgets.autosaveGB);
    autosaveLayout->setSpacing(spacingHint);
    autosaveLayout->setMargin(fontMetrics().height());

    m_GeneralWidgets.autosaveCB = new QCheckBox(i18n("E&nable autosave"), m_GeneralWidgets.autosaveGB);
    m_GeneralWidgets.autosaveCB->setChecked(optionState.generalState.autosave);
    autosaveLayout->addWidget(m_GeneralWidgets.autosaveCB, 0, 0);

    m_GeneralWidgets.autosaveL = new QLabel(i18n("Select auto-save time interval (mins):"), m_GeneralWidgets.autosaveGB);
    autosaveLayout->addWidget(m_GeneralWidgets.autosaveL, 1, 0);

#if QT_VERSION >= 0x050000
    m_GeneralWidgets.timeISB = new QSpinBox(m_GeneralWidgets.autosaveGB);
    m_GeneralWidgets.timeISB->setRange(1, 600);
    m_GeneralWidgets.timeISB->setSingleStep(1);
    m_GeneralWidgets.timeISB->setValue(optionState.generalState.autosavetime);
#else
    m_GeneralWidgets.timeISB = new KIntSpinBox(1, 600, 1, optionState.generalState.autosavetime, m_GeneralWidgets.autosaveGB);
#endif
    m_GeneralWidgets.timeISB->setEnabled(optionState.generalState.autosave);
    autosaveLayout->addWidget(m_GeneralWidgets.timeISB, 1, 1);

    // Allow definition of Suffix for autosave (default: ".xmi")generator
    Dialog_Utils::makeLabeledEditField(autosaveLayout, 2,
                                        m_GeneralWidgets.autosaveSuffixL, i18n("Set autosave suffix:"),
                                        m_GeneralWidgets.autosaveSuffixT, optionState.generalState.autosavesuffix);
                                        QString autoSaveSuffixToolTip = i18n("<qt><p>The autosave file will be saved to ~/autosave.xmi if the autosaving occurs "
                                        "before you have manually saved the file.</p>"
                                        "<p>If you have already saved it, the autosave file will be saved in the same folder as the file "
                                        "and will be named like the file's name, followed by the suffix specified.</p>"
                                        "<p>If the suffix is equal to the suffix of the file you have saved, "
                                        "the autosave will overwrite your file automatically.</p></qt>");
    m_GeneralWidgets.autosaveSuffixL->setToolTip(autoSaveSuffixToolTip);
    m_GeneralWidgets.autosaveSuffixT->setToolTip(autoSaveSuffixToolTip);
    topLayout->addWidget(m_GeneralWidgets.autosaveGB);

    //setup backup settings
    QGroupBox *backupBox = new QGroupBox(i18n("Backup"));
    topLayout->addWidget(backupBox);
    QGridLayout * backupLayout = new QGridLayout(backupBox);
    m_GeneralWidgets.makeBackupCB = new QCheckBox(i18n("Create backup file when saving"), backupBox);
    m_GeneralWidgets.makeBackupCB->setChecked(optionState.generalState.makeBackup);
    backupLayout->addWidget(m_GeneralWidgets.makeBackupCB, 0, 0);
    QLabel *label;
    Dialog_Utils::makeLabeledEditField(backupLayout, 1,
                                        label, i18n("Date related file name pattern:"),
                                        m_GeneralWidgets.backupPatternT, optionState.generalState.backupDatePattern);
    QString backupPatternToolTip = i18n("<qt><p>The date related file name pattern will be used to create the date part of the backup file name.</p>"
    "<p>The following patterns are available:<ul>"
    "<li>yyyy - Year</li>"
    "<li>MM - Month</li>"
    "<li>dd - Day</li>"
    "<li>HH - Hour</li>"
    "<li>mm - Minute</li>"
    "<li>ss - Seconds</li>"
    "</ul></p>"
    "</qt>");
    label->setToolTip(backupPatternToolTip);
    m_GeneralWidgets.backupPatternT->setToolTip(backupPatternToolTip);

    //setup startup settings
    m_GeneralWidgets.startupGB = new QGroupBox(i18n("Startup"));
    topLayout->addWidget(m_GeneralWidgets.startupGB);

    QGridLayout * startupLayout = new QGridLayout(m_GeneralWidgets.startupGB);
    startupLayout->setSpacing(spacingHint);
    startupLayout->setMargin(fontMetrics().height());

    m_GeneralWidgets.loadlastCB = new QCheckBox(i18n("&Load last project"), m_GeneralWidgets.startupGB);
    m_GeneralWidgets.loadlastCB->setChecked(optionState.generalState.loadlast);
    startupLayout->addWidget(m_GeneralWidgets.loadlastCB, 0, 0);

    m_GeneralWidgets.startL = new QLabel(i18n("Start new project with:"), m_GeneralWidgets.startupGB);
    startupLayout->addWidget(m_GeneralWidgets.startL, 1, 0);

    m_GeneralWidgets.diagramKB = new KComboBox(m_GeneralWidgets.startupGB);
#if QT_VERSION < 0x050000
    m_GeneralWidgets.diagramKB->setCompletionMode(KGlobalSettings::CompletionPopup);
#endif
    startupLayout->addWidget(m_GeneralWidgets.diagramKB, 1, 1);

    // start at 1 because we don't allow No Diagram any more
    // diagramNo 1 is Uml::DiagramType::Class
    // digaramNo 9 is Uml::DiagramType::EntityRelationship
    for (int diagramNo = 1; diagramNo < 10; ++diagramNo) {
        Uml::DiagramType::Enum dt = Uml::DiagramType::fromInt(diagramNo);
        insertDiagram(Uml::DiagramType::toString(dt), diagramNo - 1);
    }

    m_GeneralWidgets.diagramKB->setCurrentIndex((int)optionState.generalState.diagram-1);
    connect(m_GeneralWidgets.autosaveCB, SIGNAL(clicked()), this, SLOT(slotAutosaveCBClicked()));

    m_GeneralWidgets.defaultLanguageL = new QLabel(i18n("Default Language :"), m_GeneralWidgets.startupGB);
    startupLayout->addWidget(m_GeneralWidgets.defaultLanguageL, 2, 0);

    m_GeneralWidgets.languageKB = new KComboBox(m_GeneralWidgets.startupGB);
#if QT_VERSION < 0x050000
    m_GeneralWidgets.languageKB->setCompletionMode(KGlobalSettings::CompletionPopup);
#endif
    startupLayout->addWidget(m_GeneralWidgets.languageKB, 2, 1);

    int indexCounter = 0;
    while (indexCounter < Uml::ProgrammingLanguage::Reserved) {
        QString language = Uml::ProgrammingLanguage::toString(Uml::ProgrammingLanguage::fromInt(indexCounter));
        m_GeneralWidgets.languageKB->insertItem(indexCounter, language);
        indexCounter++;
    }
    m_GeneralWidgets.languageKB->setCurrentIndex(optionState.generalState.defaultLanguage);
    topLayout->addWidget(m_GeneralWidgets.startupGB);
}

/**
 * Destructor.
 */
GeneralOptionPage::~GeneralOptionPage()
{
}

/**
 * Sets default values.
 */
void GeneralOptionPage::setDefaults()
{
    m_GeneralWidgets.autosaveCB->setChecked(false);
    m_GeneralWidgets.timeISB->setValue(5);
    m_GeneralWidgets.timeISB->setEnabled(true);
    m_GeneralWidgets.loadlastCB->setChecked(true);
    m_GeneralWidgets.diagramKB->setCurrentIndex(0);
    m_GeneralWidgets.languageKB->setCurrentIndex(Uml::ProgrammingLanguage::Cpp);
}

/**
 * Reads the set values from their corresponding widgets, writes them back to
 * the data structure, and notifies clients.
 */
void GeneralOptionPage::apply()
{
    Settings::OptionState &optionState = Settings::optionState();
    optionState.generalState.undo = m_GeneralWidgets.undoCB->isChecked();
    optionState.generalState.tabdiagrams = m_GeneralWidgets.tabdiagramsCB->isChecked();
#ifdef ENABLE_NEW_CODE_GENERATORS
    optionState.generalState.newcodegen = m_GeneralWidgets.newcodegenCB->isChecked();
#endif
    optionState.generalState.angularlines = m_GeneralWidgets.angularLinesCB->isChecked();
    optionState.generalState.layoutType = Uml::LayoutType::fromInt(m_GeneralWidgets.layoutTypeKB->currentIndex() + 1);
    optionState.generalState.footerPrinting = m_GeneralWidgets.footerPrintingCB->isChecked();
    optionState.generalState.autosave = m_GeneralWidgets.autosaveCB->isChecked();
    optionState.generalState.autosavetime = m_GeneralWidgets.timeISB->value();
    // retrieve Suffix setting from dialog entry
    optionState.generalState.autosavesuffix = m_GeneralWidgets.autosaveSuffixT->text();
    optionState.generalState.makeBackup = m_GeneralWidgets.makeBackupCB->isChecked();
    optionState.generalState.backupDatePattern = m_GeneralWidgets.backupPatternT->text();
    optionState.generalState.loadlast = m_GeneralWidgets.loadlastCB->isChecked();
    optionState.generalState.diagram  = Uml::DiagramType::fromInt(m_GeneralWidgets.diagramKB->currentIndex() + 1);
    optionState.generalState.defaultLanguage = Uml::ProgrammingLanguage::fromInt(m_GeneralWidgets.languageKB->currentIndex());
    emit applyClicked();
}

/**
 * Inserts @p type into the type-combobox as well as its completion object.
 */
void GeneralOptionPage::insertDiagram(const QString& type, int index)
{
    m_GeneralWidgets.diagramKB->insertItem(index, type);
    m_GeneralWidgets.diagramKB->completionObject()->addItem(type);
}

/**
 * Inserts @p type into the type-combobox as well as its completion object.
 */
void GeneralOptionPage::insertLayoutType(const QString& type, int index)
{
    m_GeneralWidgets.layoutTypeKB->insertItem(index, type);
    m_GeneralWidgets.layoutTypeKB->completionObject()->addItem(type);
}

/**
 * Slot for clicked event.
 */
void GeneralOptionPage::slotAutosaveCBClicked()
{
    m_GeneralWidgets.timeISB->setEnabled(m_GeneralWidgets.autosaveCB->isChecked());
}
