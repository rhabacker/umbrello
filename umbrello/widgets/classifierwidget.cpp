/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   copyright (C) 2004-2009                                               *
 *   Umbrello UML Modeller Authors <uml-devel@uml.sf.net>                  *
 ***************************************************************************/

// own header
#include "classifierwidget.h"

// qt/kde includes

// app includes
#include "associationline.h"
#include "associationwidget.h"
#include "classifier.h"
#include "expanderbox.h"
#include "listpopupmenu.h"
#include "object_factory.h"
#include "operation.h"
#include "template.h"
#include "textitem.h"
#include "textitemgroup.h"
#include "uml.h"
#include "umldoc.h"
#include "umlscene.h"
#include "umlview.h"
#include "widget_utils.h"

static QBrush awesomeHeaderBrush()
{
    static QBrush brush;
    if (brush.style() == Qt::NoBrush) {
        QColor alphaBlue(Qt::darkBlue);
        alphaBlue.setAlpha(155);
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(alphaBlue);
    }
    return brush;
}

const qreal ClassifierWidget::CircleMinimumRadius = 30;
const int ClassifierWidget::InvalidIndex = 99999;

/**
 * Constructs a ClassifierWidget.
 *
 * @param c The UMLObject to represent.
 */
ClassifierWidget::ClassifierWidget(UMLClassifier *c)
    : UMLWidget(c),
    m_classAssociationWidget(0)

{
    createTextItemGroup(); // For header (name, stereotype..)
    createTextItemGroup(); // For attributes and operations.
    createTextItemGroup(); // For template text items'

    m_attributeExpanderBox = new ExpanderBox(false, this);
    connect(m_attributeExpanderBox, SIGNAL(expansionToggled(bool)), this, SLOT(slotShowAttributes(bool)));

    m_operationExpanderBox = new ExpanderBox(false, this);
    connect(m_operationExpanderBox, SIGNAL(expansionToggled(bool)), this, SLOT(slotShowOperations(bool)));

    // Null initially
    m_dummyAttributeItem = m_dummyOperationItem = 0;
    m_lineItem2Index = InvalidIndex;

    m_baseType = Uml::wt_Class;
    // TODO: The following properties should be set using the
    //       OptionState rather than direct defaults.

    // Set the following properties by default. The remaining
    // properties are not set.
    m_visualProperties = ShowOperations | ShowVisibility | ShowAttributes;

    m_attributeSignatureType = Uml::st_ShowSig;
    m_operationSignatureType = Uml::st_ShowSig;

    // Check if this widget is representing an interface and set
    // properties corresponding to that if it is.
    if (c && c->isInterface()) {
        m_baseType = Uml::wt_Interface;
        m_visualProperties = ShowOperations | ShowVisibility | ShowStereotype;
        setShowStereotype(true);
    }
}

/**
 * Destructor
 * @todo Reimplement this properly after implementing the Associationwidget
 */
ClassifierWidget::~ClassifierWidget()
{
    if (m_classAssociationWidget) {
        m_classAssociationWidget->setAssociationClass(0);
    }
}

/// @return the UMLClassifier which this ClassifierWidget represents.
UMLClassifier *ClassifierWidget::classifier() const
{
    return static_cast<UMLClassifier*>(umlObject());
}

/**
 * Set an OR combination of properties stored in \a properties on this
 * widget.
 */
void ClassifierWidget::setVisualProperties(VisualProperties properties)
{
    // Don't do anything if the argument is equal to current status.
    if (quint32(m_visualProperties) == quint32(properties)) {
        return;
    }

    m_visualProperties = properties;
    updateSignatureTypes();
}

/**
 * @return The status of the property passed in.
 *
 * @note Use @ref attributeSignatureType() and @ref
 *       operationSignatureType() to get signature status.  This
 *       method only indicates whether signature is visible or not.
 */
