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
#include "floatingdashlinewidget.h"
#include "combinedfragmentwidget.h"

//kde includes
#include <KLocalizedString>

//app includes
#include "debug_utils.h"
#include "dialog_utils.h"
#include "umlview.h"
#include "umlscene.h"
#include "widget_utils.h"
#include "listpopupmenu.h"

// qt includes
#include <QPainter>

DEBUG_REGISTER_DISABLED(FloatingDashLineWidget)

/**
 * Creates a floating dash line.
 * @param scene   The parent of the widget
 * @param id      The ID to assign (-1 will prompt a new ID)
 * @param parent  The CombinedFragmentWidget which acts as the parent
 */
FloatingDashLineWidget::FloatingDashLineWidget(UMLScene * scene, Uml::ID::Type id, CombinedFragmentWidget *parent)
  : UMLWidget(scene, WidgetBase::wt_FloatingDashLine, id),
    m_parent(parent)
{
    //scene->addItem(this);
    m_resizable = false;
    m_Text = QString();
    const QFontMetrics &fm = getFontMetrics(FT_NORMAL);
    const int fontHeight = fm.lineSpacing();
    setSize(10, fontHeight);
}

/**
 * Destructor.
 */
FloatingDashLineWidget::~FloatingDashLineWidget()
{
    if (m_parent)
        m_parent->removeDashLine(this);
}

/**
 * Overrides the standard paint event.
 */
void FloatingDashLineWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    const QFontMetrics &fm = getFontMetrics(FT_NORMAL);
    const int fontHeight  = fm.lineSpacing();
    painter->setPen(textColor());
    painter->setFont(UMLWidget::font());
    painter->drawText(FLOATING_DASH_LINE_TEXT_MARGIN, 0,
               width() - FLOATING_DASH_LINE_TEXT_MARGIN * 2, fontHeight,
               Qt::AlignLeft, QLatin1Char('[') + m_Text + QLatin1Char(']'));
    painter->setPen(QPen(UMLWidget::lineColor(), 0, Qt::DashLine));
    painter->drawLine(0, 0, width(), 0);

    UMLWidget::paint(painter, option, widget);
}

/**
 * Sets m_text.
 */
void FloatingDashLineWidget::setText(const QString& text)
{
    m_Text = text;
}

/**
 * Returns true if the given point is near the floatingdashline.
 */
bool FloatingDashLineWidget::onLine(const QPointF& point)
{
    // check if the given point is the start or end point of the line
    if (((abs((long)(y() + height() - point.y()))) <= POINT_DELTA) || (abs((long)(y() - point.y())) <= POINT_DELTA)) {
        return true;
    }
    // check if the given point is the start or end point of the line
   return false;
}

void FloatingDashLineWidget::slotMenuSelection(QAction* action)
{
    ListPopupMenu::MenuType sel = ListPopupMenu::typeFromAction(action);
    switch(sel) {
    case ListPopupMenu::mt_Rename:
        {
            QString name = m_Text;
            bool ok = Dialog_Utils::askName(i18n("Enter alternative Name"),
                                            i18n("Enter the alternative:"),
                                            name);
            if (ok && name.length() > 0)
                m_Text = name;
        }
        break;
    default:
        UMLWidget::slotMenuSelection(action);
    }
}

/**
 * Overrides the setY method.
 */
void FloatingDashLineWidget::setY(qreal y)
{
    qreal _y = mapFromScene(QPointF(y,0)).y();
    if (_y < m_marginTop)
        UMLWidget::setY(m_marginTop);
    else if (_y > m_parent->height() - m_marginBottom - height())
        UMLWidget::setY(m_parent->height() - m_marginBottom - height());
    else
        UMLWidget::setY(_y);
}

/**
 * Creates the "floatingdashline" XMI element.
 */
void FloatingDashLineWidget::saveToXMI1(QDomDocument & qDoc, QDomElement & qElement)
{
    QDomElement textElement = qDoc.createElement(QLatin1String("floatingdashlinewidget"));
    UMLWidget::saveToXMI1(qDoc, textElement);
    textElement.setAttribute(QLatin1String("text"), m_Text);

    qElement.appendChild(textElement);
}

/**
 * Loads the "floatingdashline" XMI element.
 */
bool FloatingDashLineWidget::loadFromXMI1(QDomElement & qElement)
{
    if(!UMLWidget::loadFromXMI1(qElement)) {
        return false;
    }
    DEBUG(DBG_SRC) << "load.......";
    m_Text = qElement.attribute(QLatin1String("text"));
    return true;
}

void FloatingDashLineWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF p = event->scenePos();
    setY(p.y());
}

void FloatingDashLineWidget::setVerticalMargins(qreal top, qreal bottom)
{
    m_marginTop = top;
    m_marginBottom = bottom;
}
