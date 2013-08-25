/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2013                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

#ifndef UMLWIDGET_H
#define UMLWIDGET_H

#include "associationwidgetlist.h"
#include "basictypes.h"
#include "optionstate.h"
#include "umlscene.h"  //:TODO: remove this when all UMLScene types are replaced
#include "widgetbase.h"

#include <QCursor>
#include <QDateTime>
#include <QFont>

class IDChangeLog;
class ListPopupMenu;
class UMLDoc;
class UMLObject;
class UMLScene;

class QPainter;
class QMoveEvent;
class QFontMetrics;

/**
 * This is the base class for nearly all graphical widgets.
 *
 * @short The base class for graphical UML objects.
 * @author  Paul Hensgen <phensgen@techie.com>
 * Bugs and comments to uml-devel@lists.sf.net or http://bugs.kde.org
 */
class UMLWidget : public WidgetBase
{
    Q_OBJECT
public:

    friend class ToolBarStateArrow;  // for calling the mouse*Event handlers

    static const QSizeF DefaultMinimumSize;
    static const QSizeF DefaultMaximumSize;

    explicit UMLWidget(UMLScene *scene, WidgetType type = wt_UMLWidget, UMLObject *o = 0);
    explicit UMLWidget(UMLScene *scene, WidgetType type = wt_UMLWidget, Uml::ID::Type id = Uml::ID::None);
    virtual ~UMLWidget();

    // Copy constructor - not implemented.
    // UMLWidget(const UMLWidget& other);

    UMLWidget& operator=(const UMLWidget& other);

    bool operator==(const UMLWidget& other) const;

    virtual QSizeF minimumSize();
    void setMinimumSize(const QSizeF &size);

    virtual QSizeF maximumSize();
    void setMaximumSize(const QSizeF &size);

    void setUseFillColor(bool fc);

    virtual void setTextColor(const QColor &color);
    void setTextColorcmd(const QColor &color);

    virtual void setLineColor(const QColor &color);
    void setLineColorcmd(const QColor &color);

    virtual void setLineWidth(uint width);

    virtual void setFillColor(const QColor &color);
    void setFillColorcmd(const QColor &color);

    virtual void setSelected(bool _select);

    /**
     * Returns the state of whether the widget is selected.
     *
     * @return Returns the state of whether the widget is selected.
     */
    bool isSelected() const {
        return m_selected;
    }

    void setSelectedFlag(bool _select) {
        m_selected = _select;
    }

    void setScene(UMLScene *scene);

    virtual bool activate(IDChangeLog* ChangeLog = 0);

    virtual qreal onWidget(const QPointF &p);

    void setPenFromSettings(QPainter &p);
    void setPenFromSettings(QPainter *p);

    virtual QFont font() const;
    virtual void setFont(QFont font);

    /**
     * Returns whether we triggered the update of position movement.
     * If so, you probably don't want to move it.
     *
     * @return The moving state.
     */
    bool getStartMove() const {
        return m_startMove;
    }

    virtual void setX(qreal x);
    virtual void setY(qreal y);

    /**
     * Returns the height of widget.
     */
    qreal height() const {
        return rect().height();
    }

    /**
     * Returns the width of the widget.
     */
    qreal width() const {
        return rect().width();
    }

    void setSize(qreal width, qreal height);
    void setSize(const QSizeF& size);

    virtual void resizeWidget(qreal newW, qreal newH);

    bool getIgnoreSnapToGrid() const;
    void setIgnoreSnapToGrid(bool to);

    void moveByLocal(qreal dx, qreal dy);

    void removeAssoc(AssociationWidget* pAssoc);
    void addAssoc(AssociationWidget* pAssoc);

    /**
     *  Returns the list of associations connected to this widget.
     */
    AssociationWidgetList & associationWidgetList() {
        return m_Assocs;
    }

    /**
     * Read property of bool m_isInstance
     */
    bool isInstance() const {
        return m_isInstance;
    }

    /**
     * Write property of bool m_isInstance
     */
    void setIsInstance(bool isInstance) {
        m_isInstance = isInstance;
    }

    /**
     * Write property of m_instanceName
     */
    void setInstanceName(const QString &instanceName) {
        m_instanceName = instanceName;
    }

    /**
     * Read property of m_instanceName
     */
    QString instanceName() const {
        return m_instanceName;
    }

    bool showStereotype() const;
    virtual void setShowStereotype(bool flag);

    virtual void showPropertiesDialog();

    virtual void adjustAssocs(qreal x, qreal y);
    void adjustUnselectedAssocs(qreal x, qreal y);

    bool isActivated() const;
    void setActivated(bool active = true);

    virtual void cleanup();

    static bool widgetHasUMLObject(WidgetBase::WidgetType type);

    void updateGeometry();

    void clipSize();

    void forceUpdateFontMetrics(QPainter *painter);

    virtual bool loadFromXMI(QDomElement &qElement);
    virtual void saveToXMI(QDomDocument &qDoc, QDomElement &qElement);

    QPointF startMovePosition() const;
    QSizeF startResizeSize() const;

    virtual QSizeF calculateSize();
    void resize();

    bool fixedAspectRatio() const {
        return m_fixedAspectRatio;
    }