bool ClassifierWidget::visualProperty(VisualProperty property) const
{
    if (property == ShowAttributeSignature) {
        return (m_attributeSignatureType == Uml::st_ShowSig
                || m_attributeSignatureType == Uml::st_SigNoVis);
    }

    else if(property == ShowOperationSignature) {
        return (m_operationSignatureType == Uml::st_ShowSig
                || m_operationSignatureType == Uml::st_SigNoVis);
    }

    return m_visualProperties.testFlag(property);
}

/**
 * A convenient method to set and reset individual VisualProperty
 *
 * @param property The property to be set/reset.
 * @param enable   True/false to set/reset. (default = true)
 *
 * @note This method handles ShowAttributeSignature and
 *       ShowOperationSignature specially.
 */
void ClassifierWidget::setVisualProperty(VisualProperty property, bool enable)
{
    // Handle ShowAttributeSignature and ShowOperationSignature
    // specially.

    if (property == ShowAttributeSignature) {
        if (!enable) {
            m_attributeSignatureType = visualProperty(ShowVisibility) ?
                Uml::st_NoSig : Uml::st_NoSigNoVis;
        }
        else {
            m_attributeSignatureType = visualProperty(ShowVisibility) ?
                Uml::st_ShowSig : Uml::st_SigNoVis;
        }
        updateTextItemGroups();
    }

    else if (property == ShowOperationSignature) {
        if (!enable) {
            m_operationSignatureType = visualProperty(ShowVisibility) ?
                Uml::st_NoSig : Uml::st_NoSigNoVis;
        }
        else {
            m_operationSignatureType = visualProperty(ShowVisibility) ?
                Uml::st_ShowSig : Uml::st_SigNoVis;
        }
        updateTextItemGroups();
    }

    else if (property == ShowStereotype) {
        // Now just update flag and use base method for actual work.
        if (enable) {
            m_visualProperties |= property;
        }
        else {
            enable &= ~property;
        }
        setShowStereotype(enable);
    }

    // Some other flag.
    else {
        // Don't do anything if the flag status is same.
        if (visualProperty(property) == enable) {
            return;
        }

        // Call setVisualProperties appropriately based on enbable.
        if (enable) {
            setVisualProperties(visualProperties() | property);
        }
        else {
            setVisualProperties(visualProperties() & ~property);
        }
    }
}

/**
 * A convenient method to toggle individual VisualProperty of this
 * widget.
 *
 * @param property The property to be toggled.
 *
 * @note This method handles ShowAttributeSignature and
 *       ShowOperationSignature specially.
 */
void ClassifierWidget::toggleVisualProperty(VisualProperty property)
{
    bool oppositeStatus;
    if (property == ShowOperationSignature) {
        oppositeStatus = !(m_operationSignatureType == Uml::st_ShowSig
                           || m_operationSignatureType == Uml::st_SigNoVis);
    }
    else if (property == ShowAttributeSignature) {
        oppositeStatus = !(m_attributeSignatureType == Uml::st_ShowSig
                           || m_attributeSignatureType == Uml::st_SigNoVis);
    }
    else {
        oppositeStatus = !visualProperty(property);
    }

    uDebug() << "VisualProperty:" << property << "to opposite status " << oppositeStatus;
    setVisualProperty(property, oppositeStatus);
}

/**
 * @retval true  If this widget represents interface and DrawAsCircle
 *               property is set.
 */
bool ClassifierWidget::shouldDrawAsCircle() const
{
    return baseType() == Uml::wt_Interface && visualProperty(DrawAsCircle) == true;
}

/**
 * Set's the attribute signature type to \a sigType.
 */
void ClassifierWidget::setAttributeSignature(Uml::Signature_Type sigType)
{
    m_attributeSignatureType = sigType;
    updateSignatureTypes();
}

/**
 * Set's the operation signature type to \a sigType.
 */
void ClassifierWidget::setOperationSignature(Uml::Signature_Type sigType)
{
    m_operationSignatureType = sigType;
    updateSignatureTypes();
}

