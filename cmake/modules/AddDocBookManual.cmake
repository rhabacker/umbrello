option(ENABLE_DOCBOOK_HTML "Docbook html export" OFF)
find_package(DocBookXSL)
find_program(XSLTPROC_EXECUTABLE xsltproc)
add_feature_info("Docbook html export" "ENABLE_DOCBOOK_HTML;DocBookXSL_FOUND;XSLTPROC_EXECUTABLE" "Add support to export the manual as html file")
option(ENABLE_DOCBOOK_HTML_INSTALL "Install manuals in HTML format" OFF)


function(add_docbook_manual)
    # Arguments per CMake docs
    set(options INSTALL)
    set(oneValueArgs TARGET_NAME DOCBOOK_SRC SRC_DIR OUTPUT_DIR INSTALL_DIR CUSTOM_CSS COMMON_ASSETS_DIR)
    set(multiValueArgs)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # Required args
    foreach(param TARGET_NAME DOCBOOK_SRC SRC_DIR OUTPUT_DIR INSTALL_DIR)
        if(NOT ARG_${param})
            message(FATAL_ERROR "add_docbook_manual: ${param} is required")
        endif()
    endforeach()

    # Asset patterns (same idea as install, excluding *.html)
    set(DOCBOOK_ASSET_PATTERNS
        "*.png" "*.jpg" "*.jpeg" "*.gif" "*.svg" "*.css" "*.js"
    )

    # Optional CSS parameter (and dependency for rebuild-on-change)
    if(ARG_CUSTOM_CSS)
        set(_css_param --stringparam html.stylesheet "${ARG_CUSTOM_CSS}")
        set(_css_dep   "${ARG_CUSTOM_CSS}")
    else()
        set(_css_param)
        set(_css_dep)
    endif()

    set(_html "${ARG_OUTPUT_DIR}/index.html")

    # ---- Collect language-specific assets (preserve tree) ----
    set(_lang_globs)
    foreach(p IN LISTS DOCBOOK_ASSET_PATTERNS)
        list(APPEND _lang_globs "${ARG_SRC_DIR}/${p}")
    endforeach()
    file(GLOB_RECURSE _assets_lang RELATIVE "${ARG_SRC_DIR}" ${_lang_globs})

    set(_copied_files)
    foreach(_rel IN LISTS _assets_lang)
        set(_src "${ARG_SRC_DIR}/${_rel}")
        set(_dst "${ARG_OUTPUT_DIR}/${_rel}")
        get_filename_component(_dir "${_dst}" DIRECTORY)
        add_custom_command(
            OUTPUT "${_dst}"
            COMMAND ${CMAKE_COMMAND} -E make_directory "${_dir}"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${_src}" "${_dst}"
            DEPENDS "${_src}"
            VERBATIM
        )
        list(APPEND _copied_files "${_dst}")
    endforeach()

    # ---- Collect missing assets from COMMON_ASSETS_DIR (if provided) ----
    if(ARG_COMMON_ASSETS_DIR)
        set(_common_globs)
        foreach(p IN LISTS DOCBOOK_ASSET_PATTERNS)
            list(APPEND _common_globs "${ARG_COMMON_ASSETS_DIR}/${p}")
        endforeach()
        file(GLOB_RECURSE _assets_common RELATIVE "${ARG_COMMON_ASSETS_DIR}" ${_common_globs})

        foreach(_rel IN LISTS _assets_common)
            if(NOT EXISTS "${ARG_SRC_DIR}/${_rel}")
                set(_src "${ARG_COMMON_ASSETS_DIR}/${_rel}")
                set(_dst "${ARG_OUTPUT_DIR}/${_rel}")
                get_filename_component(_dir "${_dst}" DIRECTORY)
                add_custom_command(
                    OUTPUT "${_dst}"
                    COMMAND ${CMAKE_COMMAND} -E make_directory "${_dir}"
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${_src}" "${_dst}"
                    DEPENDS "${_src}"
                    VERBATIM
                )
                list(APPEND _copied_files "${_dst}")
            endif()
        endforeach()
    endif()

    # Target to copy all assets (only if there are any)
    if(_copied_files)
        add_custom_target(copy-assets-${ARG_TARGET_NAME} DEPENDS ${_copied_files})
    endif()

    # ---- Generate the HTML output with xsltproc ----
    add_custom_command(
        OUTPUT "${_html}"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${ARG_OUTPUT_DIR}"
        COMMAND ${XSLTPROC_EXECUTABLE}
                --nonet
                --param passivetex.extensions '1'
                --param generate.consistent.ids '1'
                --path ${KDOCTOOLS_CUSTOMIZATION_DIR}/dtd
                --output "${_html}"
                ${_css_param}
                --xinclude
                "${DOCBOOKXSL_DIR}/xhtml/docbook.xsl"
                "${ARG_DOCBOOK_SRC}"
        DEPENDS "${ARG_DOCBOOK_SRC}" ${_css_dep} ${_copied_files}
        WORKING_DIRECTORY "${ARG_SRC_DIR}"
        COMMENT "Generating single-page HTML manual: ${ARG_TARGET_NAME}"
        VERBATIM
    )

    # Main target (like original, built by default)
    add_custom_target(${ARG_TARGET_NAME} ALL DEPENDS "${_html}")
    if(TARGET copy-assets-${ARG_TARGET_NAME})
        add_dependencies(${ARG_TARGET_NAME} copy-assets-${ARG_TARGET_NAME})
    endif()

    # Optional installation (matches patterns incl. HTML)
    if(ARG_INSTALL)
        install(DIRECTORY "${ARG_OUTPUT_DIR}/"
            DESTINATION "${ARG_INSTALL_DIR}"
            FILES_MATCHING
                PATTERN "*.html"
                PATTERN "*.png"
                PATTERN "*.jpg"
                PATTERN "*.jpeg"
                PATTERN "*.gif"
                PATTERN "*.svg"
                PATTERN "*.css"
                PATTERN "*.js"
        )
    endif()
endfunction()
