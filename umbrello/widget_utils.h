/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef WIDGET_UTILS_H
#define WIDGET_UTILS_H

#include "umlnamespace.h"
#include "umlwidgetlist.h"
#include "messagewidgetlist.h"

/**
 * General purpose widget utilities.
 * @author Oliver Kellogg
 * Bugs and comments to uml-devel@lists.sf.net or http://bugs.kde.org
 */
namespace Umbrello {

	/**
	 * Find the widget identified by the given ID in the given widget
	 * or message list.
	 *
	 * @param id		The unique ID to find.
	 * @param widgets	The UMLWidgetList to search in.
	 * @param pMessages	Optional pointer to a MessageWidgetList to
	 *			search in.
	 */
	UMLWidget* findWidget(int id,
			      const UMLWidgetList& widgets,
			      const MessageWidgetList* pMessages = NULL);

}

#endif