/**
 * Changes this classifier from an interface to a class.  Attributes
 * and stereotype visibility is got from the view OptionState.  This
 * widget is also updated.
 */
void ClassifierWidget::changeToClass()
{
    m_baseType = Uml::wt_Class;
    classifier()->setBaseType(Uml::ot_Class);

    bool showAtts = true;
    bool showStereotype = false;

    if (umlScene()) {
        const Settings::OptionState& ops = umlScene()->getOptionState();
        showAtts = ops.classState.showAtts;
        showStereotype = ops.classState.showStereoType;
    }

    setVisualProperty(ShowAttributes, showAtts);
    setVisualProperty(ShowStereotype, showStereotype);

    updateTextItemGroups();
}

/**
 * Changes this classifier from a class to an interface.  Attributes
 * are hidden and stereotype is shown.  This widget is also updated.
 */
void ClassifierWidget::changeToInterface()
{
    m_baseType = Uml::wt_Interface;
    classifier()->setBaseType(Uml::ot_Interface);

    setVisualProperty(ShowAttributes, false);
    setVisualProperty(ShowStereotype, true);

    updateTextItemGroups();
}

/**
 * Set the AssociationWidget when this ClassWidget acts as an
 * association class.
 */
void ClassifierWidget::setClassAssociationWidget(AssociationWidget *assocwidget)
{
    m_classAssociationWidget = assocwidget;
    UMLAssociation *umlassoc = 0;
    if (assocwidget) {
        umlassoc = assocwidget->association();
    }
    classifier()->setClassAssoc(umlassoc);
}

/**
 * Extends base method to adjust also the association of a class
 * association.  Executes the base method and then, if file isn't
 * loading and the classifier acts as a class association, the
 * association position is updated.
 *
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 *
 * @todo Implement this properly after implementing AssociationWidget.
 */
void ClassifierWidget::adjustAssociations()
{
    UMLWidget::adjustAssociations();

    if (umlDoc()->loading() || m_classAssociationWidget == 0) {
        return;
    }

    m_classAssociationWidget->associationLine()->calculateAssociationClassLine();
}

/**
 * Reimplemented from UMLWidget::loadFromXMI to load the
 * classifier widget from XMI.
 */
bool ClassifierWidget::loadFromXMI(QDomElement & qElement)
{
    if (!UMLWidget::loadFromXMI(qElement)) {
        return false;
    }

    // Determine str
    QString defaultSigType = QString::number(Uml::st_NoSig);

    QString showatts = qElement.attribute( "showattributes", "0" );
    QString showops = qElement.attribute( "showoperations", "1" );
    QString showpubliconly = qElement.attribute( "showpubliconly", "0" );
    QString showattsigs = qElement.attribute( "showattsigs", defaultSigType );
    QString showopsigs = qElement.attribute( "showopsigs", defaultSigType );
    QString showpackage = qElement.attribute( "showpackage", "0" );
    QString showscope = qElement.attribute( "showscope", "0" );
    QString drawascircle = qElement.attribute("drawascircle", "0");

    setVisualProperty(ShowAttributes, (bool)showatts.toInt());
    setVisualProperty(ShowOperations, (bool)showops.toInt());
    setVisualProperty(ShowPublicOnly, (bool)showpubliconly.toInt());
    setVisualProperty(ShowPackage, (bool)showpackage.toInt());
    setVisualProperty(ShowVisibility, (bool)showscope.toInt());
    setVisualProperty(DrawAsCircle, (bool)drawascircle.toInt());

    setAttributeSignature((Uml::Signature_Type)showattsigs.toInt());
    setOperationSignature((Uml::Signature_Type)showopsigs.toInt());

    return true;
}

/**
 * Reimplemented from UMLWidget::saveToXMI to save
 * classifierwidget data either to 'interfacewidget' or 'classwidget'
 * XMI element.
 */
