
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "actor.h"
#include "classimport.h"
#include "class.h"
#include "package.h"
#include "component.h"
#include "node.h"
#include "artifact.h"
#include "interface.h"
#include "docwindow.h"
#include "listpopupmenu.h"
#include "operation.h"
#include "attribute.h"
#include "uml.h"
#include "umldoc.h"
#include "umllistview.h"
#include "umllistviewitemdatalist.h"
#include "umlview.h"
#include "usecase.h"
#include "clipboard/idchangelog.h"
#include "clipboard/umldrag.h"
#include "dialogs/classpropdlg.h"
#include "dialogs/umlattributedialog.h"
#include "dialogs/umloperationdialog.h"
#include <kiconloader.h>
#include <kapplication.h>
#include <kdebug.h>
#include <kfiledialog.h>
#include <klocale.h>
#include <kmessagebox.h>
#include <kstandarddirs.h>
#include "diagram/diagram.h"

//using Umbrello::Diagram;

UMLListView::UMLListView(QWidget *parent,const char *name) :
	KListView(parent,name),
	menu(0)
{
	loadPixmaps();

	//setup list view
	setBackgroundColor(white);
	setAcceptDrops(true);
	setDropVisualizer(false);
	setItemsMovable(true);
	setItemsRenameable( true );
	setSelectionModeExt(FileManager);
	setShowToolTips( true );
	setTooltipColumn( 0 );
	setFocusPolicy(QWidget::StrongFocus);
	setDragEnabled(TRUE);
	setColumnWidthMode( 0, Manual );
	setDefaultRenameAction( Reject );
	setResizeMode( LastColumn );
	//add columns and initial items
	addColumn(i18n("UML Diagrams"));

	rv =  new UMLListViewItem(this, i18n("Views"), Uml::lvt_View);
	ucv = new UMLListViewItem(rv, i18n("Use Case View"), Uml::lvt_UseCase_View);
	lv = new UMLListViewItem(rv, i18n("Logical View"), Uml::lvt_Logical_View);
	componentView = new UMLListViewItem(rv, i18n("Component View"), Uml::lvt_Component_View);
	deploymentView = new UMLListViewItem(rv, i18n("Deployment View"), Uml::lvt_Deployment_View);
	diagramFolder = new UMLListViewItem(rv,i18n("Diagrams"),Uml::lvt_Diagrams);

	init();

	//setup slots/signals
	connect(this, SIGNAL(dropped(QDropEvent *, QListViewItem *, QListViewItem *)), this, SLOT(slotDropped(QDropEvent *, QListViewItem *, QListViewItem *)));
	connect( this, SIGNAL( collapsed( QListViewItem * ) ), this, SLOT( slotCollapsed( QListViewItem * ) ) );
	connect( this, SIGNAL( expanded( QListViewItem * ) ), this, SLOT( slotExpanded( QListViewItem * ) ) );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
UMLListView::~UMLListView() {}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::contentsMousePressEvent(QMouseEvent *me) {
	if( isRenaming() )
		return;
	if( doc -> getCurrentView() )
		doc -> getCurrentView() -> clearSelected();
	if( me -> state() != ShiftButton )
		clearSelection();
	//UMLListViewItem *item = (UMLListViewItem *)currentItem();
	QPoint pt = ((UMLListView*)this) -> contentsToViewport( me -> pos() );
	UMLListViewItem * item = (UMLListViewItem*)itemAt(pt);


	if(  me -> button() != RightButton && me -> button() != LeftButton  ) {
		doc -> getDocWindow() -> updateDocumentation( true );
		return;
	}

	Uml::ListView_Type type;
	type = item ? item->getType() : lvt_Unknown;
	if (me->button() == LeftButton) {
		switch( type ) {
			//If is necesary activate the view
		case Uml::lvt_UseCase_Diagram:
		case Uml::lvt_Class_Diagram:
		case Uml::lvt_Collaboration_Diagram:
		case Uml::lvt_Sequence_Diagram:
		case Uml::lvt_State_Diagram:
		case Uml::lvt_Activity_Diagram:
		case Uml::lvt_Component_Diagram:
		case Uml::lvt_Deployment_Diagram:
			if( ! doc->activateView( item->getID()))
				KMessageBox::error( kapp -> mainWidget(), i18n("Could not activate the diagram."), i18n("Diagram Load Error"));
			else
				doc -> changeCurrentView(item->getID());
			emit diagramSelected( item->getID());
			doc -> getDocWindow() -> showDocumentation( doc -> findView( item -> getID() ), false );
			break;

		case Uml::lvt_UseCase:
		case Uml::lvt_Class:
		case Uml::lvt_Package:
		case Uml::lvt_Component:
		case Uml::lvt_Node:
		case Uml::lvt_Interface:
		case Uml::lvt_Actor:
		case Uml::lvt_Attribute:
		case Uml::lvt_Operation:
			doc -> getDocWindow() -> showDocumentation( item -> getUMLObject(), false );
			break;

		default:
			doc -> getDocWindow() -> updateDocumentation( true );
			break;
		}
	}//end switch
	if(me->button() == RightButton) {
		//setSelected( item, true);
		if(menu != 0) {
			menu->hide();
			disconnect(menu, SIGNAL(activated(int)), this, SLOT(popupMenuSel(int)));
			delete menu;
			menu = 0;
		}

		menu = new ListPopupMenu(this, type);
		menu->popup(me->globalPos());
		connect(menu, SIGNAL(activated(int)), this, SLOT(popupMenuSel(int)));
	}//end if right button

	/*
		We don't need to do anything for Left button.
		But if we do in future, just put and else statement in here
	*/
	if( !isRenaming() )
		this->KListView::contentsMousePressEvent(me);


}

void UMLListView::contentsMouseReleaseEvent(QMouseEvent *me) {
	if( isRenaming() )
		return;
	this->KListView::contentsMouseReleaseEvent(me);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::popupMenuSel(int sel) {
	UMLListViewItem * temp = (UMLListViewItem*)currentItem();
	if( !temp ) {
		kdDebug() << "popupMenuSel invoked without currently selectedItem" << endl;
		return;
	}
	int id = temp -> getID();
	UMLObject * object = temp -> getUMLObject();
	Uml::ListView_Type lvtType = temp -> getType();
	Uml::UMLObject_Type umlType = Uml::ot_UMLObject;
	QString name;

	switch(sel) {
		case ListPopupMenu::mt_Activity_Diagram:
			doc->createDiagram(dt_Activity);
			break;

		case ListPopupMenu::mt_UseCase_Diagram:
			doc->createDiagram(dt_UseCase);
			break;

		case ListPopupMenu::mt_Sequence_Diagram:
			doc->createDiagram(dt_Sequence);
			break;

		case ListPopupMenu::mt_Collaboration_Diagram:
			doc->createDiagram(dt_Collaboration);
			break;

		case ListPopupMenu::mt_Class_Diagram:
			doc->createDiagram(dt_Class);
			break;

		case ListPopupMenu::mt_State_Diagram:
			doc->createDiagram(dt_State);
			break;

		case ListPopupMenu::mt_Component_Diagram:
			doc->createDiagram(dt_Component);
			break;

		case ListPopupMenu::mt_Deployment_Diagram:
			doc->createDiagram(dt_Deployment);
			break;

		case ListPopupMenu::mt_Class:
			addNewItem( temp, Uml::lvt_Class );
			break;

		case ListPopupMenu::mt_Package:
			addNewItem(temp, Uml::lvt_Package);
			break;

		case ListPopupMenu::mt_Component:
			addNewItem(temp, Uml::lvt_Component);
			break;

		case ListPopupMenu::mt_Node:
			addNewItem(temp, Uml::lvt_Node);
			break;

		case ListPopupMenu::mt_Artifact:
			addNewItem(temp, Uml::lvt_Artifact);
			break;

		case ListPopupMenu::mt_Interface:
			addNewItem(temp, Uml::lvt_Interface);
			break;

		case ListPopupMenu::mt_Actor:
			addNewItem( temp, Uml::lvt_Actor );
			break;

		case ListPopupMenu::mt_UseCase:
			addNewItem( temp, Uml::lvt_UseCase );
			break;

		case ListPopupMenu::mt_Attribute:
			addNewItem( temp, Uml::lvt_Attribute );
			break;

		case ListPopupMenu::mt_Operation:
			addNewItem( temp, Uml::lvt_Operation );
			break;

		case ListPopupMenu::mt_Import_Classes:
			((ClassImport*)doc)->importCPP(
			    KFileDialog::getOpenFileNames(":import-classes",
			                                  i18n("*.h|Header Files (*.h)\n*.*|All Files"),
			                                  this, i18n("Select Classes to Import") ));
		case ListPopupMenu::mt_Expand_All:
				expandAll(temp);
				break;
		case ListPopupMenu::mt_Collapse_All:
				collapseAll(temp);
				break;

		case ListPopupMenu::mt_Export_Image:
			doc->getCurrentView()->exportImage();
			break;

		case ListPopupMenu::mt_Rename:
			temp-> startRename(0);
			break;

		case ListPopupMenu::mt_Delete:
			if ( typeIsDiagram(lvtType) ) {
				doc->removeDiagram(id);
			} else if( typeIsFolder(lvtType) ) {
				if ( temp->firstChild() ) {
					KMessageBox::error(kapp->mainWidget(), i18n("The folder must be emptied before it can be deleted."), i18n("Folder Not Empty"));
					return;
				}
				delete temp;
			} else {
				doc->removeUMLObject(object);
			}
			return;
			break;

		case ListPopupMenu::mt_Properties:
			/* first check if we are on a diagram */
			if( typeIsDiagram(lvtType) ) {
				UMLView * pView = doc->findView( temp->getID() );
				if( !pView ) {
					return;
				}
				doc->getDocWindow()->updateDocumentation(false);
				pView->showPropDialog();
				doc->getDocWindow()->showDocumentation(pView, true);
				temp->cancelRename(0);
				return;
			}

			/* ok, we are on another object, so find out on which one */
			umlType = object->getBaseType();

			if ( typeIsCanvasWidget(lvtType) ) {
				doc->showProperties(object, ClassPropDlg::page_gen);
			} else if(umlType == Uml::ot_Attribute) {
				// show the attribute dialogue
				UMLAttribute* selectedAttribute = (UMLAttribute*)object;
				UMLAttributeDialog dialogue( this, selectedAttribute );
				if (dialogue.exec()) {
					doc->signalChildUMLObjectUpdate(selectedAttribute);
				}
			} else if(umlType == Uml::ot_Operation) {
				// show the operation dialogue
				UMLOperation* selectedOperation = (UMLOperation*)object;
				UMLOperationDialog dialogue( this, selectedOperation );
				if (dialogue.exec()) {
					doc->signalChildUMLObjectUpdate(selectedOperation);
				}
			} else {
				kdWarning() << "calling properties on unknown type" << endl;
			}
			temp -> cancelRename( 0 );
			break;

		case ListPopupMenu::mt_Logical_Folder:
			addNewItem( temp, Uml::lvt_Logical_Folder );
			doc -> setModified( true );
			break;

		case ListPopupMenu::mt_UseCase_Folder:
			addNewItem( temp, Uml::lvt_UseCase_Folder );
			doc -> setModified( true );
			break;

		case ListPopupMenu::mt_Component_Folder:
			addNewItem(temp, Uml::lvt_Component_Folder);
			doc->setModified(true);
			break;

		case ListPopupMenu::mt_Deployment_Folder:
			addNewItem(temp, Uml::lvt_Deployment_Folder);
			doc->setModified(true);
			break;

		case ListPopupMenu::mt_Cut:
			m_bStartedCut = true;
			doc -> editCut();
			break;

		case ListPopupMenu::mt_Copy:
			doc -> editCopy();
			break;

		case ListPopupMenu::mt_Paste:
			doc -> editPaste();
			break;

		default:
			return;//must be something we don't want to do
			break;
	}//end switch
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::diagramCreated(Diagram* d) {
	new UMLListViewItem( diagramFolder, d->name(),
			     convert_DT_LVT((Uml::Diagram_Type)d->diagramType()), d->getID() );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotDiagramCreated( int id ) {
	if( loading )
		return;
	UMLListViewItem * temp = 0, *p = 0;
	UMLView *v = doc -> findView( id );
	if( !v )
		return;
	//See if we wanted to create diagram in folder
	UMLListViewItem * current = (UMLListViewItem *) currentItem();
	if ( current && typeIsFolder(current->getType()) ) {
		p = current;
	} else if (v->getType() == Uml::dt_UseCase) {
		p = ucv;
	} else if (v->getType() == Uml::dt_Component) {
		p = componentView;
	} else if (v->getType() == Uml::dt_Deployment) {
		p = deploymentView;
	} else {
		p = lv;
	}
	temp = new UMLListViewItem( p, v->getName(), convert_DT_LVT( v->getType() ),  id );
	setSelected( temp, true );
	doc -> getDocWindow() -> showDocumentation( v , false );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotObjectCreated(UMLObject* newObject) {
	if (loading) {
		return;
	}
	UMLListViewItem* newItem = 0;
	UMLListViewItem* parentItem = 0;
	Uml::UMLObject_Type type = newObject->getBaseType();

	//See if we wanted to create diagram in currently selected folder
	UMLListViewItem* current = (UMLListViewItem*) currentItem();
	if( current &&
	    (current->getType() == Uml::lvt_Logical_Folder &&
	     (type == Uml::ot_Class || type == Uml::ot_Package || type == Uml::ot_Interface))
	    || (current->getType() == Uml::lvt_UseCase_Folder &&
		(type == Uml::ot_Actor || type == Uml::ot_UseCase))
	    || (current->getType() == Uml::lvt_Component_Folder &&
		(type == Uml::ot_Component || type == Uml::ot_Artifact)) ) {
		parentItem = current;
	} else if( type == Uml::ot_Class ) {
		parentItem = lv;
	} else if( type == Uml::ot_Package ) {
		parentItem = lv;
	} else if( type == Uml::ot_Interface ) {
		parentItem = lv;
	} else if( type == Uml::ot_Component ) {
		parentItem = componentView;
	} else if( type == Uml::ot_Artifact ) {
		parentItem = componentView;
	} else if( type == Uml::ot_Node ) {
		parentItem = deploymentView;
	} else if( type == Uml::ot_Association ) {
		return;
	} else {
		parentItem = ucv;
	}
	newItem = new UMLListViewItem(parentItem, newObject->getName(), convert_OT_LVT(type), newObject);
	ensureItemVisible(newItem);
	newItem->setOpen(true);
	setSelected(newItem, true);
	doc->getDocWindow()->showDocumentation(newObject, false);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

void UMLListView::slotChildObjectCreated(UMLObject * o) {
	if(loading) {
		return;
	}
	UMLListViewItem *item = findUMLObject((UMLObject*)o->parent());
	UMLListViewItem *temp = new UMLListViewItem(item, o->getName(), convert_OT_LVT( o->getBaseType() ), o);
	ensureItemVisible(item);
	setSelected(temp, true);
	doc -> getDocWindow() -> showDocumentation( o, false );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotDiagramRenamed(int id) {
	UMLListViewItem * temp;
	UMLView *v = doc->findView(id);
	temp = findView(v);
	temp -> setText(v->getName());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotObjectChanged(UMLObject * o) {
	if(loading)//needed for class wizard
		return;
	UMLListViewItem *item = findUMLObject(o);
	if(item)
		item -> updateObject();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotChildObjectChanged(UMLObject * o) {
	if(loading)//needed for class wizard
		return;
	UMLListViewItem * item = findChildUMLObject(o);
	if(item)
		item -> updateObject();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::setDocument(UMLDoc *d) {
	doc = d;
	connect( (UMLApp *)doc -> parent(), SIGNAL( sigCutSuccessful() ), this, SLOT( slotCutSuccessful() ) );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotObjectRemoved(UMLObject * o) {
	if(loading)//needed for class wizard
		return;
	UMLListViewItem * t = findItem(o -> getID());
	delete t;
	doc -> getDocWindow() -> updateDocumentation( true );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::slotDiagramRemoved(int id) {
	UMLListViewItem * temp = findItem(id);
	delete temp;
	doc -> getDocWindow() -> updateDocumentation( true );
}
////////////////////////////////////////////////////////////////////////////////////////////////////
QDragObject* UMLListView::dragObject() {
	UMLListViewItemList selecteditems;
	getSelectedItems(selecteditems);
	selecteditems.setAutoDelete( FALSE );
	UMLListViewItemListIt it(selecteditems);
	UMLListViewItem * item = 0;
	UMLListViewItemDataList  list;
	list.setAutoDelete( FALSE );
	Uml::ListView_Type type;
	while((item=it.current()) != 0) {
		++it;
		type = item->getType();
		if ( !typeIsCanvasWidget(type) && !typeIsDiagram(type) && !typeIsFolder(type) ) {
			return 0;
		}
		list.append(item->getdata());
	}
	UMLDrag *t = new UMLDrag(list, this);

	return t;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::startDrag() {
	QTextDrag * o=(QTextDrag*)dragObject();
	if(o)
		o->dragCopy();
}

UMLListViewItem * UMLListView::findUMLObjectInFolder(UMLListViewItem* folder, UMLObject* obj) {
	UMLListViewItem *item = static_cast<UMLListViewItem *>(folder->firstChild());
	while(item)
	{
		switch(item->getType())
		{
			case Uml::lvt_Actor :
			case Uml::lvt_UseCase :
			case Uml::lvt_Class :
			case Uml::lvt_Package :
			case Uml::lvt_Component :
			case Uml::lvt_Node :
			case Uml::lvt_Artifact :
			case Uml::lvt_Interface :
				if(item->getUMLObject() == obj)
					return item;
				break;
			case Uml::lvt_Logical_Folder :
			case Uml::lvt_UseCase_Folder :
			case Uml::lvt_Component_Folder :
			case Uml::lvt_Deployment_Folder :
				{
				UMLListViewItem *temp = findUMLObjectInFolder(item, obj);
				if (temp)
					return temp;
				}
			default:
				break;
		}
		item = static_cast<UMLListViewItem *>(item->nextSibling());
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
UMLListViewItem * UMLListView::findUMLObject(UMLObject *p) {
	Uml::UMLObject_Type pt = p->getBaseType();
	UMLListViewItem *item, *temp;
	if(pt == Uml::ot_Class || pt == Uml::ot_Package || pt == Uml::ot_Interface) {
		item = lv;
	} else if(pt == Uml::ot_Actor || pt == Uml::ot_UseCase) {
		item = ucv;
	} else if (pt == Uml::ot_Component || pt == Uml::ot_Artifact) {
		item = componentView;
	} else if (pt == Uml::ot_Node) {
		item = deploymentView;
	} else {
		kdWarning() << "listview:findUMLObject" << endl;
		return 0;
	}
	temp = static_cast<UMLListViewItem *>(item->firstChild());
	while(temp) {
		Uml::ListView_Type type = temp->getType();
		if( typeIsFolder(type) ) {
			item = findUMLObjectInFolder(temp, p);
			if (item) {
				return item;
			}
		} else if( typeIsCanvasWidget(type) ) {
			if(temp->getUMLObject() == p) {
				return temp;
			}
		}
		temp = static_cast<UMLListViewItem *>(temp->nextSibling());
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
UMLListViewItem * UMLListView::findChildUMLObject(UMLObject *c) {
	UMLListViewItem *item, *child, *temp;
	//must be an att or op we are looking for here
	item = (UMLListViewItem *)lv->firstChild();
	//go though all classes
	while(item) {
		//item = (UMLListViewItem *)lv->firstChild();
		if(item -> getType() == Uml::lvt_Logical_Folder) {
			temp = (UMLListViewItem *)item->firstChild();
			while(temp) {
				if(temp->getType() == Uml::lvt_Class) {
					child = (UMLListViewItem *)temp->firstChild();
					while(child) {
						if(child->getUMLObject() == c)
							return child;
						child = (UMLListViewItem *)child ->nextSibling();
					}//end while child
				}//end if
				temp =(UMLListViewItem *)temp -> nextSibling();
			}//end while temp
		}//end if Uml::lvt_Logical_Folder
		//check each classes children for the id
		else if(item->getType() == Uml::lvt_Class) {
			child = (UMLListViewItem *)item->firstChild();
			while(child) {
				if(child->getUMLObject() == c)
					return child;
				child = (UMLListViewItem *)child ->nextSibling();
			}//end while child
		}
		item =(UMLListViewItem *)item -> nextSibling();
	}//end while
	kdDebug() << "Error findchild" << endl;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
UMLListViewItem* UMLListView::findView(UMLView *v) {
	if(!v)
		return 0;
	UMLListViewItem *item, *temp, * child;
	Uml::Diagram_Type dType = v->getType();
	Uml::ListView_Type type = convert_DT_LVT( dType );
	int id = v->getID();
	if (dType == Uml::dt_UseCase) {
		item = ucv;
	} else if (dType == Uml::dt_Component) {
		item = componentView;
	} else if (dType == Uml::dt_Deployment) {
		item = deploymentView;
	} else {
		item = lv;
	}

	temp = (UMLListViewItem *)item->firstChild();
	while(temp) {
		if( typeIsFolder(temp->getType()) ) {
			child = (UMLListViewItem *)temp -> firstChild();
			while(child) {
				if( child -> getType() == type && child -> getID() == id)
					return child;
				child = (UMLListViewItem *)child-> nextSibling();
			}
		} else {
			if(temp->getType() == type && temp->getID() == id)
				return temp;
		}
		temp = (UMLListViewItem *)temp->nextSibling();
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
UMLListViewItem* UMLListView::findItem(int id) {
	UMLListViewItem *temp;
	QListViewItemIterator it(this);
	for( ; (temp = (UMLListViewItem*)it.current()); ++it )
		if(temp->getID() == id)
			return temp;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

//
// This method is called more than once during an instance's lifetime (by UMLDoc)!
// So we must not allocate any memory before freeing the previously allocated one
// or do connect()s.
//
void UMLListView::init() {
	deleteChildrenOf( ucv );
	deleteChildrenOf( lv );
	deleteChildrenOf( componentView );
	deleteChildrenOf( deploymentView );
	deleteChildrenOf( diagramFolder );

	rv->setOpen(true);
	ucv->setOpen(true);
	lv->setOpen(true);
	componentView->setOpen(true);
	deploymentView->setOpen(true);

	//setup misc.
	delete menu;
	menu = 0;
	m_bStartedCut = false;
	loading = false;
	m_bIgnoreCancelRename = true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::setView(UMLView * v) {
	if(!v)
		return;
	UMLListViewItem * temp = findView(v);
	if(temp)
		setSelected(temp, true);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void UMLListView::contentsMouseDoubleClickEvent(QMouseEvent * me) {
	UMLListViewItem * item = static_cast<UMLListViewItem *>( currentItem() );
	if( !item || me -> button() != LeftButton )
		return;
	//see if on view
	Uml::ListView_Type lvType = item -> getType();
	if( typeIsDiagram(lvType) ) {
		UMLView * pView = doc -> findView( item -> getID() );
		if( !pView )
			return;
		doc -> getDocWindow() -> updateDocumentation( false );
		pView -> showPropDialog();
		doc -> getDocWindow() -> showDocumentation( pView, true );
		item -> cancelRename( 0 );
		return;
	}
	//else see if an object
	UMLObject * object = item -> getUMLObject();
	//continue only if we are on a UMLObject
	if(!object)
		return;


	Uml::UMLObject_Type type = object -> getBaseType();
	int page = ClassPropDlg::page_gen;
	if(type == Uml::ot_Attribute || type == Uml::ot_Operation)
		object = (UMLObject *)object -> parent();
	//set what page to show
	if(type == Uml::ot_Attribute)
		page = ClassPropDlg::page_att;
	else if(type == Uml::ot_Operation)
		page = ClassPropDlg::page_op;

	if(object)
		doc -> showProperties(object, page);
	item -> cancelRename( 0 );//double click can cause it to go into rename mode.
}


bool UMLListView::acceptDrag(QDropEvent* event) const {
	QPoint mousePoint = ((UMLListView*)this)->contentsToViewport( event->pos() );

	UMLListViewItem* item = (UMLListViewItem*)itemAt(mousePoint);
	if(!item) {
		return false;
	}
	((QListView*)this)->setCurrentItem( (QListViewItem*)item );
	UMLListViewItemDataList list;

	bool status = UMLDrag::decodeClip3(event, list);
	if(!status) {
		return false;
	}

	UMLListViewItemDataListIt it(list);
	UMLListViewItemData* data = 0;
	int type = 0;
	bool accept = true;
	type = item->getType();
	while(accept && ((data = it.current()) != 0)) {
		++it;
		if((data->getType() == Uml::lvt_Class || data->getType() == Uml::lvt_Package
		    || data->getType() == Uml::lvt_Interface || data->getType() == Uml::lvt_Class_Diagram
		    || data->getType() == Uml::lvt_Collaboration_Diagram
		    || data->getType() == Uml::lvt_State_Diagram
		    || data->getType() == Uml::lvt_Activity_Diagram
		    || data->getType() == Uml::lvt_Sequence_Diagram)
		   && (type == Uml::lvt_Logical_Folder || type == Uml::lvt_Logical_View) ) {
			continue;
		}
		if( (data->getType() == Uml::lvt_Actor || data->getType() == Uml::lvt_UseCase
		     || data->getType() == Uml::lvt_UseCase_Diagram)
		    && (type == Uml::lvt_UseCase_Folder || type == Uml::lvt_UseCase_View) ) {
			continue;
		}
		if( (data->getType() == Uml::lvt_Component || data->getType() == Uml::lvt_Artifact
		     || data->getType() == Uml::lvt_Component_Diagram)
		    && (type == Uml::lvt_Component_Folder) ) {
			continue;
		}
		if( (data->getType() == Uml::lvt_Node ||
		     data->getType() == Uml::lvt_Deployment_Diagram)
		    && type == Uml::lvt_Deployment_Folder ) {
			continue;
		}
		accept = false;
	}

	return accept;
}

void UMLListView::slotDropped(QDropEvent * de, QListViewItem * parent, QListViewItem * item) {
	UMLListViewItem * move;
	parent = 0;//done just to stop compiler warning
	if(!item)

		return;
	UMLListViewItemDataList list;
	bool status = UMLDrag::decodeClip3(de, list);

	if(!status) {
		return;
	}
	UMLListViewItemDataListIt it(list);
	UMLListViewItemData* data = 0;
	Uml::ListView_Type type = Uml::lvt_Unknown;
	UMLView * v = 0;
	UMLObject * o =0;
	while((data =  it.current()) != 0) {
		++it;
		if( typeIsDiagram(data->getType()) ) {
			v = doc -> findView(data->getID());
			move = findView(v);
			if(!move)
				continue;
		} else {
			o = doc -> findUMLObject(data->getID());
			move = findUMLObject(o);
			if(!move)
				continue;
		}
		type = ((UMLListViewItem*)item)  -> getType();
		//make sure trying to place in correct location

		if( (data->getType() == Uml::lvt_UseCase_Folder
		     || data->getType() == Uml::lvt_Actor
		     || data->getType() == Uml::lvt_UseCase
		     || data->getType() == Uml::lvt_UseCase_Diagram)
		    && (type == Uml::lvt_UseCase_Folder || type == Uml::lvt_UseCase_View) ) {
			moveItem(move, item, item);
		}
		if( (data->getType() == Uml::lvt_Component_Folder
		     || data->getType() == Uml::lvt_Component
		     || data->getType() == Uml::lvt_Artifact
		     || data->getType() == Uml::lvt_Component_Diagram)
		    && (type == Uml::lvt_Component_Folder || type == Uml::lvt_Component_View) ) {
			moveItem(move, item, item);
		}
		if( (data->getType() == Uml::lvt_Deployment_Folder
		     || data->getType() == Uml::lvt_Node
		     || data->getType() == Uml::lvt_Deployment_Diagram)
		    && (type == Uml::lvt_Deployment_Folder || type == Uml::lvt_Deployment_View) ) {
			moveItem(move, item, item);
		}
		if( ((data->getType() >= Uml::lvt_Collaboration_Diagram
		      && data->getType() <= Uml::lvt_Sequence_Diagram)
		     || data->getType() == Uml::lvt_Class
		     || data->getType() == Uml::lvt_Package
		     || data->getType() == Uml::lvt_Interface)
		    && (type == Uml::lvt_Logical_Folder || type == Uml::lvt_Logical_View)) {
			moveItem(move, item, item);
		}
	}
}

/* Reads a UMLListView from a QDataStream, this implementation allows the posibiliy to have folders
inside folders and it is closely tied to the behavior of a QListViewItemIterator, in QT's documentation
it says this iterator performs a preorder reading of the tree and this function uses this fact */
bool UMLListView::serialize(QDataStream *s, bool archive, int fileversion) {
	if(archive) {
		UMLListViewItem *temp;
		QListViewItemIterator it( this );
		//For the root item save only its child count.
		temp = (UMLListViewItem*)it.current();
		*s << temp->childCount();
		++it;
		for( ; (temp = (UMLListViewItem*)it.current()); ++it ) {
			temp->getdata()->serialize(s, archive, fileversion);
		}
	} else {
		deleteChildrenOf( ucv );
		deleteChildrenOf( lv );
		deleteChildrenOf( componentView );
		deleteChildrenOf( deploymentView );
		deleteChildrenOf( diagramFolder );

		int id, childs =0, rootchilds =0;
		Uml::ListView_Type type = Uml::lvt_Unknown;
		QString text;
		int 	t, open, useFolder;
		*s >> rootchilds;

		for(int i =0; i < rootchilds ; i++) {
			*s >> id
			>> t
			>> text;
			if (fileversion > 4)
			{
				*s >> childs
				>> open;
				type = (Uml::ListView_Type)t;
				switch( type) {
					case Uml::lvt_UseCase_View:
						ucv -> setOpen( (bool)open );
						for(int i =0; i < childs ; i++) {
							if( !ReadChilds( ucv, s ) ) {
								return false;
							}
						}
						break;
					case Uml::lvt_Logical_View:
						lv -> setOpen( (bool)open );
						for(int i =0; i < childs ; i++) {
							if( !ReadChilds( lv, s ) ) {
								return false;
							}
						}
						break;
					default:
						return false;
						break;
				}//end switch
			}
			else
			{
				UMLListViewItem         *folder = 0,
							*item = 0,
							*prev = 0;
				ucv -> setOpen( (bool)open );
				lv -> setOpen( (bool)open );
				UMLObject       *o = 0;

				*s >> useFolder;
				if ( t < /* UCVIEW */ 3 )
					continue;
				switch( t ) {
					case /* LFOLDER */ 609 :
						folder = new UMLListViewItem(lv, text, Uml::lvt_Logical_Folder);
						break;
					case /* UCFOLDER */ 608 :
						folder = new UMLListViewItem(lv, text, Uml::lvt_UseCase_Folder);
						break;
					case /* UCDIAGRAM */ 300 :
						if( !useFolder || !folder) {
							item = new UMLListViewItem(ucv, text, Uml::lvt_UseCase_Diagram, id);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_UseCase_Diagram, id);
						createDiagram(item, Uml::dt_UseCase);
						break;
					case /* COLLDIAGRAM */ 301 :
						if ( !useFolder || !folder) {
							item = new UMLListViewItem(lv, text, Uml::lvt_Collaboration_Diagram, id);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_Collaboration_Diagram, id);
						createDiagram(item, Uml::dt_Collaboration);
						break;
					case /* CONDIAGRAM */ 302 :
						if ( !useFolder || !folder) {
							item = new UMLListViewItem(lv, text, Uml::lvt_Class_Diagram, id);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_Class_Diagram, id);
						createDiagram(item, Uml::dt_Class);
						break;
					case /* SEQDIAGRAM */ 303 :
						if ( !useFolder || !folder) {
							item = new UMLListViewItem(lv, text, Uml::lvt_Sequence_Diagram, id);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_Sequence_Diagram, id);
						createDiagram(item, Uml::dt_Sequence);
						break;
						//FIXME what about the other diagram types?
					case /* ACTOR */ 100 :
						o = doc->findUMLObject(id);
						if ( !useFolder || !folder) {
							item = new UMLListViewItem(ucv, text, Uml::lvt_Actor, o);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_Actor, o);
						break;
					case /* USECASE */ 101 :
						o = doc->findUMLObject(id);
						if ( !useFolder || !folder) {
							item = new UMLListViewItem(ucv, text, Uml::lvt_UseCase, o);
							folder = 0;
						}
						else
							item = new UMLListViewItem(folder, text, Uml::lvt_UseCase, o);
						break;
					case /* CONCEPT...err thats "CLASS" now */ 102 :
						o = doc->findUMLObject(id);
						if ( !useFolder || !folder) {
							prev = new UMLListViewItem(lv, text, Uml::lvt_Class, o);
							folder = 0;
						}
						else
							prev = new UMLListViewItem(folder, text, Uml::lvt_Class, o);
						break;
					case /* ATTRIBUTE */ 400 :
						item = new UMLListViewItem(prev, text, Uml::lvt_Attribute, ((UMLClass*)o)->findChildObject(id));
						break;
					case /* OPERATION */ 401 :
						item = new UMLListViewItem(prev, text, Uml::lvt_Operation, ((UMLClassifier *)o)->findChildObject(id));
						break;
					default:
						continue;
						break;
				}//end switch
			}
		}//end for
	}//end else
	return true;
}

bool UMLListView::ReadChilds( UMLListViewItem* parent, QDataStream *s) {
	int id, childs;
	Uml::ListView_Type type = Uml::lvt_Unknown;
	int t, open;
	QString text;

	UMLListViewItem * item;
	UMLObject * o;

	*s >> id
	>> t
	>> text
	>> childs
	>> open;
	type = (Uml::ListView_Type)t;
	if ( typeIsCanvasWidget(type) ) {
		o = doc -> findUMLObject(id);
		item = new UMLListViewItem(parent, text, type, o);
	} else if( typeIsClassifierList(type) ) {
		item = new UMLListViewItem(parent, text, type, ((UMLClassifier*)parent->getUMLObject())->findChildObject(id));
	} else {
		item = new UMLListViewItem(parent, text, type, id);
	}
	item -> setOpen( (bool)open );
	for(int i = 0; i < childs ; i++) {
		if(!ReadChilds(item, s)) {
			return false;
		}
	}

	return true;
}
/** No descriptions */
bool UMLListView::getSelectedItems(UMLListViewItemList &ItemList) {
	ItemList.setAutoDelete( FALSE );
	QListViewItemIterator it(this);
	// iterate through all items of the list view
	for ( ; it.current(); ++it ) {
		if ( it.current()->isSelected() ) {
			ItemList.append((UMLListViewItem*)it.current());
		}
	}

	return true;
}
/** Returns the amount of bytes needed to serialize Item to the clipboard*/
long UMLListView::getClipSizeOfItemList(UMLListViewItemList* Items)
{
	if(!Items) {
		return 0;
	}
	long l_size = sizeof(Items->count());
	UMLListViewItemListIt item_it( *Items );
	UMLListViewItem * item;
	QString name;

	while ( ( item=item_it.current()) != 0 ) {
		++item_it;
		l_size += item->getdata()->getClipSizeOf();
	}

	return l_size;
}

/** Serialize an instance of this class to a QDataStream that will be put in the clipboard */
bool UMLListView::clipSerializeItemList(UMLListViewItemList* Items, QDataStream *s, const bool toClip) {
	UMLListViewItem * item = 0;
	if(toClip) {
		if(!Items) {
			return false;
		}
		*s << Items->count();
		UMLListViewItemListIt item_it( *Items );
		while ( ( item=item_it.current()) != 0 ) {
			++item_it;
			item->getdata()->clipSerialize(s, toClip);
		}
	} else {
		uint count =0;
		UMLObject * o;
		*s >> count;
		UMLListViewItemData data;
		for(uint i=0; i < count; i++) {
			data.clipSerialize(s, toClip);
			switch( data.getType() ) {
				case Uml::lvt_Actor:
				case Uml::lvt_UseCase:
					o = doc -> findUMLObject(data.getID());
					item = new UMLListViewItem(ucv, data.text(0), data.getType(), o);
					break;
				case Uml::lvt_Class:
					o = doc -> findUMLObject(data.getID());
					item = new UMLListViewItem(lv, data.text(0), data.getType(), o);
					break;
					/*case Uml::ot_Attribute:
					case Uml::ot_Operation:
						item = new UMLListViewItem(parent, text, type, ((UMLClass*)parent->getUMLObject())->findChildObject(id));
					break;*/
				case Uml::lvt_Logical_Folder:
					item = new UMLListViewItem(lv, data.text(0), data.getType());
					break;
				case Uml::lvt_UseCase_Folder:
					item = new UMLListViewItem(ucv, data.text(0), data.getType());
					break;
				default:
					break;
			}
			Items->append(item);
			/*for(uint j = 0; j < childs; j++)
			{
				if(!ReadClipChildren(item, s, i, Items))
				{
					return false;
				}
			}*/
		}
	}

	return true;
}
/** Reads the children of a UMLListViewItem from a QDataStream
representing the clipboard */
/*bool UMLListView::ReadClipChildren(UMLListViewItem* parent, QDataStream* s, uint& Count,
																																			UMLListViewItemList* Items)
{
	UMLListViewItem * item;
	UMLListViewItemData data;
	UMLObject* o;

	data.clipSerialize(s, false);
	switch(data.getType())
	{
 		case Uml::ot_Actor:
 		case Uml::ot_UseCase:
		case Uml::ot_Class:
 			o = doc -> findUMLObject(data.getID());
 			item = new UMLListViewItem(parent, data.text(0), data.getType(), o);
 		break;
 		//case Uml::ot_Attribute:
 		//	item = new UMLListViewItem(parent, text, type, ((UMLClass*)parent->getUMLObject())->findChildObject(id));
 		//break;
 		//case Uml::ot_Operation:
 		//	item = new UMLListViewItem(parent, text, type, ((UMLClassifier*)parent->getUMLObject())->findChildObject(id));
 		//break;
 		default:
 			item = new UMLListViewItem(parent, data.text(0), data.getType());
 		break;
 	}
	Items->append(item);
	Count++; //Increases the number of readed items from the QDataStream
 	for(int j = 0; j < data.childCount(); j++)
 	{
 		if(!ReadClipChildren(item, s, Count, Items))
 		{
 			return false;
 		}
 	}

	return true;
}*/

/** Creates a new UMLListViewItem from a UMLListViewItemData,
if parent is null the ListView Decides who is going to be
the parent */
UMLListViewItem* UMLListView::createItem(UMLListViewItemData& Data, IDChangeLog& IDChanges,
                                       UMLListViewItem* parent /*= 0*/) {
	UMLObject* o = 0;
	UMLView *v = 0;
	UMLListViewItem* item = 0;
	if(!parent) {
		if(Data.getType() == Uml::lvt_Actor || Data.getType() == Uml::lvt_UseCase || Data.getType() == Uml::lvt_UseCase_Folder || Data.getType() == Uml::lvt_UseCase_Diagram) {
			parent = ucv;
		} else if ( Data.getType() == Uml::lvt_Component_Diagram ||
			    Data.getType() == Uml::lvt_Component ||
			    Data.getType() == Uml::lvt_Artifact) {
			parent = componentView;
		} else if ( Data.getType() == Uml::lvt_Deployment_Diagram ||
			    Data.getType() == Uml::lvt_Node) {
			parent = deploymentView;
		} else if( typeIsDiagram(Data.getType()) ) {
			parent = lv;
		} else if(Data.getType() != Uml::lvt_Attribute && Data.getType() != Uml::lvt_Operation) {
			parent = lv;
		} else {
			return 0;
		}
	}
	int newID;
	UMLObject * pObject = 0;

	switch(Data.getType()) {
		case Uml::lvt_Actor:
		case Uml::lvt_UseCase:
		case Uml::lvt_Class:
		case Uml::lvt_Package:
		case Uml::lvt_Component:
		case Uml::lvt_Node:
		case Uml::lvt_Artifact:
		case Uml::lvt_Interface:
			newID = IDChanges.findNewID(Data.getID());
			//if there is no ListViewItem associated with the new ID,
			//it could exist an Item already asocciated if the user chose to reuse an uml object
			if(!(item = findItem(newID))) {
				o = doc->findUMLObject( IDChanges.findNewID(Data.getID()) );
				item = new UMLListViewItem(parent, Data.getLabel(), Data.getType(), o);
			}
			break;
		case Uml::lvt_Logical_Folder:
		case Uml::lvt_UseCase_Folder:
		case Uml::lvt_Component_Folder:
		case Uml::lvt_Deployment_Folder:
			item = new UMLListViewItem(parent, Data.getLabel(), Data.getType());
			break;
		case Uml::lvt_Attribute:
		{
			UMLClass * pClass =  (UMLClass *)parent -> getUMLObject();
			newID = IDChanges.findNewID( Data.getID() );
			pObject = pClass -> findChildObject( newID );
			if (pObject) {
				item = new UMLListViewItem( parent, Data.getLabel(), Data.getType(), pObject );
			} else {
				item = 0;
			}
			break;
		}
		case Uml::lvt_Operation:
		{
			UMLClassifier * pConcept =  (UMLClassifier *)parent -> getUMLObject();
			pObject = pConcept  -> findChildObject( IDChanges.findNewID( Data.getID() ) );
			if (pObject) {
				item = new UMLListViewItem( parent, Data.getLabel(), Data.getType(), pObject );
			} else {
				item = 0;
			}
			break;
		}
		case Uml::lvt_UseCase_Diagram:
		case Uml::lvt_Sequence_Diagram:
		case Uml::lvt_Collaboration_Diagram:
		case Uml::lvt_Class_Diagram:
		case Uml::lvt_State_Diagram:
		case Uml::lvt_Activity_Diagram:
		case Uml::lvt_Component_Diagram:
		case Uml::lvt_Deployment_Diagram:
			v = doc->findView(IDChanges.findNewID(Data.getID()));
			if(!v) {
				return 0;
			}
			item = new UMLListViewItem(parent, v->getName(), convert_DT_LVT( v->getType() ),  IDChanges.findNewID(Data.getID()));
			break;
		default:
			break;
	}
	return item;
}

int UMLListView::getSelectedCount() {
	QListViewItemIterator it(this);
	int count = 0;
	// iterate through all items of the list view
	for ( ; it.current(); ++it ) {
		if ( it.current()->isSelected() ) {
			count++;
		}
	}

	return count;
}

void UMLListView::focusOutEvent ( QFocusEvent * fe) {
	clearSelection();
	triggerUpdate();
	//repaint();

	QListView::focusOutEvent(fe);
}

Uml::ListView_Type UMLListView::convert_DT_LVT(Uml::Diagram_Type dt) {
	Uml::ListView_Type type =  Uml::lvt_Unknown;
	switch(dt) {
		case Uml::dt_UseCase:
			type = Uml::lvt_UseCase_Diagram;
			break;

		case Uml::dt_Class:
			type = Uml::lvt_Class_Diagram;
			break;

		case Uml::dt_Sequence:
			type = Uml::lvt_Sequence_Diagram;
			break;

		case Uml::dt_Collaboration:
			type = Uml::lvt_Collaboration_Diagram;
			break;

		case Uml::dt_State:
			type = Uml::lvt_State_Diagram;
			break;

		case Uml::dt_Activity:
			type = Uml::lvt_Activity_Diagram;
			break;

		case Uml::dt_Component:
			type = Uml::lvt_Component_Diagram;
			break;

		case Uml::dt_Deployment:
			type = Uml::lvt_Deployment_Diagram;
			break;

		default:
			kdWarning() << "convert_DT_LVT() called on unknown diagram type" << endl;
			break;
	}
	return type;
}

Uml::ListView_Type UMLListView::convert_OT_LVT(Uml::UMLObject_Type ot) {
	Uml::ListView_Type type =  Uml::lvt_Unknown;
	switch(ot) {
		case Uml::ot_UseCase:
			type = Uml::lvt_UseCase;
			break;

		case Uml::ot_Actor:
			type = Uml::lvt_Actor;
			break;

		case Uml::ot_Class:
			type = Uml::lvt_Class;
			break;

		case Uml::ot_Package:
			type = Uml::lvt_Package;
			break;

		case Uml::ot_Component:
			type = Uml::lvt_Component;
			break;

		case Uml::ot_Node:
			type = Uml::lvt_Node;
			break;

		case Uml::ot_Artifact:
			type = Uml::lvt_Artifact;
			break;

		case Uml::ot_Interface:
			type = Uml::lvt_Interface;
			break;

		case Uml::ot_Attribute:
			type = Uml::lvt_Attribute;
			break;

		case Uml::ot_Operation:
			type = Uml::lvt_Operation;
			break;

		case Uml::ot_Template:
			type = Uml::lvt_Template;
			break;
		default:
			break;
	}
	return type;
}

QPixmap & UMLListView::getPixmap( Icon_Type type ) {
	switch( type ) {
		case it_Home:
			return m_Pixmaps.Home;
			break;

		case it_Folder_Green:
			return m_Pixmaps.Folder_Green;
			break;

		case it_Folder_Green_Open:
			return m_Pixmaps.Folder_Green_Open;
			break;

		case it_Folder_Grey:
			return m_Pixmaps.Folder_Grey;
			break;

		case it_Folder_Grey_Open:
			return m_Pixmaps.Folder_Grey_Open;
			break;

		case it_Folder_Red:
			return m_Pixmaps.Folder_Red;
			break;

		case it_Folder_Red_Open:
			return m_Pixmaps.Folder_Red_Open;
			break;

		case it_Folder_Violet:
			return m_Pixmaps.Folder_Violet;
			break;

		case it_Folder_Violet_Open:
			return m_Pixmaps.Folder_Violet_Open;
			break;

		case it_Diagram:
			return m_Pixmaps.Diagram;
			break;

		case it_Class:
			return m_Pixmaps.Class;
			break;

		case it_Template:
			return m_Pixmaps.Template;
			break;

		case it_Package:
			return m_Pixmaps.Package;
			break;

		case it_Component:
			return m_Pixmaps.Component;
			break;

		case it_Node:
			return m_Pixmaps.Node;
			break;

		case it_Artifact:
			return m_Pixmaps.Artifact;
			break;

		case it_Interface:
			return m_Pixmaps.Interface;
			break;

		case it_Actor:
			return m_Pixmaps.Actor;
			break;

		case it_UseCase:
			return m_Pixmaps.UseCase;
			break;

		case it_Public_Method:
			return m_Pixmaps.Public_Method;
			break;

		case it_Private_Method:
			return m_Pixmaps.Private_Method;
			break;

		case it_Protected_Method:
			return m_Pixmaps.Protected_Method;
			break;

		case it_Public_Attribute:
			return m_Pixmaps.Public_Attribute;
			break;

		case it_Private_Attribute:
			return m_Pixmaps.Private_Attribute;
			break;

		case it_Protected_Attribute:
			return m_Pixmaps.Protected_Attribute;
			break;

		default:
			kdWarning() << "getPixmap() called on unknown icon" << endl;
			break;
	}//end switch
	return m_Pixmaps.Home;//you'll know you have a problem if this shows up in the list!!
}

void UMLListView::loadPixmaps() {
	KStandardDirs * dirs = KGlobal::dirs();
	QString dataDir = dirs -> findResourceDir("data", "umbrello/pics/object.xpm");
	dataDir += "/umbrello/pics/";

	m_Pixmaps.Home = SmallIcon("folder_home");
	m_Pixmaps.Folder_Green = SmallIcon("folder_green");
	m_Pixmaps.Folder_Green_Open = SmallIcon("folder_green_open");
	m_Pixmaps.Folder_Grey = SmallIcon("folder_grey");
	m_Pixmaps.Folder_Grey_Open = SmallIcon("folder_grey_open");
	m_Pixmaps.Folder_Red = SmallIcon("folder_red");
	m_Pixmaps.Folder_Red_Open = SmallIcon("folder_red_open");
	m_Pixmaps.Folder_Violet = SmallIcon("folder_violet");
	m_Pixmaps.Folder_Violet_Open = SmallIcon("folder_violet_open");

	m_Pixmaps.Diagram.load( dataDir + "CVnamespace.png" ); //change to have different one for each type of diagram
	m_Pixmaps.Class.load( dataDir + "umlclass.xpm" );
	m_Pixmaps.Template.load( dataDir + "umlclass_template.xpm" );
	m_Pixmaps.Package.load( dataDir + "package.xpm" );
	m_Pixmaps.Component.load( dataDir + "component.xpm" );
	m_Pixmaps.Node.load( dataDir + "node.xpm" );
	m_Pixmaps.Artifact.load( dataDir + "artifact.xpm" );
	m_Pixmaps.Interface.load( dataDir + "interface.xpm" );
	m_Pixmaps.Actor.load( dataDir + "actor.xpm" );
	m_Pixmaps.UseCase.load( dataDir + "case.xpm" );
	m_Pixmaps.Public_Method.load( dataDir + "CVpublic_meth.png" );
	m_Pixmaps.Private_Method.load( dataDir + "CVprivate_meth.png" );
	m_Pixmaps.Protected_Method.load( dataDir + "CVprotected_meth.png" );
	m_Pixmaps.Public_Attribute.load( dataDir + "CVpublic_var.png" );
	m_Pixmaps.Private_Attribute.load( dataDir + "CVprivate_var.png" );
	m_Pixmaps.Protected_Attribute.load( dataDir + "CVprotected_var.png" );
}

void UMLListView::slotExpanded( QListViewItem * item ) {
	UMLListViewItem * myItem= (UMLListViewItem *)item;
	switch( myItem -> getType() ) {
		case Uml::lvt_Logical_View:
		case Uml::lvt_UseCase_View:
		case Uml::lvt_Component_View:
		case Uml::lvt_Deployment_View:
		case Uml::lvt_Logical_Folder:
		case Uml::lvt_UseCase_Folder:
		case Uml::lvt_Component_Folder:
		case Uml::lvt_Deployment_Folder:
			myItem->updateFolder();
			break;
		default:
			break;
	}//end switch
}

void UMLListView::slotCollapsed( QListViewItem * item ) {
	UMLListViewItem * myItem = (UMLListViewItem *)item;
	switch( myItem -> getType() ) {
		case Uml::lvt_Logical_View:
		case Uml::lvt_UseCase_View:
		case Uml::lvt_Component_View:
		case Uml::lvt_Deployment_View:
		case Uml::lvt_Logical_Folder:
		case Uml::lvt_UseCase_Folder:
		case Uml::lvt_Component_Folder:
		case Uml::lvt_Deployment_Folder:
			myItem -> updateFolder();
			break;
		default:
			break;
	}//end switch
}

void UMLListView::slotCutSuccessful() {
	if( m_bStartedCut ) {
		popupMenuSel( ListPopupMenu::mt_Delete );
		//deletion code here
		m_bStartedCut = false;
	}
}

void UMLListView::addNewItem( QListViewItem * parent, Uml::ListView_Type type ) {
	QString name = i18n("folder");
	UMLListViewItem * newItem = static_cast<UMLListViewItem *>( parent );//used for att/ops - rest overwrite
	parent -> setOpen( true );
	switch( type ) {
		case Uml::lvt_UseCase_Folder:
		case Uml::lvt_Logical_Folder:
		case Uml::lvt_Component_Folder:
		case Uml::lvt_Deployment_Folder:
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_Actor:
			name = getUniqueUMLObjectName( Uml::ot_Actor );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem -> setPixmap( 0, getPixmap( it_Actor ) );
			break;

		case Uml::lvt_Class:
			name = getUniqueUMLObjectName( Uml::ot_Class);
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem -> setPixmap( 0, getPixmap( it_Class ) );
			break;

		case Uml::lvt_Package:
			name = getUniqueUMLObjectName( Uml::ot_Package );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem->setPixmap( 0, getPixmap( it_Package ) );
			break;

		case Uml::lvt_Component:
			name = getUniqueUMLObjectName( Uml::ot_Component );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem->setPixmap( 0, getPixmap( it_Component ) );
			break;

		case Uml::lvt_Node:
			name = getUniqueUMLObjectName( Uml::ot_Node );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem->setPixmap( 0, getPixmap( it_Node ) );
			break;

		case Uml::lvt_Artifact:
			name = getUniqueUMLObjectName( Uml::ot_Artifact );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem->setPixmap( 0, getPixmap( it_Artifact ) );
			break;

		case Uml::lvt_Interface:
			name = getUniqueUMLObjectName( Uml::ot_Interface );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem*>(parent), name, type, (UMLObject*)0 );
			newItem->setPixmap( 0, getPixmap( it_Interface ) );
			break;

		case Uml::lvt_Attribute:
		{
			UMLClass * childParent = static_cast<UMLClass*>( newItem -> getdata() -> getUMLObject() );
			name = getUniqueChildUMLObjectName( childParent, Uml::ot_Attribute );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem -> setPixmap( 0, getPixmap( it_Public_Attribute ) );
			break;
		}
		case Uml::lvt_Operation:
		{
			UMLClassifier * childParent = static_cast<UMLClassifier *>( newItem -> getdata() -> getUMLObject() );
			name = getUniqueChildUMLObjectName( childParent, Uml::ot_Operation );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem -> setPixmap( 0, getPixmap( it_Public_Method ) );
			break;
		}
		case Uml::lvt_UseCase:
			name = getUniqueUMLObjectName( Uml::ot_UseCase );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, (UMLObject *)0 );
			newItem -> setPixmap( 0, getPixmap( it_UseCase ) );
			break;

		case Uml::lvt_Class_Diagram:
			name = getUniqueDiagramName( Uml::dt_Class );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_UseCase_Diagram:
			name = getUniqueDiagramName( Uml::dt_UseCase );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_Sequence_Diagram:
			name = getUniqueDiagramName( Uml::dt_Sequence );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_Collaboration_Diagram:
			name = getUniqueDiagramName( Uml::dt_Collaboration );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_State_Diagram:
			name = getUniqueDiagramName( Uml::dt_State );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;
		case Uml::lvt_Activity_Diagram:
			name = getUniqueDiagramName( Uml::dt_Activity );
			newItem = new UMLListViewItem( static_cast<UMLListViewItem *>( parent ), name, type, -1 );
			break;

		case Uml::lvt_Component_Diagram:
			name = getUniqueDiagramName(Uml::dt_Component);
			newItem = new UMLListViewItem(static_cast<UMLListViewItem*>(parent), name, type, -1);
			break;

		case Uml::lvt_Deployment_Diagram:
			name = getUniqueDiagramName(Uml::dt_Deployment);
			newItem = new UMLListViewItem(static_cast<UMLListViewItem*>(parent), name, type, -1);
			break;
		default:
			break;
	}
	m_bIgnoreCancelRename = false;
	ensureItemVisible(newItem);
	newItem->setOpen( true );
	newItem->setCreating( true );
	newItem->startRename( 0 );
}

bool UMLListView::slotItemRenamed( QListViewItem * item , int /*col*/ ) {
	//if true the item was cancel before this message
	if( m_bIgnoreCancelRename ) {
		return true;
	}
	m_bIgnoreCancelRename = true;
	UMLListViewItem * renamedItem = static_cast< UMLListViewItem *>( item ) ;
	Uml::ListView_Type type = renamedItem -> getType();
	QString newText = renamedItem -> text( 0 );
	renamedItem -> setCreating( false );

	//if the length of any type then delete it.
	if( newText.length() == 0 ) {
		KMessageBox::error( kapp -> mainWidget() , i18n( "The name you entered was invalid!\nCreation process has been cancelled" ),
		                    i18n( "Name Not Valid" ) );
		delete item;
		return false;
	}
	// No need to do anything for folders if the string length was > 0
	if( typeIsFolder(type) ) {
		return true;
	}

	if( !isUnique( renamedItem, newText ) ) {
		//if operation ask if ok not to be unique i.e overloading
		if( type == Uml::lvt_Operation ) {
			if( KMessageBox::warningYesNo( kapp -> mainWidget() , i18n( "The name you entered was not unique!\nIs this what you wanted?" ),
			                               i18n( "Name Not Unique" ) ) == KMessageBox::No ) {
				delete item;
				return false;
			}
		} else {
			KMessageBox::error( kapp -> mainWidget() , i18n( "The name you entered was not unique!\nCreation process has been cancelled" ),
			                    i18n( "Name Not Unique" ) );
			delete item;
			return false;
		}
	}

	switch( type ) {
		case Uml::lvt_Actor:
			createUMLObject( renamedItem, Uml::ot_Actor );
			break;

		case Uml::lvt_Class:
			createUMLObject( renamedItem, Uml::ot_Class);
			break;

		case Uml::lvt_Package:
			createUMLObject( renamedItem, Uml::ot_Package );
			break;

		case Uml::lvt_Component:
			createUMLObject(renamedItem, Uml::ot_Component);
			break;

		case Uml::lvt_Node:
			createUMLObject(renamedItem, Uml::ot_Node);
			break;

		case Uml::lvt_Artifact:
			createUMLObject(renamedItem, Uml::ot_Artifact);
			break;

		case Uml::lvt_Interface:
			createUMLObject( renamedItem, Uml::ot_Interface );
			break;

		case Uml::lvt_UseCase:
			createUMLObject( renamedItem, Uml::ot_UseCase );
			break;

		case Uml::lvt_Attribute:
			createChildUMLObject( renamedItem, Uml::ot_Attribute );
			break;

		case Uml::lvt_Operation:
			createChildUMLObject( renamedItem, Uml::ot_Operation );
			break;

		case Uml::lvt_Class_Diagram:
			createDiagram( renamedItem, Uml::dt_Class );
			break;

		case Uml::lvt_UseCase_Diagram:
			createDiagram( renamedItem, Uml::dt_UseCase );
			break;

		case Uml::lvt_Sequence_Diagram:
			createDiagram( renamedItem, Uml::dt_Sequence );
			break;

		case Uml::lvt_Collaboration_Diagram:
			createDiagram( renamedItem, Uml::dt_Collaboration );
			break;

		case Uml::lvt_State_Diagram:
			createDiagram( renamedItem, Uml::dt_State );
			break;

		case Uml::lvt_Activity_Diagram:
			createDiagram( renamedItem, Uml::dt_Activity );
			break;

		case Uml::lvt_Component_Diagram:
			createDiagram( renamedItem, Uml::dt_Component );
			break;

		case Uml::lvt_Deployment_Diagram:
			createDiagram( renamedItem, Uml::dt_Deployment );
			break;

		default:
			break;

	}
	return true;
}

void UMLListView::createUMLObject( UMLListViewItem * item, Uml::UMLObject_Type type ) {
	QString name = item -> text( 0 );
	UMLObject * object = doc -> findUMLObject( type, name );
	if( object ) {
		delete item;
		return;
	}
	switch( type ) {
		case Uml::ot_UseCase:
			object = new UMLUseCase( doc, name, doc -> getUniqueID() );
			break;

		case Uml::ot_Actor:
			object = new UMLActor( doc, name, doc -> getUniqueID() );
			break;

		case Uml::ot_Class:
			object = new UMLClass( doc, name, doc -> getUniqueID() );
			break;

		case Uml::ot_Package:
			object = new UMLPackage( doc, name, doc->getUniqueID() );
			break;

		case Uml::ot_Component:
			object = new UMLComponent( doc, name, doc->getUniqueID() );
			break;

		case Uml::ot_Node:
			object = new UMLNode( doc, name, doc->getUniqueID() );
			break;

		case Uml::ot_Artifact:
			object = new UMLArtifact( doc, name, doc->getUniqueID() );
			break;

		case Uml::ot_Interface:
			object = new UMLInterface( doc, name, doc->getUniqueID() );
			break;
		default:
			kdWarning() << "createing UML Object of unknown type" << endl;
			break;
	}
	doc -> addUMLObject( object );
	UMLListViewItemData * pData = item -> getdata();
	pData -> setUMLObject( object );
	pData -> setID( object -> getID() );
	pData -> setLabel( name );
}

void UMLListView::createChildUMLObject( UMLListViewItem * item, Uml::UMLObject_Type type ) {
	QString name = item -> text( 0 );
	UMLObject * object = static_cast<UMLListViewItem *>( item -> parent() ) -> getUMLObject();
	if( !object ) {
		delete item;
		return;
	}

	if( type == Uml::ot_Attribute )
	{
		UMLClass * parent = static_cast<UMLClass *>( object );
		object = parent -> addAttribute( name, doc -> getUniqueID() );
	}
	else
	{
		UMLClassifier * parent = static_cast<UMLClassifier *>( object );
		object = parent -> addOperation( name, doc -> getUniqueID() );
	}

	UMLListViewItemData * pData = item -> getdata();
	pData -> setUMLObject( object );
	pData -> setID( object -> getID() );
	pData -> setLabel( name );
	loading = true;
	doc -> signalChildUMLObjectCreated( object );
	loading = false;
}

void UMLListView::createDiagram( UMLListViewItem * item, Uml::Diagram_Type type ) {
	QString name = item -> text( 0 );
	UMLView * view = doc -> findView( type, name );
	if( view ) {
		delete item;
		return;
	}
	UMLViewData * pData = new UMLViewData();
	pData -> setName( name );
	pData -> setType( type );
	pData -> setID( doc -> getUniqueID() );
	view = new UMLView(doc->getUMLApp()->getMainDockWidget(), pData, doc);
	doc -> addView( view );
	view  -> setOptionState( ((UMLApp *) doc -> parent()) -> getOptionState() );
	UMLListViewItemData * data = item -> getdata();
	data -> setID( view -> getID() );
	data -> setLabel( name );
	view->activate();
	doc -> changeCurrentView( view -> getID() );
}

QString UMLListView::getUniqueUMLObjectName( Uml::UMLObject_Type type ) {
	QString temp = "";
	QString name = "";
	QString newClass = i18n("new_class");
	QString newPackage = i18n("new_package");
	QString newComponent = i18n("new_component");
	QString newNode = i18n("new_node");
	QString newArtifact = i18n("new_artifact");
	QString newInterface = i18n("new_interface");
	QString newActor = i18n("new_actor");
	QString newUseCase = i18n("new_usecase");

	UMLObject * object = 0;
	int count = 0;

	if (type == Uml::ot_Actor) {
		name = newActor;
	} else if (type == Uml::ot_UseCase) {
		name = newUseCase;
	} else if (type == Uml::ot_Class) {
		name = newClass;
	} else if (type == Uml::ot_Package) {
		name = newPackage;
	} else if (type == Uml::ot_Component) {
		name = newComponent;
	} else if (type == Uml::ot_Node) {
		name = newNode;
	} else if (type == Uml::ot_Artifact) {
		name = newArtifact;
	} else if (type == Uml::ot_Interface) {
		name = newInterface;
	} else {
		kdWarning() << "getting unique uml object name for unknown type" << endl;
	}

	do {
		temp = name;
		if( count > 0 )
			temp.append("_").append( QString::number( count ) );
		object = doc -> findUMLObject( type, temp );
		count++;
	} while( object );

	return temp;
}

QString UMLListView::getUniqueChildUMLObjectName( UMLClassifier * parent, Uml::UMLObject_Type type ) {
	QString name = "";
	QString temp = "";
	QString newAtt = i18n("new_attribute");
	QString newOp = i18n("new_operation");

	bool cont = true;
	int count = 0;

	if( type == Uml::ot_Attribute )
		name = newAtt;
	else
		name = newOp;

	do {
		temp = name;
		if( count > 0 )
			temp.append("_").append( QString::number( count ) );
		cont = parent -> findChildObject( type, temp ).count() != 0;
		count++;
	} while( cont );
	return temp;
}

QString UMLListView::getUniqueDiagramName(Uml::Diagram_Type type) {
	return doc->uniqViewName(type);
}

bool UMLListView::isUnique( UMLListViewItem * item, QString name ) {
	UMLListViewItem * parentItem = static_cast<UMLListViewItem *>( item -> parent() );
	Uml::ListView_Type type = item -> getType();
	switch( type ) {
		case Uml::lvt_Class_Diagram:
			return !doc -> findView( Uml::dt_Class, name );
			break;

		case Uml::lvt_Sequence_Diagram:
			return !doc -> findView( Uml::dt_Sequence, name );
			break;

		case Uml::lvt_UseCase_Diagram:
			return !doc -> findView( Uml::dt_UseCase, name );
			break;

		case Uml::lvt_Collaboration_Diagram:
			return !doc -> findView( Uml::dt_Collaboration, name );
			break;

		case Uml::lvt_State_Diagram:
			return !doc -> findView( Uml::dt_State, name );
			break;

		case Uml::lvt_Activity_Diagram:
			return !doc -> findView( Uml::dt_Activity, name );
			break;

		case Uml::lvt_Component_Diagram:
			return !doc->findView(Uml::dt_Component, name);
			break;

		case Uml::lvt_Deployment_Diagram:
			return !doc->findView(Uml::dt_Deployment, name);
			break;

		case Uml::lvt_Actor:
			return !doc -> findUMLObject( Uml::ot_Actor, name );
			break;

		case Uml::lvt_UseCase:
			return !doc -> findUMLObject( Uml::ot_UseCase, name );
			break;

		case Uml::lvt_Class:
			return !doc -> findUMLObject( Uml::ot_Class, name );
			break;

		case Uml::lvt_Package:
			return !doc->findUMLObject(Uml::ot_Package, name);
			break;

		case Uml::lvt_Component:
			return !doc->findUMLObject(Uml::ot_Component, name);
			break;

		case Uml::lvt_Node:
			return !doc->findUMLObject(Uml::ot_Node, name);
			break;

		case Uml::lvt_Artifact:
			return !doc->findUMLObject(Uml::ot_Artifact, name);
			break;

		case Uml::lvt_Interface:
			return !doc->findUMLObject(Uml::ot_Interface, name);
			break;

		case Uml::lvt_Attribute:
		{
			UMLClass * parent = static_cast<UMLClass *>( parentItem  -> getUMLObject() );
			return ( parent -> findChildObject( Uml::ot_Attribute, name ).count() == 0 );
			break;
		}
		case Uml::lvt_Operation:
		{
			UMLClassifier * parent = static_cast<UMLClassifier *>( parentItem  -> getUMLObject() );
			return ( parent -> findChildObject( Uml::ot_Operation, name ).count() == 0 );
			break;
		}
		default:
			break;
	}
	return false;
}

void UMLListView::cancelRename( QListViewItem * item ) {
	if( !m_bIgnoreCancelRename ) {
		delete item;
		m_bIgnoreCancelRename = true;
	}
}

bool UMLListView::saveToXMI( QDomDocument & qDoc, QDomElement & qElement ) {
	QDomElement listElement = qDoc.createElement( "listview" );
	bool status = rv -> getdata() -> saveToXMI( qDoc, listElement);
	qElement.appendChild( listElement );
	return status;
}

bool UMLListView::loadFromXMI( QDomElement & element ) {
	deleteChildrenOf( ucv );
	deleteChildrenOf( lv );
	deleteChildrenOf( componentView );
	deleteChildrenOf( deploymentView );
	deleteChildrenOf( diagramFolder );

	QDomNode node = element.firstChild();
	QDomElement domElement = node.toElement();
	while( !domElement.isNull() ) {
		if( domElement.tagName() == "listitem" ) {
			QString type = domElement.attribute( "type", "-1" );
			if( type == "-1" )
				return false;
			Uml::ListView_Type lvType = (Uml::ListView_Type)type.toInt();
			if( lvType == Uml::lvt_View ) {
				if( !loadChildrenFromXMI( rv, domElement ) )
					return false;
			} else
				return false;
		}
		node = node.nextSibling();
		domElement = node.toElement();

	}//end while
	return true;
}

bool UMLListView::loadChildrenFromXMI( UMLListViewItem * parent, QDomElement & element ) {
	QDomNode node = element.firstChild();
	QDomElement domElement = node.toElement();
	while( !domElement.isNull() ) {
		if( domElement.tagName() == "listitem" ) {
			QString id = domElement.attribute( "id", "-1" );
			QString type = domElement.attribute( "type", "-1" );
			QString label = domElement.attribute( "label", "" );
			QString open = domElement.attribute( "open", "1" );
			if( type == "-1" )
				return false;
			Uml::ListView_Type lvType = (Uml::ListView_Type)type.toInt();
			bool bOpen = (bool)open.toInt();
			int nID = id.toInt();
			UMLObject * pObject = 0;
			UMLListViewItem * item = 0;
			switch( lvType ) {
				case Uml::lvt_Actor:
				case Uml::lvt_UseCase:
				case Uml::lvt_Class:
				case Uml::lvt_Package:
				case Uml::lvt_Component:
				case Uml::lvt_Node:
				case Uml::lvt_Artifact:
				case Uml::lvt_Interface:
					pObject = doc->findUMLObject(nID);
					item = new UMLListViewItem(parent, label, lvType, pObject);
					break;
				case Uml::lvt_Attribute:
				case Uml::lvt_Template:
				{
					UMLObject* umlObject = parent->getUMLObject();
					if (!umlObject)
						return false;
					umlObject = static_cast<UMLClass *>(umlObject)->findChildObject(nID);
					item = new UMLListViewItem( parent, label, lvType, umlObject);
					break;
				}
				case Uml::lvt_Operation:
				{
					UMLObject* umlObject = parent->getUMLObject();
					if (!umlObject)
						return false;
					umlObject = static_cast<UMLClassifier*>(umlObject)->findChildObject(nID);
					item = new UMLListViewItem( parent, label, lvType, umlObject);
					break;
				}

				case Uml::lvt_Logical_View:
					item = lv;
					break;
				case Uml::lvt_UseCase_View:
					item = ucv;
					break;
				case Uml::lvt_Component_View:
					item = componentView;
					break;
				case Uml::lvt_Deployment_View:
					item = deploymentView;
					break;

				case Uml::lvt_Diagrams:
					item = diagramFolder;
					break;

				default:
					item = new UMLListViewItem( parent, label, lvType, nID );
					break;
			}//end switch
			item -> setOpen( (bool)bOpen );
			if( !loadChildrenFromXMI( item, domElement ) )
				return false;
		}//end if
		node = domElement.nextSibling();
		domElement = node.toElement();
	}//end while
	return true;
}

	/** Open all items in the list view*/
void UMLListView::expandAll(QListViewItem *item)
{
	if(!item) item = firstChild();
	for( item = item->firstChild(); item; item = item->nextSibling())
		item->setOpen(true);
}
	/** Close all items in the list view*/
void UMLListView::collapseAll(QListViewItem *item)
{
	if(!item) item = firstChild();
	for( item = item->firstChild(); item; item = item->nextSibling())
		item->setOpen(false);
}

void UMLListView::setStartedCut(bool startedCut) {
	m_bStartedCut = startedCut;
}

bool UMLListView::typeIsCanvasWidget(ListView_Type type) {
	if (type == lvt_Actor ||
	    type == lvt_UseCase ||
	    type == lvt_Class ||
	    type == lvt_Package ||
	    type == lvt_Component ||
	    type == lvt_Node ||
	    type == lvt_Artifact ||
	    type == lvt_Interface) {
		return true;
	} else {
		return false;
	}
}

bool UMLListView::typeIsFolder(ListView_Type type) {
	if (type == Uml::lvt_Logical_Folder ||
	    type == Uml::lvt_UseCase_Folder ||
	    type == Uml::lvt_Component_Folder ||
	    type == Uml::lvt_Deployment_Folder) {
		return true;
	} else {
		return false;
	}
}

bool UMLListView::typeIsClassifierList(ListView_Type type) {
	if (type == Uml::lvt_Attribute ||
	    type == Uml::lvt_Operation ||
	    type == Uml::lvt_Template) {
		return true;
	} else {
		return false;
	}
}

bool UMLListView::typeIsDiagram(ListView_Type type) {
	if (type == Uml::lvt_Class_Diagram ||
	    type == Uml::lvt_Collaboration_Diagram ||
	    type == Uml::lvt_State_Diagram ||
	    type == Uml::lvt_Activity_Diagram ||
	    type == Uml::lvt_Sequence_Diagram ||
	    type == Uml::lvt_UseCase_Diagram ||
	    type == Uml::lvt_Component_Diagram ||
	    type == Uml::lvt_Deployment_Diagram) {
		return true;
	} else {
		return false;
	}
}

void UMLListView::deleteChildrenOf( QListViewItem *parent )
{
    if ( !parent )
        return;

    while ( parent->firstChild() )
        delete parent->firstChild();
}

#include "umllistview.moc"
