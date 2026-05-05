find_package(antlr4-runtime 4.13 CONFIG REQUIRED)

set(ADA95_DATA_DIR ${CMAKE_SOURCE_DIR}/3rdparty/grammars-v4/ada)

add_custom_target(generate_ada95_parser
    COMMAND antlr4 -Dlanguage=Cpp -listener ada95/Ada95Lexer.g4 -o ada95
    COMMAND antlr4 -Dlanguage=Cpp -listener -lib ada95/ada95 ada95/Ada95Lexer.g4 ada95/Ada95Parser.g4 -o ada95
    WORKING_DIRECTORY ${ADA95_DATA_DIR}
)

set(ADA95_PARSER_DIR ${ADA95_DATA_DIR}/ada95/ada95)
set(ADA95_IMPORT_SOURCES
    ada95import.cpp
    ada95import.h
    ${ADA95_PARSER_DIR}/Ada95Lexer.cpp
    ${ADA95_PARSER_DIR}/Ada95Lexer.h
    ${ADA95_PARSER_DIR}/Ada95Parser.cpp
    ${ADA95_PARSER_DIR}/Ada95Parser.h
    ${ADA95_PARSER_DIR}/Ada95ParserBaseListener.cpp
    ${ADA95_PARSER_DIR}/Ada95ParserBaseListener.h
    ${ADA95_PARSER_DIR}/Ada95ParserListener.cpp
    ${ADA95_PARSER_DIR}/Ada95ParserListener.h
)

add_library(ada95import STATIC ${ADA95_IMPORT_SOURCES})
target_compile_options(ada95import PRIVATE -fexceptions -DANTLR4_USE_THREAD_LOCAL_CACHE)
target_include_directories(ada95import
    PRIVATE
        ${ADA95_PARSER_DIR}
        ${ANTLR4_INCLUDE_DIR}
)
target_link_libraries(ada95import
    PRIVATE
        antlr4_shared
        Qt::Widgets
        Qt::Xml
)
set(ADA95IMPORT_LIBRARY ada95import PARENT_SCOPE)
