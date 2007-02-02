/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2004-2006                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

// own header
#include "toolbarstatemessages.h"

// kde includes
#include <kdebug.h>

// local includes
#include "floatingtextwidget.h"
#include "messagewidget.h"
#include "objectwidget.h"
#include "uml.h"
#include "umldoc.h"
#include "umlview.h"

#include <klocale.h>
#include <kmessagebox.h>

ToolBarStateMessages::ToolBarStateMessages(UMLView *umlView) : ToolBarStatePool(umlView) {
    m_firstObject = 0;
    m_messageLine = 0;
    xclick = 0;
    yclick = 0;
}

ToolBarStateMessages::~ToolBarStateMessages() {
    delete m_messageLine;
}

void ToolBarStateMessages::init() {
    ToolBarStatePool::init();

    cleanMessage();
}

void ToolBarStateMessages::cleanBeforeChange() {
    ToolBarStatePool::cleanBeforeChange();

    cleanMessage();
}

void ToolBarStateMessages::mouseMove(QMouseEvent* ome) {
    ToolBarStatePool::mouseMove(ome);

    if (m_messageLine) {
        QPoint sp = m_messageLine->startPoint();
        m_messageLine->setPoints(sp.x(), sp.y(), m_pMouseEvent->x(), m_pMouseEvent->y());
    }
}

void ToolBarStateMessages::slotWidgetRemoved(UMLWidget* widget) {
    ToolBarState::slotWidgetRemoved(widget);

    if (widget == m_firstObject) {
        cleanMessage();
    }
}

void ToolBarStateMessages::setCurrentElement() {
    m_isObjectWidgetLine = false;

    ObjectWidget* objectWidgetLine = m_pUMLView->onWidgetLine(m_pMouseEvent->pos());
    if (objectWidgetLine) {
        setCurrentWidget(objectWidgetLine);
        m_isObjectWidgetLine = true;
        return;
    }

    //commit 515177 fixed a setting creation messages only working properly at 100% zoom
    //However, the applied patch doesn't seem to be necessary no more, so it was removed
    //The widgets weren't got from UMLView, but from a method in this class similarto the
    //one in UMLView but containing special code to handle the zoom
    UMLWidget *widget = m_pUMLView->testOnWidget(m_pMouseEvent->pos());
    if (widget) {
        setCurrentWidget(widget);
        return;
    }
}

void ToolBarStateMessages::mouseReleaseWidget() {
    //TODO When an association between UMLObjects of invalid types is made, an error message
    //is shown. Shouldn't also a message be used here?
    if (m_pMouseEvent->button() != Qt::LeftButton ||
                getCurrentWidget()->getBaseType() != Uml::wt_Object) {
        cleanMessage();
        return;
    }

    if (!m_isObjectWidgetLine && !m_firstObject) {
        return;
    }

    if (!m_isObjectWidgetLine) {
        setSecondWidget(static_cast<ObjectWidget*>(getCurrentWidget()), CreationMessage);
        return;
    }

    if (!m_firstObject) {
        setFirstWidget(static_cast<ObjectWidget*>(getCurrentWidget()));
    } else {
        setSecondWidget(static_cast<ObjectWidget*>(getCurrentWidget()), NormalMessage);
    }
}

void ToolBarStateMessages::mouseReleaseEmpty() {
    Uml::Sequence_Message_Type msgType = getMessageType();

    int y = m_pMouseEvent->y();

    if (m_firstObject && msgType ==  Uml::sequence_message_lost) {
	xclick = m_pMouseEvent->x();
	yclick = m_pMouseEvent->y();
	
	MessageWidget* message = new MessageWidget(m_pUMLView, m_firstObject,m_firstObject, y, msgType);
	message->setxclicked(xclick);
	message->setyclicked(yclick);
	cleanMessage();
 	m_pUMLView->getMessageList().append(message);

   	FloatingTextWidget *ft = message->getFloatingTextWidget();
    	//TODO cancel doesn't cancel the creation of the message, only cancels setting an operation.
    	//Shouldn't it cancel also the whole creation?
    	ft->showOpDlg();
    	message->setTextPosition();
    	m_pUMLView->getWidgetList().append(ft);

    	UMLApp::app()->getDocument()->setModified();
    }
    else if (!m_firstObject && msgType == Uml::sequence_message_found) {
	xclick = m_pMouseEvent->x();
	yclick = m_pMouseEvent->y();

	m_messageLine = new Q3CanvasLine(m_pUMLView->canvas());
    	m_messageLine->setPoints(m_pMouseEvent->x(), m_pMouseEvent->y(), m_pMouseEvent->x(), m_pMouseEvent->y());
    	m_messageLine->setPen(QPen(m_pUMLView->getLineColor(), m_pUMLView->getLineWidth(), Qt::DashLine));

    	m_messageLine->setVisible(true);

    	m_pUMLView->viewport()->setMouseTracking(true);
    }
    else
    	cleanMessage();
}