void ClassifierWidget::saveToXMI(QDomDocument & qDoc, QDomElement & qElement)
{
    QDomElement conceptElement;
    UMLClassifier *umlc = classifier();

    QString tagName = umlc->isInterface() ?
        "interfacewidget" : "classwidget";
    conceptElement = qDoc.createElement(tagName);
    UMLWidget::saveToXMI( qDoc, conceptElement );

    conceptElement.setAttribute("showoperations", visualProperty(ShowOperations));
    conceptElement.setAttribute("showpubliconly", visualProperty(ShowPublicOnly));
    conceptElement.setAttribute("showopsigs", m_operationSignatureType);
    conceptElement.setAttribute("showpackage", visualProperty(ShowPackage));
    conceptElement.setAttribute("showscope", visualProperty(ShowVisibility));

    if (! umlc->isInterface()) {
        conceptElement.setAttribute("showattributes", visualProperty(ShowAttributes));
        conceptElement.setAttribute("showattsigs", m_attributeSignatureType);
    }

    if (umlc->isInterface() || umlc->getAbstract()) {
        conceptElement.setAttribute("drawascircle", visualProperty(DrawAsCircle));
    }
    qElement.appendChild(conceptElement);
}

/**
 * Reimplemented form UMLWidget::paint to draw
 * ClassifierWidget.
 */
void ClassifierWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget *)
{
    QPen pen(lineColor(), lineWidth());
    painter->setPen(pen);
    painter->setBrush(brush());

    if (shouldDrawAsCircle()) {
        // m_classifierRect represents circle geometry when shouldDrawAsCircle is true.
        painter->drawEllipse(m_classifierRect);
    }
    else {
        // The elements not to be drawn will have null dimension and
        // hence it effectively is not drawn. (automatic ;) )
        painter->drawRoundedRect(m_classifierRect, 5, 5);
        painter->drawLines(m_classifierLines, 2);

        painter->setPen(QPen(Qt::NoPen));
        painter->setBrush(awesomeHeaderBrush());
        Uml::Corners corners(Uml::corner_TopLeft | Uml::corner_TopRight);
        Widget_Utils::drawRoundedRect(painter, textItemGroupAt(HeaderGroupIndex)->groupGeometry(),
                5, 5, corners);

        pen.setStyle(Qt::DotLine);
        painter->setPen(pen);
        painter->setBrush(brush());
        painter->drawRect(m_templateRect);
    }
}

/**
 * Reimplemented from UMLWidget::updateGeometry to calculate
 * minimum size for this widget based on the current state of this
 * widget.
 */
void ClassifierWidget::updateGeometry()
{
    // Min size including classifier and template box.
    QSizeF totalMinSize;
    UMLWidget::SizeHintOption sizeHintOption = UMLWidget::AddMargin;

    // Min size for classifier items and header (doesn't include template)
    QSizeF headerSize = textItemGroupAt(HeaderGroupIndex)->minimumSize();
    QSizeF attribOpSize = textItemGroupAt(AttribOpGroupIndex)->minimumSize();

    QSizeF classifierMinSize; // combined size
    classifierMinSize.setWidth(qMax(headerSize.width(), attribOpSize.width()));
    classifierMinSize.setHeight(headerSize.height() + attribOpSize.height());

    if (shouldDrawAsCircle()) {
        qreal minDiameter = 2 * ClassifierWidget::CircleMinimumRadius;
        // only header items are drawn, so total min size should include only that.
        totalMinSize.setWidth(qMax(headerSize.width(), minDiameter));
        totalMinSize.setHeight(headerSize.height() + minDiameter);
    } else {
        // Draw the bounding rectangle
        QSizeF templateBoxSize = textItemGroupAt(TemplateGroupIndex)->minimumSize();

        if (textItemGroupAt(TemplateGroupIndex)->textItemCount() == 0) {
            // If we don't have template params use entire size for header, params and operations.
            totalMinSize = classifierMinSize;
        }
        else {
            // minus margin() below because to overlap a bit.
            totalMinSize.setHeight(classifierMinSize.height() +
                    templateBoxSize.height() - margin());
            totalMinSize.setWidth(classifierMinSize.width() + .5 * templateBoxSize.width());
            // Dont add margin as we have already added manually
            sizeHintOption = UMLWidget::DontAddMargin;
        }

    }
    setMinimumSize(totalMinSize, sizeHintOption);
    UMLWidget::updateGeometry();
}