    void setFixedAspectRatio(bool state) {
        m_fixedAspectRatio = state;
    }

    typedef enum {
        FT_NORMAL = 0,
        FT_BOLD  = 1,
        FT_ITALIC = 2,
        FT_UNDERLINE = 3,
        FT_BOLD_ITALIC = 4,
        FT_BOLD_UNDERLINE = 5,
        FT_ITALIC_UNDERLINE = 6,
        FT_BOLD_ITALIC_UNDERLINE = 7,
        FT_INVALID = 8
    } FontType;

    virtual void setDefaultFontMetrics(UMLWidget::FontType fontType);
    virtual void setDefaultFontMetrics(UMLWidget::FontType fontType, QPainter &painter);

    QFontMetrics &getFontMetrics(UMLWidget::FontType fontType);
    void setFontMetrics(UMLWidget::FontType fontType, QFontMetrics fm);
    void setupFontType(QFont &font, UMLWidget::FontType fontType);

public Q_SLOTS:
    virtual void updateWidget();
    virtual void slotMenuSelection(QAction* action);
    virtual void slotWidgetMoved(Uml::ID::Type id);
    virtual void slotFillColorChanged(Uml::ID::Type viewID);
    virtual void slotLineColorChanged(Uml::ID::Type viewID);
    virtual void slotTextColorChanged(Uml::ID::Type viewID);
    virtual void slotLineWidthChanged(Uml::ID::Type viewID);

    void slotClearAllSelected();
    void slotSnapToGrid();

signals:
    /**
     * Emit when the widget moves its' position.
     * @param id The id of the object behind the widget.
     */
    void sigWidgetMoved(Uml::ID::Type id);

protected:
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent* event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual void moveEvent(QGraphicsSceneMouseEvent *event);
    virtual void moveWidgetBy(qreal diffX, qreal diffY);
    virtual void constrainMovementForAllWidgets(qreal &diffX, qreal &diffY);
    virtual void constrain(qreal& width, qreal& height);

    virtual bool isInResizeArea(QGraphicsSceneMouseEvent *me);
    virtual QCursor resizeCursor() const;

    virtual void paintSelected(QPainter * p, int offsetX = 0, int offsetY = 0);

    void selectSingle(QGraphicsSceneMouseEvent *me);
    void selectMultiple(QGraphicsSceneMouseEvent *me);
    void deselect(QGraphicsSceneMouseEvent *me);
    // void resetSelection();

    void setSelectionBounds();

    void resize(QGraphicsSceneMouseEvent *me);

    bool wasSizeChanged();
    bool wasPositionChanged();

    ///////////////// Data Loaded/Saved /////////////////////////////////

    /// A list of AssociationWidgets between the UMLWidget and other UMLWidgets in the diagram
    AssociationWidgetList m_Assocs;

    QFont m_Font;   ///< the font the widget will use

    QString m_instanceName;  ///< instance name (used if on a deployment diagram)
    bool m_isInstance;       ///< holds whether this widget is a component instance (i.e. on a deployment diagram)
    bool m_showStereotype;   ///< should the stereotype be displayed

    ///////////////// End of Data Loaded/Saved //////////////////////////

    bool m_selected, m_startMove;
    QPointF        m_startMovePostion;
    QSizeF         m_startResizeSize;
    int            m_nPosX;
    UMLDoc        *m_doc;  ///< shortcut for UMLApp::app()->getDocument()
    bool           m_resizable;
    QFontMetrics  *m_pFontMetrics[FT_INVALID];
    QSizeF         m_minimumSize;
    QSizeF         m_maximumSize;

    /// true if the activate function has been called for this class instance
    bool m_activated;

    /**
     * Change Widget Behaviour
     */
    bool m_ignoreSnapToGrid;
    bool m_ignoreSnapComponentSizeToGrid;
    bool m_fixedAspectRatio;

    /// Timer that prevents excessive updates (be easy on the CPU).
    QTime m_lastUpdate;

    /**
     * A list containing the selected widgets.
     * It's filled by setSelectionBounds method. It must be filled again if
     * selected widgets changed. It is cleared only in setSelectionBounds, just
     * before filling it.
     * Select, deselect and so on methods DON'T modify this list.
     */
    UMLWidgetList m_selectedWidgetsList;

    /// The text in the status bar when the cursor was pressed.
    QString m_oldStatusBarMsg;

    /// The X/Y offset from the position of the cursor when it was pressed to the
    /// upper left corner of the widget.
    QPointF m_pressOffset;

    /// The X/Y position the widget had when the movement started.
    QPointF m_oldPos;

    /// The width/height the widget had when the resize started.
    qreal m_oldW, m_oldH;

    /// If shift or control button were pressed in mouse press event.
    bool m_shiftPressed;

    /**
     * If cursor was in move/resize area when left button was pressed (and no
     * other widgets were selected).
     */
    bool m_inMoveArea, m_inResizeArea;

    /**
     * If the widget was selected/moved/resized in the press and release cycle.
     * Moved/resized is true if the widget was moved/resized even if the final
     * position/size is the same as the starting one.
     */
    bool m_moved, m_resized;

private:
    void init();
    void toForeground();


};
#endif
