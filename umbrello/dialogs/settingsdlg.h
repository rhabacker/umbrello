/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef SETTINGSDLG_H
#define SETTINGSDLG_H
//qt includes
#include <qgroupbox.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qdict.h> 
//kde includes
#include <kcombobox.h>
#include <kfontdialog.h>
#include <kdialogbase.h>
#include <kcolorbutton.h>
//app includes
#include "../codegenerator.h"

class CodeGenerationOptionsPage;
/**
 * @author Paul Hensgen
 */

class SettingsDlg : public KDialogBase {

	Q_OBJECT

public:
	//enums
	enum Page
	{
	    page_general = 0,
	    page_font,
	    page_UI,
	    page_class,
	    page_codegen
	};

	enum Diagram
	{
	    diagram_no = 0,
	    diagram_class,
	    diagram_usecase,
	    diagram_sequence,
	    diagram_collaboration,
	    diagram_state,
	    diagram_activity,
	    diagram_component,
	    diagram_deployment
	};

	struct CodeGenState {
		QString outputDir;
		QString headingsDir;
		bool includeHeadings;
		bool forceDoc;
		bool forceSections;
		CodeGenerator::OverwritePolicy overwritePolicy;
		CodeGenerator::ModifyNamePolicy modname;
	}
	;//end struct CodeGenState

	//public structs
	struct GeneralState {
		bool autosave;
		int time;
		bool logo;
		bool tip;
		bool loadlast;
		Diagram diagram;
		QString lastFile;
	}
	;//end struct GeneralState

	struct UIState {
		bool useFillColor;
		QColor fillColor;
		QColor lineColor;
		QFont font;
	}
	;//end struct UIState

	struct ClassState {
		bool showScope;
		bool showAtts;
		bool showOps;
		bool showStereoType;
		bool showAttSig;
		bool showOpSig;
		bool showPackage;
	}
	;//end struct ClassState

	struct OptionState {
		GeneralState generalState;
		UIState uiState;
		ClassState classState;
		CodeGenState  codegenState;
	}
	;//end struct OptionState

	SettingsDlg( QWidget * parent, OptionState state, 
		     QDict<GeneratorInfo> ldict, QString activeLanguage);
	~SettingsDlg();

	//public methods
	OptionState getOptionState() {
		return m_OptionState;
	}
	bool getChangesApplied() {
		return m_bChangesApplied;
	}

	QString getCodeGenerationLanguage();

private:
	//private structs
	struct UIWidgets {
		QGroupBox * colorGB;

		QLabel * lineColorL;
		QLabel * fillColorL;

		QPushButton * lineDefaultB;
		QPushButton * fillDefaultB;

		KColorButton * lineColorB;
		KColorButton * fillColorB;

		QCheckBox * useFillColorCB;
	}
	;//end struct UIWidgets

	struct GeneralWidgets {
		QGroupBox * autosaveGB;
		QGroupBox * startupGB;

		KComboBox * timeKB;
		KComboBox * diagramKB;

		QCheckBox * autosaveCB;
		QCheckBox * logoCB;
		QCheckBox * tipCB;
		QCheckBox * loadlastCB;

		QLabel * startL;
		QLabel *  autosaveL;
	}
	;//end struct GeneralWidgets

	struct ClassWidgets {
		QGroupBox * visibilityGB;

		QCheckBox * showScopeCB;
		QCheckBox * showAttsCB;
		QCheckBox * showOpsCB;
		QCheckBox * showStereotypeCB;
		QCheckBox * showAttSigCB;
		QCheckBox * showPackageCB;

		QCheckBox * showOpSigCB;
	}
	;//end struct ClassWidgets

	struct FontWidgets {
		KFontChooser * chooser;
	};

	//private methods
	void setupFontPage();
	void setupUIPage();
	void setupGeneralPage();
	void setupClassPage();
	void setupCodeGenPage(QDict<GeneratorInfo> ldict, QString activeLanguage);
	void applyPage( Page page );

	//private attributes
	FontWidgets m_FontWidgets;
	GeneralWidgets m_GeneralWidgets;
	UIWidgets m_UiWidgets;
	ClassWidgets m_ClassWidgets;
	OptionState m_OptionState;
	CodeGenerationOptionsPage * m_pCodeGenPage;

	KConfig * m_pCfg;
	bool m_bChangesApplied;

	//signals
signals:
	//slots
private slots:
	void slotApply();
	void slotOk();
	void slotDefault();
	void slotLineBClicked();
	void slotFillBClicked();
	void slotAutosaveCBClicked();
};

#endif