/**
 * Reimplemented from UMLWidget::attributeChange to handle @ref
 * SizeHasChanged notification and pre-calculate the TextItem position
 * and the drawing elements like rectangle, lines ...
 */
QVariant ClassifierWidget::attributeChange(WidgetAttributeChange change, const QVariant& oldValue)
{
    if (change == SizeHasChanged) {
        calculateTemplateDrawing();
        calculateClassifierDrawing();
    }
    return UMLWidget::attributeChange(change, oldValue);
}

/**
 * Calculates the template box dimensions and the position of text
 * items inside it based on the current size.
 */
void ClassifierWidget::calculateTemplateDrawing()
{
    const qreal w = size().width();

    TextItemGroup *templateGroup = textItemGroupAt(TemplateGroupIndex);
    QSizeF templateGroupSize = templateGroup->minimumSize();

    // No template box if no templates or drawing as circle.
    if (templateGroup->textItemCount() == 0 || shouldDrawAsCircle()) {
        m_templateRect = QRectF();
    }
    else {
        m_templateRect.setTop(0);
        m_templateRect.setLeft(w - templateGroupSize.width());
        m_templateRect.setSize(templateGroupSize);

        templateGroup->setGroupGeometry(m_templateRect);
    }
}

/**
 * Calculates the classifier box dimensions and the position of text
 * items inside it based on the current size.
 *
 * @note Assumes calculateTemplateDrawing is called before calling
 *       this method.
 */
void ClassifierWidget::calculateClassifierDrawing()
{
    const qreal w = width();
    const qreal h = height();

    TextItemGroup *headerGroup = textItemGroupAt(HeaderGroupIndex);
    TextItemGroup *attribOpGroup = textItemGroupAt(AttribOpGroupIndex);

    if (shouldDrawAsCircle()) {
        // Allocates circle space algined at top and "minimum space"
        // for the text which is aligned bottom.
        qreal fontHeight = headerGroup->minimumSize().height();
        qreal diameter = qMin(w, h - fontHeight);
        m_classifierRect.setRect(0, 0, diameter, diameter);
        m_classifierRect.moveCenter(QPointF(.5 * w, m_classifierRect.center().y()));

        QRectF groupRect(0, diameter, w, h - diameter);
        headerGroup->setGroupGeometry(groupRect);
        // classifierGroup->setGroupGeometry(groupRect);
        m_classifierLines[0] = m_classifierLines[1] = QLineF();
    }
    else {
        // Utilize entire space if template box is empty.
        if (textItemGroupAt(TemplateGroupIndex)->textItemCount() == 0) {
            m_classifierRect = rect();
        }
        else {
            m_classifierRect.setTop(m_templateRect.bottom() - margin());
            m_classifierRect.setLeft(0);
            m_classifierRect.setBottomRight(QPointF(m_templateRect.center().x(), h));
        }

        QRectF headerGeometry(m_classifierRect);
        headerGeometry.setHeight(headerGroup->minimumSize().height());
        headerGroup->setGroupGeometry(headerGeometry);

        QRectF attribOpGeometry(m_classifierRect);
        attribOpGeometry.setTop(headerGeometry.bottom());
        attribOpGroup->setGroupGeometry(attribOpGeometry);

        const int cnt = attribOpGroup->textItemCount();
        qreal expanderDistance = 4;
        bool showNameOnly = (!visualProperty(ShowAttributes) && !visualProperty(ShowOperations)
                && !visualProperty(ShowStereotype) && !shouldDrawAsCircle());
        if (!showNameOnly && !shouldDrawAsCircle()) {
            qreal y = textItemGroupAt(HeaderGroupIndex)->groupGeometry().bottom();
            m_classifierLines[0].setLine(m_classifierRect.left(), y, m_classifierRect.right(), y);
            qreal expanderX = rect().left() -
                m_attributeExpanderBox->rect().width() -
                expanderDistance;
            m_attributeExpanderBox->setPos(expanderX, y);
        }
        if (cnt > m_lineItem2Index) {
            TextItem *item = attribOpGroup->textItemAt(m_lineItem2Index);
            qreal y = item->mapToParent(item->boundingRect().bottomLeft()).y();
            m_classifierLines[1].setLine(m_classifierRect.left(), y, m_classifierRect.right(), y);
            qreal expanderX = rect().left() - m_operationExpanderBox->rect().width() -
                expanderDistance;
            m_operationExpanderBox->setPos(expanderX, y);
        }
    }
}

