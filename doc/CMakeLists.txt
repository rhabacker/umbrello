########### install files ###############
kdoctools_create_handbook(index.docbook INSTALL_DESTINATION ${KDE_INSTALL_DOCBUNDLEDIR}/en SUBDIR umbrello)

add_subdirectory(apphelp)

include(AddDocBookManual)

if(ENABLE_DOCBOOK_HTML AND DocBookXSL_FOUND AND XSLTPROC_EXECUTABLE)
    if(ENABLE_DOCBOOK_HTML_INSTALL)
        set(INSTALL_OPT INSTALL)
    endif()
    add_docbook_manual(
        TARGET_NAME doc-en-index-html
        DOCBOOK_SRC ${CMAKE_SOURCE_DIR}/doc/index.docbook
        SRC_DIR ${CMAKE_SOURCE_DIR}/doc
        CUSTOM_CSS umbrello.css
        OUTPUT_DIR ${CMAKE_BINARY_DIR}/doc/en/umbrello
        INSTALL_DIR ${KDE_INSTALL_DOCBUNDLEDIR}/en/umbrello
        ${INSTALL_OPT}
    )
    list(APPEND ALL_MANUAL_TARGETS doc-en-index-html)

    file(GLOB LANG_DIRS RELATIVE ${CMAKE_SOURCE_DIR}/po ${CMAKE_SOURCE_DIR}/po/*)
    set(_langs)
    foreach(lang ${LANG_DIRS})
        set(SOURCE ${CMAKE_SOURCE_DIR}/po/${lang}/docs/umbrello/index.docbook)
        if(EXISTS ${SOURCE})
            list(APPEND _langs ${lang})
            add_docbook_manual(
                TARGET_NAME doc-${lang}-index-html
                DOCBOOK_SRC ${SOURCE}
                COMMON_ASSETS_DIR ${CMAKE_SOURCE_DIR}/doc
                CUSTOM_CSS umbrello.css
                OUTPUT_DIR ${CMAKE_BINARY_DIR}/po/${lang}/docs/umbrello
                SRC_DIR ${CMAKE_SOURCE_DIR}/po/${lang}/docs/umbrello
                INSTALL_DIR ${KDE_INSTALL_DOCBUNDLEDIR}/${lang}/umbrello
                ${INSTALL_OPT}
            )
            list(APPEND ALL_MANUAL_TARGETS doc-${lang}-index-html)
        endif()
    endforeach()
    message(STATUS "Generating manual in html format for '${_langs}'")
    # Create an aggregate target that depends on all manual targets
    add_custom_target(doc-html ALL
        DEPENDS ${ALL_MANUAL_TARGETS}
        COMMENT "Build all DocBook HTML manuals"
    )
endif()
