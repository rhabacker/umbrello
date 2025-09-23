
// Generated from ada95/Ada95Lexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Ada95Lexer : public antlr4::Lexer {
public:
  enum {
    ABORT = 1, ABS = 2, ABSTRACT = 3, ACCEPT_ = 4, ACCESS = 5, ALIASED = 6, 
    ALL = 7, AND = 8, ARRAY = 9, AT = 10, BEGIN = 11, BODY_ = 12, CASE = 13, 
    CONSTANT = 14, DECLARE = 15, DELAY = 16, DELTA = 17, DIGITS = 18, DO = 19, 
    ELSE = 20, ELSIF = 21, END = 22, ENTRY = 23, EXCEPTION = 24, EXIT = 25, 
    FOR = 26, FUNCTION = 27, GENERIC = 28, GOTO = 29, IF = 30, IN = 31, 
    IS = 32, LIMITED = 33, LOOP = 34, MOD = 35, NEW = 36, NOT = 37, NULL_ = 38, 
    OF = 39, OR = 40, OTHERS = 41, OUT = 42, PACKAGE = 43, PRAGMA = 44, 
    PRIVATE = 45, PROCEDURE = 46, PROTECTED = 47, RAISE = 48, RANGE_ = 49, 
    RECORD = 50, REM = 51, RENAMES = 52, REQUEUE = 53, RETURN = 54, REVERSE = 55, 
    SELECT = 56, SEPARATE = 57, SUBTYPE = 58, TAGGED = 59, TASK = 60, TERMINATE = 61, 
    THEN = 62, TYPE = 63, UNTIL = 64, USE = 65, WHEN = 66, WHILE = 67, WITH = 68, 
    XOR = 69, WHITESPACE = 70, LINE_COMMENT = 71, IDENTIFIER_ = 72, NUMERIC_LITERAL_ = 73, 
    DECIMAL_LITERAL_ = 74, NUMERAL = 75, EXPONENT = 76, BASED_LITERAL = 77, 
    BASED_NUMERAL = 78, EXTENDED_DIGIT = 79, BASE = 80, CHARACTER_LITERAL = 81, 
    STRING_LITERAL_ = 82, HASH = 83, AMPERSAND = 84, LP = 85, RP = 86, MULT = 87, 
    PLUS = 88, COMMA = 89, MINUS = 90, DOT = 91, COLON = 92, SEMI = 93, 
    LT = 94, EQ = 95, GT = 96, US = 97, VL = 98, DIV = 99, EP = 100, PS = 101, 
    ARROW = 102, DOTDOT = 103, EXPON = 104, ASSIGN = 105, NE = 106, GE = 107, 
    LE = 108, LLB = 109, RLB = 110, BOX = 111, SQ = 112
  };

  explicit Ada95Lexer(antlr4::CharStream *input);

  ~Ada95Lexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