void ToolBarStateMessages::setFirstWidget(ObjectWidget* firstObject) {
    m_firstObject = firstObject;
    Uml::Sequence_Message_Type msgType = getMessageType();
    int y = m_pMouseEvent->y();
    if (msgType ==  Uml::sequence_message_found && xclick!=0 && yclick!=0) {
	MessageWidget* message = new MessageWidget(m_pUMLView, m_firstObject,m_firstObject, y, msgType);
	message->setxclicked(xclick);
	message->setyclicked(yclick);
	cleanMessage();
 	m_pUMLView->getMessageList().append(message);

   	FloatingTextWidget *ft = message->getFloatingTextWidget();
    	//TODO cancel doesn't cancel the creation of the message, only cancels setting an operation.
    	//Shouldn't it cancel also the whole creation?
    	ft->showOpDlg();
    	message->setTextPosition();
    	m_pUMLView->getWidgetList().append(ft);

    	UMLApp::app()->getDocument()->setModified();
    }
    else {
    	m_messageLine = new Q3CanvasLine(m_pUMLView->canvas());
    	m_messageLine->setPoints(m_pMouseEvent->x(), m_pMouseEvent->y(), m_pMouseEvent->x(), m_pMouseEvent->y());
    	m_messageLine->setPen(QPen(m_pUMLView->getLineColor(), m_pUMLView->getLineWidth(), Qt::DashLine));

    	m_messageLine->setVisible(true);

    	m_pUMLView->viewport()->setMouseTracking(true);
    }
}

void ToolBarStateMessages::setSecondWidget(ObjectWidget* secondObject, MessageType messageType) {
    Uml::Sequence_Message_Type msgType = getMessageType();

    //TODO shouldn't start position in the first widget be used also for normal messages
    //and not only for creation?
    int y = m_pMouseEvent->y();
    if (messageType == CreationMessage) {
        msgType = Uml::sequence_message_creation;
        y = m_messageLine->startPoint().y();
    }

    MessageWidget* message = new MessageWidget(m_pUMLView, m_firstObject,
                                               secondObject, y, msgType);

    cleanMessage();

    m_pUMLView->getMessageList().append(message);

    FloatingTextWidget *ft = message->getFloatingTextWidget();
    //TODO cancel doesn't cancel the creation of the message, only cancels setting an operation.
    //Shouldn't it cancel also the whole creation?
    ft->showOpDlg();
    message->setTextPosition();
    m_pUMLView->getWidgetList().append(ft);

    UMLApp::app()->getDocument()->setModified();
}

Uml::Sequence_Message_Type ToolBarStateMessages::getMessageType() {
    if (getButton() == WorkToolBar::tbb_Seq_Message_Synchronous) {
        return Uml::sequence_message_synchronous;
    }
    else if (getButton() == WorkToolBar::tbb_Seq_Message_Found) {
        return Uml::sequence_message_found;
    }
    else if (getButton() == WorkToolBar::tbb_Seq_Message_Lost) {
        return Uml::sequence_message_lost;
    }
    return Uml::sequence_message_asynchronous;
}

void ToolBarStateMessages::cleanMessage() {
    m_firstObject = 0;

    delete m_messageLine;
    m_messageLine = 0;
}

#include "toolbarstatemessages.moc"
