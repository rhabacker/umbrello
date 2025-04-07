

if(UNIX)
    add_test(
        NAME lint-xmi-files
        COMMAND ${CMAKE_SOURCE_DIR}/tools/lint-xmi-files
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()