/**
 * Reimplemented from UMLWidget::updateTextItemGroups to
 * calculate the Text strings , their properties and also hide/show
 * them based on the current state.
 */
void ClassifierWidget::updateTextItemGroups()
{
    // Invalidate stuff and recalculate them.
    invalidateDummies();

    TextItemGroup *headerGroup = textItemGroupAt(HeaderGroupIndex);
    TextItemGroup *attribOpGroup = textItemGroupAt(AttribOpGroupIndex);
    TextItemGroup *templateGroup = textItemGroupAt(TemplateGroupIndex);

    attribOpGroup->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    templateGroup->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    UMLClassifier *umlC = classifier();
    UMLClassifierListItemList attribList = umlC->getFilteredList(Uml::ot_Attribute);
    UMLClassifierListItemList opList = umlC->getFilteredList(Uml::ot_Operation);

    // Set up template group and template text items.
    UMLTemplateList tlist = umlC->getTemplateList();
    templateGroup->setTextItemCount(tlist.size());
    bool templateHide = shouldDrawAsCircle(); // Hide if draw as circle.
    for(int i = 0; i < tlist.size(); ++i) {
        UMLTemplate *t = tlist[i];
        templateGroup->textItemAt(i)->setText(t->toString());
        templateGroup->textItemAt(i)->setVisible(!templateHide);
    }

    // Stereo type and name.
    const int headerItemCount = 2;
    headerGroup->setTextItemCount(headerItemCount);

    const int cnt = attribList.count() + opList.count();
    attribOpGroup->setTextItemCount(cnt);

    // Setup Stereo text item.
    TextItem *stereoItem = headerGroup->textItemAt(StereotypeItemIndex);
    stereoItem->setBold(true);
    stereoItem->setText(umlC->getStereotype(true));

    bool v = !shouldDrawAsCircle()
        && visualProperty(ShowStereotype)
        && !(umlC->getStereotype(false).isEmpty());
    stereoItem->setVisible(v);

    // name item is always visible.
    TextItem *nameItem = headerGroup->textItemAt(NameItemIndex);
    nameItem->setBold(true);
    nameItem->setItalic(umlC->getAbstract());
    nameItem->setUnderline(shouldDrawAsCircle());
    QString nameText = name();
    if (visualProperty(ShowPackage) == true) {
        nameText = umlC->getFullyQualifiedName();
    }

    bool showNameOnly = (!visualProperty(ShowAttributes) && !visualProperty(ShowOperations)
                         && !visualProperty(ShowStereotype) && !shouldDrawAsCircle());
    nameItem->setText(nameText);

    int attribStartIndex = 0;
    int opStartIndex = attribStartIndex + attribList.size();

    // Now setup attribute texts.
    int visibleAttributes = 0;
    for (int i=0; i < attribList.size(); ++i) {
        UMLClassifierListItem *obj = attribList[i];

        TextItem *item = attribOpGroup->textItemAt(attribStartIndex + i);
        item->setItalic(obj->getAbstract());
        item->setUnderline(obj->getStatic());
        item->setText(obj->toString(m_attributeSignatureType));

        bool v = !shouldDrawAsCircle()
            && ( !visualProperty(ShowPublicOnly)
                 || obj->getVisibility() == Uml::Visibility::Public)
            && visualProperty(ShowAttributes) == true;

        item->setVisible(v);
        if (v) {
            ++visibleAttributes;
        }
    }

    // Update expander box to reflect current state and also visibility
    m_attributeExpanderBox->setExpanded(visualProperty(ShowAttributes));
    m_attributeExpanderBox->setVisible(!visualProperty(DrawAsCircle) && !umlC->isInterface());

    const QString dummyText;
    // Setup line and dummies.
    if (!showNameOnly) {
        // Stuff in a dummy item as spacer if there are no attributes,
        if (!shouldDrawAsCircle() && (visibleAttributes == 0 || !visualProperty(ShowAttributes))) {
            m_dummyAttributeItem = new TextItem(dummyText);
            int index = attribStartIndex;
            if (visibleAttributes == 0 && !attribList.isEmpty()) {
                index = opStartIndex;
            }
            attribOpGroup->insertTextItemAt(index, m_dummyAttributeItem);
            m_lineItem2Index = index;
            ++opStartIndex;
        }
        else {
            // Now set the second index.
            m_lineItem2Index = opStartIndex - 1;
        }
    }

    int visibleOperations = 0;
    for (int i=0; i < opList.size(); ++i) {
        UMLClassifierListItem *obj = opList[i];

        TextItem *item = attribOpGroup->textItemAt(opStartIndex + i);
        item->setItalic(obj->getAbstract());
        item->setUnderline(obj->getStatic());
        item->setText(obj->toString(m_operationSignatureType));

        bool v = !shouldDrawAsCircle()
            && ( !visualProperty(ShowPublicOnly)
                 || obj->getVisibility() == Uml::Visibility::Public)
            && visualProperty(ShowOperations);

        item->setVisible(v);
        if (v) {
            ++visibleOperations;
        }
    }
    m_operationExpanderBox->setExpanded(visualProperty(ShowOperations));
    m_operationExpanderBox->setVisible(!visualProperty(DrawAsCircle));

    if (!showNameOnly) {
        if (!shouldDrawAsCircle() && (visibleOperations == 0 || !visualProperty(ShowOperations))) {
            m_dummyOperationItem = new TextItem(dummyText);
            attribOpGroup->insertTextItemAt(opStartIndex+opList.size(), m_dummyOperationItem);
        }
    }

    UMLWidget::updateTextItemGroups();
}

