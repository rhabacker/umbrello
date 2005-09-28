/*
 *  copyright (C) 2002-2005
 *  Umbrello UML Modeller Authors <uml-devel@ uml.sf.net>
 */

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

// own header
#include "umlattributedialog.h"

// qt includes
#include <qlayout.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <q3groupbox.h>
#include <q3buttongroup.h>
#include <qradiobutton.h>
#include <qlabel.h>
//Added by qt3to4:
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

// kde includes
#include <kcombobox.h>
#include <kcompletion.h>
#include <klocale.h>
#include <kmessagebox.h>
#include <kdebug.h>

// app includes
#include "../attribute.h"
#include "../classifier.h"
#include "../template.h"
#include "../umldoc.h"
#include "../uml.h"
#include "../dialog_utils.h"

UMLAttributeDialog::UMLAttributeDialog( QWidget * pParent, UMLAttribute * pAttribute )
        : KDialogBase( Plain, i18n("Attribute Properties"), Help | Ok | Cancel , Ok, pParent, "_UMLATTRIBUTEDLG_", true, true) {
    m_pAttribute = pAttribute;
    setupDialog();
}

UMLAttributeDialog::~UMLAttributeDialog() {}

void UMLAttributeDialog::setupDialog() {
    UMLDoc * pDoc = UMLApp::app()->getDocument();
    int margin = fontMetrics().height();

    QVBoxLayout * mainLayout = new QVBoxLayout( plainPage() );

    m_pValuesGB = new Q3GroupBox(i18n("General Properties"), plainPage() );
    QGridLayout * valuesLayout = new QGridLayout(m_pValuesGB, 5, 2);
    valuesLayout -> setMargin(margin);
    valuesLayout -> setSpacing(10);

    m_pTypeL = new QLabel(i18n("&Type:"), m_pValuesGB);
    valuesLayout -> addWidget(m_pTypeL, 0, 0);

    m_pTypeCB = new KComboBox(true, m_pValuesGB);
    valuesLayout -> addWidget(m_pTypeCB, 0, 1);
    m_pTypeL->setBuddy(m_pTypeCB);

    Dialog_Utils::makeLabeledEditField( m_pValuesGB, valuesLayout, 1,
                                    m_pNameL, i18n("&Name:"),
                                    m_pNameLE, m_pAttribute->getName() );

    Dialog_Utils::makeLabeledEditField( m_pValuesGB, valuesLayout, 2,
                                    m_pInitialL, i18n("&Initial value:"),
                                    m_pInitialLE, m_pAttribute->getInitialValue() );

    Dialog_Utils::makeLabeledEditField( m_pValuesGB, valuesLayout, 3,
                                    m_pStereoTypeL, i18n("Stereotype name:"),
                                    m_pStereoTypeLE, m_pAttribute->getStereotype() );

    m_pStaticCB = new QCheckBox( i18n("Classifier &scope (\"static\")"), m_pValuesGB );
    m_pStaticCB -> setChecked( m_pAttribute -> getStatic() );
    valuesLayout -> addWidget(m_pStaticCB, 4, 0);


    mainLayout -> addWidget(m_pValuesGB);


    m_pScopeBG = new Q3ButtonGroup(i18n("Visibility"), plainPage() );
    QHBoxLayout * scopeLayout = new QHBoxLayout(m_pScopeBG);
    scopeLayout -> setMargin(margin);

    m_pPublicRB = new QRadioButton(i18n("&Public"), m_pScopeBG);
    scopeLayout -> addWidget(m_pPublicRB);

    m_pPrivateRB = new QRadioButton(i18n("P&rivate"), m_pScopeBG);
    scopeLayout -> addWidget(m_pPrivateRB);

    m_pProtectedRB = new QRadioButton(i18n("Prot&ected"), m_pScopeBG);
    scopeLayout -> addWidget(m_pProtectedRB);
    mainLayout -> addWidget(m_pScopeBG);
    Uml::Scope scope = m_pAttribute -> getScope();
    if( scope == Uml::Public )
        m_pPublicRB -> setChecked( true );
    else if( scope == Uml::Private )
        m_pPrivateRB -> setChecked( true );
    else
        m_pProtectedRB -> setChecked( true );

    m_pTypeCB->setDuplicatesEnabled(false);//only allow one of each type in box

    //now add the Concepts
    UMLClassifierList namesList( pDoc->getConcepts() );
    UMLClassifier* obj;
    for (obj=namesList.first(); obj!=0; obj=namesList.next()) {
        insertType( obj->getFullyQualifiedName() );
    }

    //work out which one to select
    int typeBoxCount = 0;
    bool foundType = false;
    while (typeBoxCount < m_pTypeCB->count() && foundType == false) {
        QString typeBoxString = m_pTypeCB->text(typeBoxCount);
        if ( typeBoxString == m_pAttribute->getTypeName() ) {
            foundType = true;
            m_pTypeCB->setCurrentItem(typeBoxCount);
        } else {
            typeBoxCount++;
        }
    }

    if (!foundType) {
        insertType( m_pAttribute->getTypeName(), 0 );
        m_pTypeCB->setCurrentItem(0);
    }

    m_pNameLE->setFocus();
    connect( m_pNameLE, SIGNAL( textChanged ( const QString & ) ), SLOT( slotNameChanged( const QString & ) ) );
    slotNameChanged(m_pNameLE->text() );
}

