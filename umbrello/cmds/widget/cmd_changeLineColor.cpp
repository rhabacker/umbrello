/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2002-2013                                               *
 *   Umbrello UML Modeller Authors <umbrello-devel@kde.org>                *
 ***************************************************************************/

#include "cmd_changeLineColor.h"

// app includes
#include "umlscene.h"
#include "umlwidget.h"

// kde includes
#include <klocale.h>

namespace Uml
{

    CmdChangeLineColor::CmdChangeLineColor(UMLWidget *w, const QColor& col)
      : m_widget(w),
        m_newColor(col)
    {
        Q_ASSERT(w != 0);
        setText(i18n("Change line color : %1", w->name()));
        m_oldColor= w->lineColor() ;
        m_oldUsesDiagramValue = w->usesDiagramLineColor();
    }

    CmdChangeLineColor::~CmdChangeLineColor()
    {
    }

    void CmdChangeLineColor::redo()
    {
        UMLScene* scene = m_widget->umlScene();
        if (scene && scene->widgetOnDiagram(m_widget->id())) {
            m_widget->setLineColorCmd(m_newColor);
        }
    }

    void CmdChangeLineColor::undo()
    {
        UMLScene* scene = m_widget->umlScene();
        if (scene && scene->widgetOnDiagram(m_widget->id())) {
            m_widget->setLineColorCmd(m_oldColor);
            m_widget->setUsesDiagramLineColor(m_oldUsesDiagramValue);
        }
    }

}