/**
 * Determines the appropriate signature types for both operations and
 * attributes based on their current state and also based on access.
 */
void ClassifierWidget::updateSignatureTypes()
{
    //turn on scope
    if (visualProperty(ShowVisibility)) {
        // Take care of operation first
        if (m_operationSignatureType == Uml::st_NoSigNoVis) {
            m_operationSignatureType = Uml::st_NoSig;
        } else if (m_operationSignatureType == Uml::st_SigNoVis) {
            m_operationSignatureType = Uml::st_ShowSig;
        }
        // Now take care of attributes
        if (m_attributeSignatureType == Uml::st_NoSigNoVis)
            m_attributeSignatureType = Uml::st_NoSig;
        else if (m_attributeSignatureType == Uml::st_SigNoVis)
            m_attributeSignatureType = Uml::st_ShowSig;

    }
    //turn off scope
    else {
        // Take care of operations first
        if (m_operationSignatureType == Uml::st_ShowSig) {
            m_operationSignatureType = Uml::st_SigNoVis;
        } else if (m_operationSignatureType == Uml::st_NoSig) {
            m_operationSignatureType = Uml::st_NoSigNoVis;
        }
        // Now take care of attributes.
        if (m_attributeSignatureType == Uml::st_ShowSig)
            m_attributeSignatureType = Uml::st_SigNoVis;
        else if(m_attributeSignatureType == Uml::st_NoSig)
            m_attributeSignatureType = Uml::st_NoSigNoVis;
    }

    updateTextItemGroups();
}

