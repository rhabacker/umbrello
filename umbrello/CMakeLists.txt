add_subdirectory( headings )
add_subdirectory(docgenerators)

if(ENABLE_OBJECT_DIAGRAM)
    set(ACTION_NEW_OBJECT_DIAGRAM "<Action name=\"new_object_diagram\"/>")
endif()
configure_file(umbrelloui.rc.cmake ${CMAKE_CURRENT_BINARY_DIR}/umbrelloui.rc @ONLY)
if(BUILD_KF5)
    configure_file(ui.qrc.cmake ${CMAKE_CURRENT_BINARY_DIR}/ui.qrc @ONLY)
endif()

########### set variables #############

# Some definitions for experimental code or debugging
# TODO migrate debug settings to DEBUG_REGISTER macro
#add_definitions(-DXMI_FLAT_PACKAGES)             # umlobject
#add_definitions(-DDEBUG_LVITEM_INSERTION_ORDER)  # umllistviewitem
#add_definitions(-DTRY_BUGFIX_120682)             # model_utils
#add_definitions(-DVERBOSE_DEBUGGING)             # listpopupmenu, association, petaltree2uml,
                                                  # umlobject, umldoc, classifierlistpage
if(UNIX)
    add_definitions(-D_GLIBCXX_PERMIT_BACKWARD_HASH)
endif()

add_definitions(-DCMAKE_BINARY_DIR="${CMAKE_BINARY_DIR}")
add_definitions(-DDOCGENERATORS_DIR="${CMAKE_SOURCE_DIR}/umbrello/docgenerators")
add_definitions(-DUMBRELLOUI_RC="${CMAKE_CURRENT_BINARY_DIR}/umbrelloui.rc")