void UMLAttributeDialog::slotNameChanged( const QString &_text )
{
    enableButtonOK( !_text.isEmpty() );
}

bool UMLAttributeDialog::apply() {
    QString name = m_pNameLE->text();
    if (name.isEmpty()) {
        KMessageBox::error(this, i18n("You have entered an invalid attribute name."),
                           i18n("Attribute Name Invalid"), false);
        m_pNameLE->setText( m_pAttribute->getName() );
        return false;
    }
    UMLClassifier * pConcept = dynamic_cast<UMLClassifier *>( m_pAttribute->parent() );
    UMLObject *o = pConcept->findChildObject(name);
    if (o && o != m_pAttribute) {
        KMessageBox::error(this, i18n("The attribute name you have chosen is already being used in this operation."),
                           i18n("Attribute Name Not Unique"), false);
        m_pNameLE->setText( m_pAttribute->getName() );
        return false;
    }
    m_pAttribute->setName(name);
    Uml::Scope scope = Uml::Protected;
    if ( m_pPublicRB->isChecked() ) {
        scope = Uml::Public;
    } else if ( m_pPrivateRB -> isChecked() ) {
        scope = Uml::Private;
    }
    m_pAttribute->setScope(scope);
    // Set the scope as the default in the option state
    Settings::OptionState optionState = UMLApp::app()->getOptionState();
    optionState.classState.defaultAttributeScope = scope;
    UMLApp::app()->setOptionState(optionState);

    m_pAttribute->setInitialValue( m_pInitialLE->text() );
    m_pAttribute->setStereotype( m_pStereoTypeLE->text() );
    m_pAttribute->setStatic( m_pStaticCB->isChecked() );

    QString typeName = m_pTypeCB->currentText();
    UMLTemplate *tmplParam = pConcept->findTemplate(typeName);
    if (tmplParam) {
        m_pAttribute->setType(tmplParam);
        return true;
    }
    UMLDoc * pDoc = UMLApp::app()->getDocument();
    UMLObject *obj = pDoc->findUMLObject(typeName);
    UMLClassifier *classifier = dynamic_cast<UMLClassifier*>(obj);
    if (classifier == NULL) {
        // If it's obviously a pointer type (C++) then create a datatype.
        // Else we don't know what it is so as a compromise create a class.
        Uml::Object_Type ot = (typeName.contains('*') ? Uml::ot_Datatype
                               : Uml::ot_Class);
        obj = pDoc->createUMLObject(ot, typeName);
        if (obj == NULL)
            return false;
        classifier = static_cast<UMLClassifier*>(obj);
    }
    m_pAttribute->setType( classifier );
    return true;
}

void UMLAttributeDialog::slotApply() {
    apply();
}

void UMLAttributeDialog::slotOk() {
    if ( apply() ) {
        accept();
    }
}

void UMLAttributeDialog::insertType( const QString& type, int index )
{
    m_pTypeCB->insertItem( type, index );
    m_pTypeCB->completionObject()->addItem( type );
}


#include "umlattributedialog.moc"
