/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2014                                               *
 *   Umbrello UML Modeller Authors <umbrello-devel@kde.org>                *
 ***************************************************************************/

#ifndef FLOATINGDASHLINEWIDGET_H
#define FLOATINGDASHLINEWIDGET_H

#include "umlwidget.h"
class CombinedFragmentWidget;

#define FLOATING_DASH_LINE_MARGIN 25
#define FLOATING_DASH_LINE_TEXT_MARGIN 5

/* how many pixels a user could click around a point */
#define POINT_DELTA 5

/**
 * This class is used to draw dash lines for UML combined fragments. A FloatingDashLineWidget
 * belongs to one @ref CombinedFragmentWidget instance.
 *
 * The FloatingDashLineWidget class inherits from the @ref UMLWidget class.
 *
 * @short  A dash line for UML combined fragments.
 * @author Thomas GALLINARI <tg8187@yahoo.fr>
 * Bugs and comments to umbrello-devel@kde.org or http://bugs.kde.org
 */
class FloatingDashLineWidget : public UMLWidget
{
    Q_OBJECT
public:
    explicit FloatingDashLineWidget(UMLScene * scene, Uml::ID::Type id = Uml::ID::None, CombinedFragmentWidget *parent = 0);
    ~FloatingDashLineWidget();

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option = 0, QWidget *widget = 0);

    void slotMenuSelection(QAction* action);

    bool onLine(const QPointF& point);

    void setText(const QString& text);

    void saveToXMI1(QDomDocument & qDoc, QDomElement & qElement);
    bool loadFromXMI1(QDomElement & qElement);
    void setY(qreal y);
    void setVerticalMargins(qreal top, qreal bottom);

protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /**
     * Text associated to the dash line
     */
    QString m_text;

    /**
     * vertical margins
     */
    qreal m_marginTop;
    qreal m_marginBottom;

    CombinedFragmentWidget *m_parent;
};

#endif