void ClassifierWidget::slotMenuSelection(QAction* action)
{
    ListPopupMenu *menu = ListPopupMenu::menuFromAction(action);
    if (!menu) {
        uError() << "Action's data field does not contain ListPopupMenu pointer";
        return;
    }
    ListPopupMenu::Menu_Type sel = menu->getMenuType(action);
    switch (sel) {
    case ListPopupMenu::mt_Attribute:
    case ListPopupMenu::mt_Operation:
    case ListPopupMenu::mt_Template:
    {
        Uml::Object_Type ot = ListPopupMenu::convert_MT_OT(sel);
        if (Object_Factory::createChildObject(classifier(), ot)) {
            UMLApp::app()->getDocument()->setModified();
        }
        break;
    }
    case ListPopupMenu::mt_Show_Operations:
    case ListPopupMenu::mt_Show_Operations_Selection:
        toggleVisualProperty(ShowOperations);
        break;

    case ListPopupMenu::mt_Show_Attributes:
    case ListPopupMenu::mt_Show_Attributes_Selection:
        toggleVisualProperty(ShowAttributes);
        break;

    case ListPopupMenu::mt_Show_Public_Only:
    case ListPopupMenu::mt_Show_Public_Only_Selection:
        toggleVisualProperty(ShowPublicOnly);
        break;

    case ListPopupMenu::mt_Show_Operation_Signature:
    case ListPopupMenu::mt_Show_Operation_Signature_Selection:
        toggleVisualProperty(ShowOperationSignature);
        break;

    case ListPopupMenu::mt_Show_Attribute_Signature:
    case ListPopupMenu::mt_Show_Attribute_Signature_Selection:
        toggleVisualProperty(ShowAttributeSignature);
        break;

    case ListPopupMenu::mt_Visibility:
    case ListPopupMenu::mt_Visibility_Selection:
        toggleVisualProperty(ShowVisibility);
        break;

    case ListPopupMenu::mt_Show_Packages:
    case ListPopupMenu::mt_Show_Packages_Selection:
        toggleVisualProperty(ShowPackage);
        break;

    case ListPopupMenu::mt_Show_Stereotypes:
    case ListPopupMenu::mt_Show_Stereotypes_Selection:
        toggleVisualProperty(ShowStereotype);
        break;

    case ListPopupMenu::mt_DrawAsCircle:
    case ListPopupMenu::mt_DrawAsCircle_Selection:
        toggleVisualProperty(DrawAsCircle);
        break;

    case ListPopupMenu::mt_ChangeToClass:
    case ListPopupMenu::mt_ChangeToClass_Selection:
        changeToClass();
        break;

    case ListPopupMenu::mt_ChangeToInterface:
    case ListPopupMenu::mt_ChangeToInterface_Selection:
        changeToInterface();
        break;

    default:
        UMLWidget::slotMenuSelection(action);
        break;
    }
}

/// Slot to show/hide attributes based on \a state.
void ClassifierWidget::slotShowAttributes(bool state)
{
    setVisualProperty(ShowAttributes, state);
}

/// Slot to show/hide operations based on \a state.
void ClassifierWidget::slotShowOperations(bool state)
{
    setVisualProperty(ShowOperations, state);
}

/**
 * Invalidates all dummies used so that they can be recalculated again.
 */
void ClassifierWidget::invalidateDummies()
{
    TextItemGroup *grp = textItemGroupAt(AttribOpGroupIndex);
    if (m_dummyAttributeItem) {
        grp->deleteTextItem(m_dummyAttributeItem);
        m_dummyAttributeItem = 0;
    }

    if (m_dummyOperationItem) {
        grp->deleteTextItem(m_dummyOperationItem);
        m_dummyOperationItem = 0;
    }

    m_lineItem2Index = InvalidIndex;
    m_classifierLines[0] = m_classifierLines[1] = QLineF();
}