include_directories(
  ${LIBXML2_INCLUDE_DIR}
  ${LIBXSLT_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/
  ${CMAKE_CURRENT_SOURCE_DIR}/clipboard/
  ${CMAKE_CURRENT_SOURCE_DIR}/cmds
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/ada/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/as/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/cpp/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/csharp/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/d/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/idl/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/java/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/js/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/pascal/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/perl/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/php/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/python/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/ruby/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/sql/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/tcl/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/vala/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/xml/
  ${CMAKE_CURRENT_SOURCE_DIR}/codegenwizard/
  ${CMAKE_CURRENT_SOURCE_DIR}/codeimport/
  ${CMAKE_CURRENT_SOURCE_DIR}/codeimport/csharp/
  ${CMAKE_CURRENT_SOURCE_DIR}/codeimpwizard/
  ${CMAKE_CURRENT_SOURCE_DIR}/debug/
  ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/
  ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/pages/
  ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/widgets/
  ${CMAKE_CURRENT_SOURCE_DIR}/docgenerators/
  ${CMAKE_CURRENT_SOURCE_DIR}/finder/
  ${CMAKE_CURRENT_SOURCE_DIR}/refactoring/
  ${CMAKE_CURRENT_SOURCE_DIR}/uml1model/
  ${CMAKE_CURRENT_SOURCE_DIR}/umlwidgets/
  ${CMAKE_CURRENT_SOURCE_DIR}/menus
  ${CMAKE_SOURCE_DIR}/lib/cppparser/
  ${CMAKE_SOURCE_DIR}/lib/interfaces/
)

set(libdebug_SRCS
    debug/debug_utils.cpp
)

set(libcodegenerator_SRCS
    codegenerators/advancedcodegenerator.cpp
    codegenerators/classifiercodedocument.cpp
    codegenerators/codeaccessormethod.cpp
    codegenerators/codeblock.cpp
    codegenerators/codeblockwithcomments.cpp
    codegenerators/codeclassfield.cpp
    codegenerators/codeclassfielddeclarationblock.cpp
    codegenerators/codecomment.cpp
    codegenerators/codedocument.cpp
    codegenerators/codegenerationpolicy.cpp
    codegenerators/codegenerator.cpp
    codegenerators/codegenfactory.cpp
    codegenerators/codegenobjectwithtextblocks.cpp
    codegenerators/codegenpolicyext.cpp
    codegenerators/codegen_utils.cpp
    codegenerators/codemethodblock.cpp
    codegenerators/codeoperation.cpp
    codegenerators/codeparameter.cpp
    codegenerators/ada/adawriter.cpp
    codegenerators/as/aswriter.cpp
    codegenerators/cpp/cppcodeclassfield.cpp
    codegenerators/cpp/cppcodecomment.cpp
    codegenerators/cpp/cppcodedocumentation.cpp
    codegenerators/cpp/cppcodegenerationform.cpp
    codegenerators/cpp/cppcodegenerationpolicy.cpp
    codegenerators/cpp/cppcodegenerationpolicypage.cpp
    codegenerators/cpp/cppcodegenerator.cpp
    codegenerators/cpp/cppheaderclassdeclarationblock.cpp
    codegenerators/cpp/cppheadercodeaccessormethod.cpp
    codegenerators/cpp/cppheadercodeclassfielddeclarationblock.cpp
    codegenerators/cpp/cppheadercodedocument.cpp
    codegenerators/cpp/cppheadercodeoperation.cpp
    codegenerators/cpp/cppmakecodedocument.cpp
    codegenerators/cpp/cppsourcecodeaccessormethod.cpp
    codegenerators/cpp/cppsourcecodeclassfielddeclarationblock.cpp
    codegenerators/cpp/cppsourcecodedocument.cpp
    codegenerators/cpp/cppsourcecodeoperation.cpp
    codegenerators/cpp/cppwriter.cpp
    codegenerators/csharp/csharpwriter.cpp
    codegenerators/d/dclassdeclarationblock.cpp
    codegenerators/d/dclassifiercodedocument.cpp
    codegenerators/d/dcodeaccessormethod.cpp
    codegenerators/d/dcodeclassfield.cpp
    codegenerators/d/dcodeclassfielddeclarationblock.cpp
    codegenerators/d/dcodecomment.cpp
    codegenerators/d/dcodedocumentation.cpp
    codegenerators/d/dcodegenerationpolicy.cpp
    codegenerators/d/dcodegenerationpolicypage.cpp
    codegenerators/d/dcodegenerator.cpp
    codegenerators/d/dcodeoperation.cpp
    codegenerators/d/dwriter.cpp
    codegenerators/hierarchicalcodeblock.cpp
    codegenerators/idl/idlwriter.cpp
    codegenerators/java/javaantcodedocument.cpp
    codegenerators/java/javaclassdeclarationblock.cpp
    codegenerators/java/javaclassifiercodedocument.cpp
    codegenerators/java/javacodeaccessormethod.cpp
    codegenerators/java/javacodeclassfield.cpp
    codegenerators/java/javacodeclassfielddeclarationblock.cpp
    codegenerators/java/javacodecomment.cpp
    codegenerators/java/javacodedocumentation.cpp
    codegenerators/java/javacodegenerationpolicy.cpp
    codegenerators/java/javacodegenerationpolicypage.cpp
    codegenerators/java/javacodegenerator.cpp
    codegenerators/java/javacodeoperation.cpp
    codegenerators/java/javawriter.cpp
    codegenerators/js/jswriter.cpp
    codegenerators/ownedcodeblock.cpp
    codegenerators/ownedhierarchicalcodeblock.cpp
    codegenerators/pascal/pascalwriter.cpp
    codegenerators/perl/perlwriter.cpp
    codegenerators/php/php5writer.cpp
    codegenerators/php/phpwriter.cpp
    codegenerators/python/pythonwriter.cpp
    codegenerators/ruby/rubyclassdeclarationblock.cpp
    codegenerators/ruby/rubyclassifiercodedocument.cpp
    codegenerators/ruby/rubycodeaccessormethod.cpp
    codegenerators/ruby/rubycodeclassfield.cpp
    codegenerators/ruby/rubycodeclassfielddeclarationblock.cpp
    codegenerators/ruby/rubycodecomment.cpp
    codegenerators/ruby/rubycodedocumentation.cpp
    codegenerators/ruby/rubycodegenerationpolicy.cpp
    codegenerators/ruby/rubycodegenerationpolicypage.cpp
    codegenerators/ruby/rubycodegenerator.cpp
    codegenerators/ruby/rubycodeoperation.cpp
    codegenerators/ruby/rubywriter.cpp
    codegenerators/simplecodegenerator.cpp
    codegenerators/sql/mysqlwriter.cpp
    codegenerators/sql/postgresqlwriter.cpp
    codegenerators/sql/sqlwriter.cpp
    codegenerators/tcl/tclwriter.cpp
    codegenerators/textblock.cpp
    codegenerators/vala/valawriter.cpp
    codegenerators/xml/xmlcodecomment.cpp
    codegenerators/xml/xmlelementcodeblock.cpp
    codegenerators/xml/xmlschemawriter.cpp
)

ki18n_wrap_ui(  libcodegenerator_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/cpp/cppcodegenerationformbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/d/dcodegenerationformbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/java/javacodegenerationformbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenerators/ruby/rubycodegenerationformbase.ui
)

set(libdocgenerator_SRCS
    docgenerators/docbook2xhtmlgeneratorjob.cpp
    docgenerators/docbookgenerator.cpp
    docgenerators/docbookgeneratorjob.cpp
    docgenerators/xhtmlgenerator.cpp
)

set(libdialogs_SRCS
    dialogs/activitydialog.cpp
    dialogs/associationpropertiesdialog.cpp
    dialogs/classpropertiesdialog.cpp
    dialogs/classwizard.cpp
    dialogs/codeeditor.cpp
    dialogs/codetextedit.cpp
    dialogs/codetexthighlighter.cpp
    dialogs/codeviewerdialog.cpp
    dialogs/diagramselectiondialog.cpp
    dialogs/dialog_utils.cpp
    dialogs/dontaskagain.cpp
    dialogs/exportallviewsdialog.cpp
    dialogs/finddialog.cpp
    dialogs/messagewidgetpropertiesdialog.cpp
    dialogs/multipagedialogbase.cpp
    dialogs/notedialog.cpp
    dialogs/objectnodedialog.cpp
    dialogs/overwritedialog.cpp
    dialogs/parameterpropertiesdialog.cpp
    dialogs/selectoperationdialog.cpp
    dialogs/settingsdialog.cpp
    dialogs/singlepagedialogbase.cpp
    dialogs/statedialog.cpp
    dialogs/umlattributedialog.cpp
    dialogs/umlinstanceattributedialog.cpp
    dialogs/umlcheckconstraintdialog.cpp
    dialogs/umlentityattributedialog.cpp
    dialogs/umlenumliteraldialog.cpp
    dialogs/umlfiledialog.cpp
    dialogs/umlforeignkeyconstraintdialog.cpp
    dialogs/umloperationdialog.cpp
    dialogs/umlroledialog.cpp
    dialogs/umltemplatedialog.cpp
    dialogs/umluniqueconstraintdialog.cpp
    dialogs/umlviewdialog.cpp
    dialogs/pages/activitypage.cpp
    dialogs/pages/notepage.cpp
    dialogs/pages/associationgeneralpage.cpp
    dialogs/pages/associationrolepage.cpp
    dialogs/pages/autolayoutoptionpage.cpp
    dialogs/pages/classassociationspage.cpp
    dialogs/pages/classgeneralpage.cpp
    dialogs/pages/classifierlistpage.cpp
    dialogs/pages/classoptionspage.cpp
    dialogs/pages/codegenerationpolicypage.cpp
    dialogs/pages/codeimportoptionspage.cpp
    dialogs/pages/codevieweroptionspage.cpp
    dialogs/pages/constraintlistpage.cpp
    dialogs/pages/defaultcodegenpolicypage.cpp
    dialogs/pages/diagramprintpage.cpp
    dialogs/pages/diagrampropertiespage.cpp
    dialogs/pages/dialogpagebase.cpp
    dialogs/pages/generaloptionpage.cpp
    dialogs/pages/packagecontentspage.cpp
    dialogs/pages/selectoperationpage.cpp
    dialogs/pages/uioptionspage.cpp
    dialogs/pages/umlroleproperties.cpp
    dialogs/pages/umlwidgetstylepage.cpp
    dialogs/widgets/documentationwidget.cpp
    dialogs/widgets/imagetypewidget.cpp
    dialogs/widgets/resolutionwidget.cpp
    dialogs/widgets/umlartifacttypewidget.cpp
    dialogs/widgets/umldatatypewidget.cpp
    dialogs/widgets/defaultvaluewidget.cpp
    dialogs/widgets/umlobjectnamewidget.cpp
    dialogs/widgets/umlpackagewidget.cpp
    dialogs/widgets/umlstereotypewidget.cpp
    dialogs/widgets/visibilityenumwidget.cpp
)

ki18n_wrap_ui(  libdialogs_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/codeviewerdialogbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/codevieweroptionsbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/exportallviewsdialogbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/finddialog.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/pages/autolayoutoptionpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/pages/codeimportoptionspage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/pages/diagrampropertiespage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/pages/umlrolepropertiesbase.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/dialogs/umlinstanceattributedialog.ui
)

set(librefactoring_SRCS
    refactoring/refactoringassistant.cpp
)

set(libcodegenwizard_SRCS
    codegenwizard/codegenerationwizard.cpp
    codegenwizard/codegenoptionspage.cpp
    codegenwizard/codegenselectpage.cpp
    codegenwizard/codegenstatuspage.cpp
)

ki18n_wrap_ui(  libcodegenwizard_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenwizard/codegenoptionspage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenwizard/codegenselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codegenwizard/codegenstatuspage.ui
)

set(libcodeimpwizard_SRCS
    codeimpwizard/codeimportingwizard.cpp
    codeimpwizard/codeimpselectpage.cpp
    codeimpwizard/codeimpstatuspage.cpp
    codeimpwizard/codeimpthread.cpp
)

ki18n_wrap_ui(  libcodeimpwizard_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/codeimpwizard/codeimpselectpage.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/codeimpwizard/codeimpstatuspage.ui
)

set(libcodeimport_SRCS
    codeimport/adaimport.cpp
    codeimport/classimport.cpp
    codeimport/idlimport.cpp
    codeimport/import_utils.cpp
    codeimport/javaimport.cpp
    codeimport/nativeimportbase.cpp
    codeimport/pascalimport.cpp
    codeimport/pythonimport.cpp
    codeimport/sqlimport.cpp
    codeimport/csharp/csharpimport.cpp
)
if(BUILD_PHP_IMPORT)
    list(APPEND libcodeimport_SRCS
        codeimport/phpimport.cpp
    )
endif()

list(APPEND libcodeimport_SRCS
    codeimport/cppimport.cpp
)

set(libkdevcppparser_SRCS
    ${CMAKE_SOURCE_DIR}/lib/cppparser/ast.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/ast_utils.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/cachemanager.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/driver.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/errors.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/lexer.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/lexercache.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/lookup.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/parser.cpp
    ${CMAKE_SOURCE_DIR}/lib/cppparser/tree_parser.cpp
    ${CMAKE_SOURCE_DIR}/lib/interfaces/hashedstring.cpp
    codeimport/kdevcppparser/cpptree2uml.cpp
)

add_library(codeimport STATIC ${libcodeimport_SRCS} ${libkdevcppparser_SRCS})
if(NOT BUILD_KF5)
    if(BUILD_PHP_IMPORT)
        target_link_libraries(codeimport
            ${KDEVPLATFORM_INTERFACES_LIBRARIES}
            ${KDEVPLATFORM_LANGUAGE_LIBRARIES}
            ${KDEVPLATFORM_OUTPUTVIEW_LIBRARIES}
            ${KDEVPLATFORM_PROJECT_LIBRARIES}
            ${KDEVPLATFORM_SUBLIME_LIBRARIES}
            ${KDEVPLATFORM_SHELL_LIBRARIES}
            ${KDEVPLATFORM_UTIL_LIBRARIES}
            ${KDEVPLATFORM_VCS_LIBRARIES}
            ${KDEVPLATFORM_DEBUGGER_LIBRARIES}
            ${KDEVPLATFORM_DOCUMENTATION_LIBRARIES}
            ${KDEVPLATFORM_TESTS_LIBRARIES}
            ${KDEVPLATFORM_JSONTESTS_LIBRARIES}
            kdev4phpparser
        )
    endif()
else()
    target_link_libraries(codeimport
        KF5::KDELibs4Support
    )
    if(BUILD_PHP_IMPORT)
        target_link_libraries(codeimport
            KDev::Interfaces
            KDev::Language
            KDev::Tests
            kdevphpparser
        )
    endif()
endif()

set(libclipboard_SRCS
    clipboard/idchangelog.cpp
    clipboard/umlclipboard.cpp
    clipboard/umldragdata.cpp
)

set(libcmds_SRCS
    cmds/cmdbaseobjectcommand.cpp
    cmds/cmdcreatediagram.cpp
    cmds/cmdhandlerename.cpp
    cmds/cmdremovediagram.cpp
    cmds/cmdsetstereotype.cpp
    cmds/cmdsetvisibility.cpp
    cmds/generic/cmdrenameumlinstancetype.cpp
    cmds/generic/cmdcreateumlobject.cpp
    cmds/generic/cmdremoveumlobject.cpp
    cmds/generic/cmdrenameumlobject.cpp
    cmds/widget/cmdbasewidgetcommand.cpp
    cmds/widget/cmdchangefont.cpp
    cmds/widget/cmdchangetextcolor.cpp
    cmds/widget/cmdchangelinecolor.cpp
    cmds/widget/cmdchangelinewidth.cpp
    cmds/widget/cmdchangefillcolor.cpp
    cmds/widget/cmdchangeusefillcolor.cpp
    cmds/widget/cmdchangemultiplicity.cpp
    cmds/widget/cmdchangevisualproperty.cpp
    cmds/widget/cmdcreatewidget.cpp
    cmds/widget/cmdmovewidget.cpp
    cmds/widget/cmdresizewidget.cpp
    cmds/widget/cmdremovewidget.cpp
    cmds/widget/cmdsetname.cpp
    cmds/widget/cmdsettxt.cpp
)
set(libmenus_SRCS
    menus/listpopupmenu.cpp
    menus/umllistviewpopupmenu.cpp
    menus/umlscenepopupmenu.cpp
    menus/associationwidgetpopupmenu.cpp
    menus/widgetbasepopupmenu.cpp
    menus/dialogspopupmenu.cpp
)

set(libumlwidgets_SRCS
    umlwidgets/activitywidget.cpp
    umlwidgets/actorwidget.cpp
    umlwidgets/artifactwidget.cpp
    umlwidgets/associationline.cpp
    umlwidgets/associationwidget.cpp
    umlwidgets/boxwidget.cpp
    umlwidgets/categorywidget.cpp
    umlwidgets/childwidgetplacement.cpp
    umlwidgets/childwidgetplacementpin.cpp
    umlwidgets/childwidgetplacementport.cpp
    umlwidgets/classifierwidget.cpp
    umlwidgets/combinedfragmentwidget.cpp
    umlwidgets/componentwidget.cpp
    umlwidgets/datatypewidget.cpp
    umlwidgets/entitywidget.cpp
    umlwidgets/enumwidget.cpp
    umlwidgets/floatingdashlinewidget.cpp
    umlwidgets/floatingtextwidget.cpp
    umlwidgets/forkjoinwidget.cpp
    umlwidgets/interfacewidget.cpp
    umlwidgets/layoutgrid.cpp
    umlwidgets/linkwidget.cpp
    umlwidgets/messagewidget.cpp
    umlwidgets/nodewidget.cpp
    umlwidgets/notewidget.cpp
    umlwidgets/objectnodewidget.cpp
    umlwidgets/objectwidget.cpp
    umlwidgets/packagewidget.cpp
    umlwidgets/pinportbase.cpp
    umlwidgets/pinwidget.cpp
    umlwidgets/portwidget.cpp
    umlwidgets/preconditionwidget.cpp
    umlwidgets/regionwidget.cpp
    umlwidgets/seqlinewidget.cpp
    umlwidgets/signalwidget.cpp
    umlwidgets/statewidget.cpp
    umlwidgets/toolbarstateonewidget.cpp
    umlwidgets/umlwidget.cpp
    umlwidgets/usecasewidget.cpp
    umlwidgets/widget_factory.cpp
    umlwidgets/widget_utils.cpp
    umlwidgets/widgetbase.cpp
    umlwidgets/widgetlist_utils.cpp
    umlwidgets/statusbartoolbutton.cpp
)

set(libfinder_SRCS
    finder/findresults.cpp
    finder/umldocfinder.cpp
    finder/umlfinder.cpp
    finder/umllistviewfinder.cpp
    finder/umlscenefinder.cpp
)

set(libuml_SRCS
    uml1model/actor.cpp
    uml1model/artifact.cpp
    uml1model/association.cpp
    uml1model/attribute.cpp
    uml1model/category.cpp
    uml1model/checkconstraint.cpp
    uml1model/classifier.cpp
    uml1model/classifierlistitem.cpp
    uml1model/component.cpp
    uml1model/datatype.cpp
    uml1model/entity.cpp
    uml1model/entityattribute.cpp
    uml1model/entityconstraint.cpp
    uml1model/enum.cpp
    uml1model/enumliteral.cpp
    uml1model/folder.cpp
    uml1model/foreignkeyconstraint.cpp
    uml1model/node.cpp
    uml1model/operation.cpp
    uml1model/package.cpp
    uml1model/port.cpp
    uml1model/stereotype.cpp
    uml1model/template.cpp
    uml1model/umlattributelist.cpp
    uml1model/umlcanvasobject.cpp
    uml1model/umlclassifierlistitemlist.cpp
    uml1model/umlentityattributelist.cpp
    uml1model/umlentityconstraintlist.cpp
    uml1model/umlobject.cpp
    uml1model/umlobjectlist.cpp
    uml1model/umlrole.cpp
    uml1model/usecase.cpp
    uml1model/uniqueconstraint.cpp
    uml1model/instance.cpp
    uml1model/instanceattribute.cpp
)

set(umbrellobase_SRCS
    assocrules.cpp
    basictypes.cpp
    birdview.cpp
    codeviewerstate.cpp
    cmdlineexportallviewsevent.cpp
    diagramswindow.cpp
    diagram_utils.cpp
    objectswindow.cpp
    docwindow.cpp
    dotgenerator.cpp
    icon_utils.cpp
    import_argo.cpp
    import_rose.cpp
    layoutgenerator.cpp
    model_utils.cpp
    object_factory.cpp
    optionstate.cpp
    petalnode.cpp
    petaltree2uml.cpp
    stereotypeswindow.cpp
    toolbarstatearrow.cpp
    toolbarstateassociation.cpp
    toolbarstate.cpp
    toolbarstatefactory.cpp
    toolbarstatemessages.cpp
    toolbarstateother.cpp
    toolbarstatepool.cpp
    umlappprivate.cpp
    uml.cpp
    umldoc.cpp
    umllistview.cpp
    umllistviewitem.cpp
    umlscene.cpp
    umlview.cpp
    umlviewimageexporterall.cpp
    umlviewimageexporter.cpp
    umlviewimageexportermodel.cpp
    uniqueid.cpp
    worktoolbar.cpp
)

set(umbrellomodels_SRCS
    models/diagramsmodel.cpp
    models/objectsmodel.cpp
    models/stereotypesmodel.cpp
)

kconfig_add_kcfg_files(umbrellobase_SRCS umbrellosettings.kcfgc)

set(libumbrello_SRCS
    ${libdebug_SRCS}
    ${libdialogs_SRCS}
    ${libfinder_SRCS}
    ${librefactoring_SRCS}
    ${libcodegenwizard_SRCS}
    ${libcodeimpwizard_SRCS}
    ${libclassparser_SRCS}
    ${libclipboard_SRCS}
    ${libcodegenerator_SRCS}
    ${libdocgenerator_SRCS}
    ${libcmds_SRCS}
    ${libmenus_SRCS}
    ${libuml_SRCS}
    ${libumlwidgets_SRCS}
    ${umbrellobase_SRCS}
    ${umbrellomodels_SRCS}
)

set(umbrello_SRCS
    main.cpp
)

set(LIB_BUILD_MODE STATIC)

if(NOT BUILD_KF5)
    if(CMAKE_MAJOR_VERSION LESS 3)
        qt4_add_resources(libumbrello_SRCS icons.qrc)
    else()
        list(APPEND libumbrello_SRCS icons.qrc)
    endif()
    kde4_add_library(libumbrello ${LIB_BUILD_MODE} ${libumbrello_SRCS})
    set_target_properties(libumbrello PROPERTIES OUTPUT_NAME umbrello)
    target_link_libraries(libumbrello
        Qt4::QtCore
        Qt4::QtGui
        Qt4::QtXml
        Qt4::QtWebKit
        ${LIBXML2_LIBRARIES}
        ${LIBXSLT_LIBRARIES}
        ${KDE4_KTEXTEDITOR_LIBS}
        ${KDE4_KFILE_LIBS}
        codeimport
    )

    kde4_add_app_icon(umbrello_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/pics/global/hi*-apps-umbrello.png")
    kde4_add_executable(umbrello ${umbrello_SRCS})
    target_link_libraries(umbrello ${LIBXML2_LIBRARIES} ${LIBXSLT_LIBRARIES} ${KDE4_KTEXTEDITOR_LIBS} ${KDE4_KFILE_LIBS} libumbrello)
else()
    if(CMAKE_MAJOR_VERSION LESS 3)
        qt5_add_resources(libumbrello_SRCS icons.qrc ${CMAKE_CURRENT_BINARY_DIR}/ui.qrc)
    else()
        list(APPEND libumbrello_SRCS icons.qrc ${CMAKE_CURRENT_BINARY_DIR}/ui.qrc)
    endif()
    add_library(libumbrello ${LIB_BUILD_MODE} ${libumbrello_SRCS})
    set_target_properties(libumbrello PROPERTIES OUTPUT_NAME umbrello)
    target_link_libraries(libumbrello
        Qt5::Widgets
        Qt5::Xml
        Qt5::PrintSupport
        Qt5::Svg
        Qt5::WebKitWidgets
        KF5::Archive
        KF5::Completion
        KF5::CoreAddons
        KF5::I18n
        KF5::IconThemes
        KF5::KIOCore
        KF5::KDELibs4Support
        KF5::TextEditor
        KF5::WidgetsAddons
        KF5::XmlGui
        KF5::Crash
        ${LIBXSLT_LIBRARIES}
        ${LIBXML2_LIBRARIES}
        codeimport
    )
    ecm_add_app_icon(umbrello_SRCS
        ICONS
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/16-apps-umbrello.png
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/22-apps-umbrello.png
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/32-apps-umbrello.png
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/48-apps-umbrello.png
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/64-apps-umbrello.png
        ${CMAKE_CURRENT_SOURCE_DIR}/pics/global/128-apps-umbrello.png
    )
    add_executable(umbrello ${umbrello_SRCS})
    target_link_libraries(umbrello
        libumbrello
        KF5::Crash
        KF5::WindowSystem
        KF5::KDELibs4Support
    )
    set_target_properties(umbrello PROPERTIES OUTPUT_NAME umbrello5)
endif()

target_compile_definitions(libumbrello PRIVATE -DQT_NO_CAST_TO_ASCII -DQT_NO_CAST_FROM_ASCII)

if(LIB_BUILD_MODE EQUAL SHARED)
    install(TARGETS libumbrello ${INSTALL_TARGETS_DEFAULT_ARGS} )
endif()
install(TARGETS umbrello ${INSTALL_TARGETS_DEFAULT_ARGS} )

########### install files #############

if(NOT BUILD_KF5)
    install( PROGRAMS org.kde.umbrello.desktop DESTINATION  ${XDG_APPS_INSTALL_DIR} )
    install( FILES
        ${CMAKE_CURRENT_BINARY_DIR}/umbrelloui.rc
        DESTINATION ${UMBRELLO_DATA_INSTALL_DIR} )
else()
    file(READ org.kde.umbrello.desktop UMBRELLO_DESKTOP_OUT)
    string(REPLACE "Exec=umbrello" "Exec=umbrello5" UMBRELLO_DESKTOP_OUT "${UMBRELLO_DESKTOP_OUT}")
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/org.kde.umbrello.desktop "${UMBRELLO_DESKTOP_OUT}")
    install( PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/org.kde.umbrello.desktop DESTINATION  ${XDG_APPS_INSTALL_DIR})
    install(FILES org.kde.umbrello.appdata.xml  DESTINATION  ${KDE_INSTALL_METAINFODIR})
endif()

install( DIRECTORY
    layouts
    DESTINATION ${UMBRELLO_DATA_INSTALL_DIR}
    PATTERN .svn EXCLUDE )

add_subdirectory( pics )
