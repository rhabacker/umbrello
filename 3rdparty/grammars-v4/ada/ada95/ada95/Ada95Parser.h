
// Generated from ada95/Ada95Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  Ada95Parser : public antlr4::Parser {
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

  enum {
    RuleIdentifier = 0, RuleNumeric_literal = 1, RuleCharacter_literal = 2, 
    RuleString_literal = 3, RuleBasic_declaration = 4, RuleDefining_identifier = 5, 
    RuleType_declaration = 6, RuleFull_type_declaration = 7, RuleType_definition = 8, 
    RuleSubtype_declaration = 9, RuleSubtype_indication = 10, RuleConstraint = 11, 
    RuleScalar_constraint = 12, RuleComposite_constraint = 13, RuleObject_declaration = 14, 
    RuleDefining_identifier_list = 15, RuleNumber_declaration = 16, RuleDerived_type_definition = 17, 
    RuleRange_constraint = 18, RuleRange = 19, RuleEnumeration_type_definition = 20, 
    RuleEnumeration_literal_specification = 21, RuleDefining_character_literal = 22, 
    RuleInteger_type_definition = 23, RuleSigned_integer_type_definition = 24, 
    RuleModular_type_definition = 25, RuleReal_type_definition = 26, RuleFloating_point_definition = 27, 
    RuleReal_range_specification = 28, RuleFixed_point_definition = 29, 
    RuleOrdinary_fixed_point_definition = 30, RuleDecimal_fixed_point_definition = 31, 
    RuleDigits_constraint = 32, RuleArray_type_definition = 33, RuleUnconstrained_array_definition = 34, 
    RuleIndex_subtype_definition = 35, RuleConstrained_array_definition = 36, 
    RuleDiscrete_subtype_definition = 37, RuleComponent_definition = 38, 
    RuleIndex_constraint = 39, RuleDiscrete_range = 40, RuleDiscriminant_part = 41, 
    RuleUnknown_discriminant_part = 42, RuleKnown_discriminant_part = 43, 
    RuleDiscriminant_specification = 44, RuleDefault_expression = 45, RuleDiscriminant_constraint = 46, 
    RuleDiscriminant_association = 47, RuleRecord_type_definition = 48, 
    RuleRecord_definition = 49, RuleComponent_list = 50, RuleComponent_item = 51, 
    RuleComponent_declaration = 52, RuleVariant_part = 53, RuleVariant = 54, 
    RuleDiscrete_choice_list = 55, RuleDiscrete_choice = 56, RuleRecord_extension_part = 57, 
    RuleAccess_type_definition = 58, RuleAccess_to_object_definition = 59, 
    RuleGeneral_access_modifier = 60, RuleAccess_to_subprogram_definition = 61, 
    RuleAccess_definition = 62, RuleIncomplete_type_declaration = 63, RuleDeclarative_part = 64, 
    RuleDeclarative_item = 65, RuleBasic_declarative_item = 66, RuleBody = 67, 
    RuleProper_body = 68, RuleName = 69, RuleDirect_name = 70, RuleSelector_name = 71, 
    RuleAttribute_designator = 72, RuleRange_attribute_reference = 73, RuleRange_attribute_designator = 74, 
    RuleAggregate = 75, RuleRecord_aggregate = 76, RuleRecord_component_association_list = 77, 
    RuleRecord_component_association = 78, RuleComponent_choice_list = 79, 
    RuleExtension_aggregate = 80, RuleAncestor_part = 81, RuleArray_aggregate = 82, 
    RulePositional_array_aggregate = 83, RuleNamed_array_aggregate = 84, 
    RuleArray_component_association = 85, RuleExpression = 86, RuleRelation = 87, 
    RuleSimple_expression = 88, RuleTerm = 89, RuleFactor = 90, RulePrimary = 91, 
    RuleLogical_operator = 92, RuleRelational_operator = 93, RuleBinary_adding_operator = 94, 
    RuleUnary_adding_operator = 95, RuleMultiplying_operator = 96, RuleHighest_precedence_operator = 97, 
    RuleQualified_expression = 98, RuleAllocator = 99, RuleSequence_of_statements = 100, 
    RuleStatement = 101, RuleSimple_statement = 102, RuleCompound_statement = 103, 
    RuleNull_statement = 104, RuleLabel = 105, RuleStatement_identifier = 106, 
    RuleAssignment_statement = 107, RuleIf_statement = 108, RuleCondition = 109, 
    RuleCase_statement = 110, RuleCase_statement_alternative = 111, RuleLoop_statement = 112, 
    RuleIteration_scheme = 113, RuleLoop_parameter_specification = 114, 
    RuleBlock_statement = 115, RuleExit_statement = 116, RuleGoto_statement = 117, 
    RuleSubprogram_declaration = 118, RuleAbstract_subprogram_declaration = 119, 
    RuleSubprogram_specification = 120, RuleDesignator = 121, RuleDefining_designator = 122, 
    RuleDefining_program_unit_name = 123, RuleOperator_symbol = 124, RuleDefining_operator_symbol = 125, 
    RuleParameter_profile = 126, RuleParameter_and_result_profile = 127, 
    RuleFormal_part = 128, RuleParameter_specification = 129, RuleMode_ = 130, 
    RuleSubprogram_body = 131, RuleProcedure_call_statement = 132, RuleActual_parameter_part = 133, 
    RuleParameter_association = 134, RuleExplicit_actual_parameter = 135, 
    RuleReturn_statement = 136, RulePackage_declaration = 137, RulePackage_specification = 138, 
    RulePackage_body = 139, RulePrivate_type_declaration = 140, RulePrivate_extension_declaration = 141, 
    RuleUse_clause = 142, RuleUse_package_clause = 143, RuleUse_type_clause = 144, 
    RuleRenaming_declaration = 145, RuleObject_renaming_declaration = 146, 
    RuleException_renaming_declaration = 147, RulePackage_renaming_declaration = 148, 
    RuleSubprogram_renaming_declaration = 149, RuleGeneric_renaming_declaration = 150, 
    RuleTask_type_declaration = 151, RuleSingle_task_declaration = 152, 
    RuleTask_definition = 153, RuleTask_item = 154, RuleTask_body = 155, 
    RuleProtected_type_declaration = 156, RuleSingle_protected_declaration = 157, 
    RuleProtected_definition = 158, RuleProtected_operation_declaration = 159, 
    RuleProtected_element_declaration = 160, RuleProtected_body = 161, RuleProtected_operation_item = 162, 
    RuleEntry_declaration = 163, RuleAccept_statement = 164, RuleEntry_index = 165, 
    RuleEntry_body = 166, RuleEntry_body_formal_part = 167, RuleEntry_barrier = 168, 
    RuleEntry_index_specification = 169, RuleEntry_call_statement = 170, 
    RuleRequeue_statement = 171, RuleDelay_statement = 172, RuleDelay_until_statement = 173, 
    RuleDelay_relative_statement = 174, RuleSelect_statement = 175, RuleSelective_accept = 176, 
    RuleGuard = 177, RuleSelect_alternative = 178, RuleAccept_alternative = 179, 
    RuleDelay_alternative = 180, RuleTerminate_alternative = 181, RuleTimed_entry_call = 182, 
    RuleEntry_call_alternative = 183, RuleConditional_entry_call = 184, 
    RuleAsynchronous_select = 185, RuleTriggering_alternative = 186, RuleTriggering_statement = 187, 
    RuleAbortable_part = 188, RuleAbort_statement = 189, RuleCompilation = 190, 
    RuleCompilation_unit = 191, RuleLibrary_item = 192, RuleLibrary_unit_declaration = 193, 
    RuleLibrary_unit_renaming_declaration = 194, RuleLibrary_unit_body = 195, 
    RuleParent_unit_name = 196, RuleContext_clause = 197, RuleContext_item = 198, 
    RuleWith_clause = 199, RuleBody_stub = 200, RuleSubprogram_body_stub = 201, 
    RulePackage_body_stub = 202, RuleTask_body_stub = 203, RuleProtected_body_stub = 204, 
    RuleSubunit = 205, RuleException_declaration = 206, RuleHandled_sequence_of_statements = 207, 
    RuleException_handler = 208, RuleChoice_parameter_specification = 209, 
    RuleException_choice = 210, RuleRaise_statement = 211, RuleGeneric_declaration = 212, 
    RuleGeneric_subprogram_declaration = 213, RuleGeneric_package_declaration = 214, 
    RuleGeneric_formal_part = 215, RuleGeneric_formal_parameter_declaration = 216, 
    RuleGeneric_instantiation = 217, RuleGeneric_actual_part = 218, RuleGeneric_association = 219, 
    RuleExplicit_generic_actual_parameter = 220, RuleFormal_object_declaration = 221, 
    RuleFormal_type_declaration = 222, RuleFormal_type_definition = 223, 
    RuleFormal_private_type_definition = 224, RuleFormal_derived_type_definition = 225, 
    RuleFormal_discrete_type_definition = 226, RuleFormal_signed_integer_type_definition = 227, 
    RuleFormal_modular_type_definition = 228, RuleFormal_floating_point_definition = 229, 
    RuleFormal_ordinary_fixed_point_definition = 230, RuleFormal_decimal_fixed_point_definition = 231, 
    RuleFormal_array_type_definition = 232, RuleFormal_access_type_definition = 233, 
    RuleFormal_subprogram_declaration = 234, RuleSubprogram_default = 235, 
    RuleDefault_name = 236, RuleFormal_package_declaration = 237, RuleFormal_package_actual_part = 238, 
    RuleAspect_clause = 239, RuleLocal_name = 240, RuleAttribute_definition_clause = 241, 
    RuleEnumeration_representation_clause = 242, RuleEnumeration_aggregate = 243, 
    RuleRecord_representation_clause = 244, RuleComponent_clause = 245, 
    RulePosition = 246, RuleFirst_bit = 247, RuleLast_bit = 248, RuleCode_statement = 249, 
    RuleRestriction = 250, RuleAt_clause = 251, RuleDelta_constraint = 252, 
    RuleMod_clause = 253, RuleBoolean_expression = 254
  };

  explicit Ada95Parser(antlr4::TokenStream *input);

  Ada95Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~Ada95Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class IdentifierContext;
  class Numeric_literalContext;
  class Character_literalContext;
  class String_literalContext;
  class Basic_declarationContext;
  class Defining_identifierContext;
  class Type_declarationContext;
  class Full_type_declarationContext;
  class Type_definitionContext;
  class Subtype_declarationContext;
  class Subtype_indicationContext;
  class ConstraintContext;
  class Scalar_constraintContext;
  class Composite_constraintContext;
  class Object_declarationContext;
  class Defining_identifier_listContext;
  class Number_declarationContext;
  class Derived_type_definitionContext;
  class Range_constraintContext;
  class RangeContext;
  class Enumeration_type_definitionContext;
  class Enumeration_literal_specificationContext;
  class Defining_character_literalContext;
  class Integer_type_definitionContext;
  class Signed_integer_type_definitionContext;
  class Modular_type_definitionContext;
  class Real_type_definitionContext;
  class Floating_point_definitionContext;
  class Real_range_specificationContext;
  class Fixed_point_definitionContext;
  class Ordinary_fixed_point_definitionContext;
  class Decimal_fixed_point_definitionContext;
  class Digits_constraintContext;
  class Array_type_definitionContext;
  class Unconstrained_array_definitionContext;
  class Index_subtype_definitionContext;
  class Constrained_array_definitionContext;
  class Discrete_subtype_definitionContext;
  class Component_definitionContext;
  class Index_constraintContext;
  class Discrete_rangeContext;
  class Discriminant_partContext;
  class Unknown_discriminant_partContext;
  class Known_discriminant_partContext;
  class Discriminant_specificationContext;
  class Default_expressionContext;
  class Discriminant_constraintContext;
  class Discriminant_associationContext;
  class Record_type_definitionContext;
  class Record_definitionContext;
  class Component_listContext;
  class Component_itemContext;
  class Component_declarationContext;
  class Variant_partContext;
  class VariantContext;
  class Discrete_choice_listContext;
  class Discrete_choiceContext;
  class Record_extension_partContext;
  class Access_type_definitionContext;
  class Access_to_object_definitionContext;
  class General_access_modifierContext;
  class Access_to_subprogram_definitionContext;
  class Access_definitionContext;
  class Incomplete_type_declarationContext;
  class Declarative_partContext;
  class Declarative_itemContext;
  class Basic_declarative_itemContext;
  class BodyContext;
  class Proper_bodyContext;
  class NameContext;
  class Direct_nameContext;
  class Selector_nameContext;
  class Attribute_designatorContext;
  class Range_attribute_referenceContext;
  class Range_attribute_designatorContext;
  class AggregateContext;
  class Record_aggregateContext;
  class Record_component_association_listContext;
  class Record_component_associationContext;
  class Component_choice_listContext;
  class Extension_aggregateContext;
  class Ancestor_partContext;
  class Array_aggregateContext;
  class Positional_array_aggregateContext;
  class Named_array_aggregateContext;
  class Array_component_associationContext;
  class ExpressionContext;
  class RelationContext;
  class Simple_expressionContext;
  class TermContext;
  class FactorContext;
  class PrimaryContext;
  class Logical_operatorContext;
  class Relational_operatorContext;
  class Binary_adding_operatorContext;
  class Unary_adding_operatorContext;
  class Multiplying_operatorContext;
  class Highest_precedence_operatorContext;
  class Qualified_expressionContext;
  class AllocatorContext;
  class Sequence_of_statementsContext;
  class StatementContext;
  class Simple_statementContext;
  class Compound_statementContext;
  class Null_statementContext;
  class LabelContext;
  class Statement_identifierContext;
  class Assignment_statementContext;
  class If_statementContext;
  class ConditionContext;
  class Case_statementContext;
  class Case_statement_alternativeContext;
  class Loop_statementContext;
  class Iteration_schemeContext;
  class Loop_parameter_specificationContext;
  class Block_statementContext;
  class Exit_statementContext;
  class Goto_statementContext;
  class Subprogram_declarationContext;
  class Abstract_subprogram_declarationContext;
  class Subprogram_specificationContext;
  class DesignatorContext;
  class Defining_designatorContext;
  class Defining_program_unit_nameContext;
  class Operator_symbolContext;
  class Defining_operator_symbolContext;
  class Parameter_profileContext;
  class Parameter_and_result_profileContext;
  class Formal_partContext;
  class Parameter_specificationContext;
  class Mode_Context;
  class Subprogram_bodyContext;
  class Procedure_call_statementContext;
  class Actual_parameter_partContext;
  class Parameter_associationContext;
  class Explicit_actual_parameterContext;
  class Return_statementContext;
  class Package_declarationContext;
  class Package_specificationContext;
  class Package_bodyContext;
  class Private_type_declarationContext;
  class Private_extension_declarationContext;
  class Use_clauseContext;
  class Use_package_clauseContext;
  class Use_type_clauseContext;
  class Renaming_declarationContext;
  class Object_renaming_declarationContext;
  class Exception_renaming_declarationContext;
  class Package_renaming_declarationContext;
  class Subprogram_renaming_declarationContext;
  class Generic_renaming_declarationContext;
  class Task_type_declarationContext;
  class Single_task_declarationContext;
  class Task_definitionContext;
  class Task_itemContext;
  class Task_bodyContext;
  class Protected_type_declarationContext;
  class Single_protected_declarationContext;
  class Protected_definitionContext;
  class Protected_operation_declarationContext;
  class Protected_element_declarationContext;
  class Protected_bodyContext;
  class Protected_operation_itemContext;
  class Entry_declarationContext;
  class Accept_statementContext;
  class Entry_indexContext;
  class Entry_bodyContext;
  class Entry_body_formal_partContext;
  class Entry_barrierContext;
  class Entry_index_specificationContext;
  class Entry_call_statementContext;
  class Requeue_statementContext;
  class Delay_statementContext;
  class Delay_until_statementContext;
  class Delay_relative_statementContext;
  class Select_statementContext;
  class Selective_acceptContext;
  class GuardContext;
  class Select_alternativeContext;
  class Accept_alternativeContext;
  class Delay_alternativeContext;
  class Terminate_alternativeContext;
  class Timed_entry_callContext;
  class Entry_call_alternativeContext;
  class Conditional_entry_callContext;
  class Asynchronous_selectContext;
  class Triggering_alternativeContext;
  class Triggering_statementContext;
  class Abortable_partContext;
  class Abort_statementContext;
  class CompilationContext;
  class Compilation_unitContext;
  class Library_itemContext;
  class Library_unit_declarationContext;
  class Library_unit_renaming_declarationContext;
  class Library_unit_bodyContext;
  class Parent_unit_nameContext;
  class Context_clauseContext;
  class Context_itemContext;
  class With_clauseContext;
  class Body_stubContext;
  class Subprogram_body_stubContext;
  class Package_body_stubContext;
  class Task_body_stubContext;
  class Protected_body_stubContext;
  class SubunitContext;
  class Exception_declarationContext;
  class Handled_sequence_of_statementsContext;
  class Exception_handlerContext;
  class Choice_parameter_specificationContext;
  class Exception_choiceContext;
  class Raise_statementContext;
  class Generic_declarationContext;
  class Generic_subprogram_declarationContext;
  class Generic_package_declarationContext;
  class Generic_formal_partContext;
  class Generic_formal_parameter_declarationContext;
  class Generic_instantiationContext;
  class Generic_actual_partContext;
  class Generic_associationContext;
  class Explicit_generic_actual_parameterContext;
  class Formal_object_declarationContext;
  class Formal_type_declarationContext;
  class Formal_type_definitionContext;
  class Formal_private_type_definitionContext;
  class Formal_derived_type_definitionContext;
  class Formal_discrete_type_definitionContext;
  class Formal_signed_integer_type_definitionContext;
  class Formal_modular_type_definitionContext;
  class Formal_floating_point_definitionContext;
  class Formal_ordinary_fixed_point_definitionContext;
  class Formal_decimal_fixed_point_definitionContext;
  class Formal_array_type_definitionContext;
  class Formal_access_type_definitionContext;
  class Formal_subprogram_declarationContext;
  class Subprogram_defaultContext;
  class Default_nameContext;
  class Formal_package_declarationContext;
  class Formal_package_actual_partContext;
  class Aspect_clauseContext;
  class Local_nameContext;
  class Attribute_definition_clauseContext;
  class Enumeration_representation_clauseContext;
  class Enumeration_aggregateContext;
  class Record_representation_clauseContext;
  class Component_clauseContext;
  class PositionContext;
  class First_bitContext;
  class Last_bitContext;
  class Code_statementContext;
  class RestrictionContext;
  class At_clauseContext;
  class Delta_constraintContext;
  class Mod_clauseContext;
  class Boolean_expressionContext; 

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdentifierContext* identifier();

  class  Numeric_literalContext : public antlr4::ParserRuleContext {
  public:
    Numeric_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Numeric_literalContext* numeric_literal();

  class  Character_literalContext : public antlr4::ParserRuleContext {
  public:
    Character_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Character_literalContext* character_literal();

  class  String_literalContext : public antlr4::ParserRuleContext {
  public:
    String_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  String_literalContext* string_literal();

  class  Basic_declarationContext : public antlr4::ParserRuleContext {
  public:
    Basic_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_declarationContext *type_declaration();
    Subtype_declarationContext *subtype_declaration();
    Object_declarationContext *object_declaration();
    Number_declarationContext *number_declaration();
    Subprogram_declarationContext *subprogram_declaration();
    Abstract_subprogram_declarationContext *abstract_subprogram_declaration();
    Package_declarationContext *package_declaration();
    Renaming_declarationContext *renaming_declaration();
    Exception_declarationContext *exception_declaration();
    Generic_declarationContext *generic_declaration();
    Generic_instantiationContext *generic_instantiation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Basic_declarationContext* basic_declaration();

  class  Defining_identifierContext : public antlr4::ParserRuleContext {
  public:
    Defining_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_identifierContext* defining_identifier();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Full_type_declarationContext *full_type_declaration();
    Incomplete_type_declarationContext *incomplete_type_declaration();
    Private_type_declarationContext *private_type_declaration();
    Private_extension_declarationContext *private_extension_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_declarationContext* type_declaration();

  class  Full_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Full_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Type_definitionContext *type_definition();
    antlr4::tree::TerminalNode *SEMI();
    Known_discriminant_partContext *known_discriminant_part();
    Task_type_declarationContext *task_type_declaration();
    Protected_type_declarationContext *protected_type_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Full_type_declarationContext* full_type_declaration();

  class  Type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Enumeration_type_definitionContext *enumeration_type_definition();
    Integer_type_definitionContext *integer_type_definition();
    Real_type_definitionContext *real_type_definition();
    Array_type_definitionContext *array_type_definition();
    Record_type_definitionContext *record_type_definition();
    Access_type_definitionContext *access_type_definition();
    Derived_type_definitionContext *derived_type_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_definitionContext* type_definition();

  class  Subtype_declarationContext : public antlr4::ParserRuleContext {
  public:
    Subtype_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUBTYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Subtype_indicationContext *subtype_indication();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subtype_declarationContext* subtype_declaration();

  class  Subtype_indicationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Subtype_indicationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    ConstraintContext *constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subtype_indicationContext* subtype_indication();

  class  ConstraintContext : public antlr4::ParserRuleContext {
  public:
    ConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Scalar_constraintContext *scalar_constraint();
    Composite_constraintContext *composite_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstraintContext* constraint();

  class  Scalar_constraintContext : public antlr4::ParserRuleContext {
  public:
    Scalar_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Range_constraintContext *range_constraint();
    Digits_constraintContext *digits_constraint();
    Delta_constraintContext *delta_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Scalar_constraintContext* scalar_constraint();

  class  Composite_constraintContext : public antlr4::ParserRuleContext {
  public:
    Composite_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Index_constraintContext *index_constraint();
    Discriminant_constraintContext *discriminant_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Composite_constraintContext* composite_constraint();

  class  Object_declarationContext : public antlr4::ParserRuleContext {
  public:
    Object_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Subtype_indicationContext *subtype_indication();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ALIASED();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    Array_type_definitionContext *array_type_definition();
    Single_task_declarationContext *single_task_declaration();
    Single_protected_declarationContext *single_protected_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Object_declarationContext* object_declaration();

  class  Defining_identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Defining_identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Defining_identifierContext *> defining_identifier();
    Defining_identifierContext* defining_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_identifier_listContext* defining_identifier_list();

  class  Number_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Number_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *CONSTANT();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Number_declarationContext* number_declaration();

  class  Derived_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Subtype_indicationContext *parent_subtype_indication = nullptr;
    Derived_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    Subtype_indicationContext *subtype_indication();
    antlr4::tree::TerminalNode *ABSTRACT();
    Record_extension_partContext *record_extension_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Derived_type_definitionContext* derived_type_definition();

  class  Range_constraintContext : public antlr4::ParserRuleContext {
  public:
    Range_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE_();
    RangeContext *range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Range_constraintContext* range_constraint();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Range_attribute_referenceContext *range_attribute_reference();
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *DOTDOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RangeContext* range();

  class  Enumeration_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Enumeration_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Enumeration_literal_specificationContext *> enumeration_literal_specification();
    Enumeration_literal_specificationContext* enumeration_literal_specification(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enumeration_type_definitionContext* enumeration_type_definition();

  class  Enumeration_literal_specificationContext : public antlr4::ParserRuleContext {
  public:
    Enumeration_literal_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();
    Defining_character_literalContext *defining_character_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enumeration_literal_specificationContext* enumeration_literal_specification();

  class  Defining_character_literalContext : public antlr4::ParserRuleContext {
  public:
    Defining_character_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Character_literalContext *character_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_character_literalContext* defining_character_literal();

  class  Integer_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Integer_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signed_integer_type_definitionContext *signed_integer_type_definition();
    Modular_type_definitionContext *modular_type_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Integer_type_definitionContext* integer_type_definition();

  class  Signed_integer_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Simple_expressionContext *static_simple_expression = nullptr;
    Signed_integer_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE_();
    antlr4::tree::TerminalNode *DOTDOT();
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Signed_integer_type_definitionContext* signed_integer_type_definition();

  class  Modular_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Modular_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Modular_type_definitionContext* modular_type_definition();

  class  Real_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Real_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Floating_point_definitionContext *floating_point_definition();
    Fixed_point_definitionContext *fixed_point_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Real_type_definitionContext* real_type_definition();

  class  Floating_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Floating_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIGITS();
    ExpressionContext *expression();
    Real_range_specificationContext *real_range_specification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Floating_point_definitionContext* floating_point_definition();

  class  Real_range_specificationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Simple_expressionContext *static_simple_expression = nullptr;
    Real_range_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RangeContext *range();
    antlr4::tree::TerminalNode *DOTDOT();
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Real_range_specificationContext* real_range_specification();

  class  Fixed_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Fixed_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ordinary_fixed_point_definitionContext *ordinary_fixed_point_definition();
    Decimal_fixed_point_definitionContext *decimal_fixed_point_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Fixed_point_definitionContext* fixed_point_definition();

  class  Ordinary_fixed_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Ordinary_fixed_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELTA();
    Real_range_specificationContext *real_range_specification();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ordinary_fixed_point_definitionContext* ordinary_fixed_point_definition();

  class  Decimal_fixed_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Decimal_fixed_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELTA();
    antlr4::tree::TerminalNode *DIGITS();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    Real_range_specificationContext *real_range_specification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Decimal_fixed_point_definitionContext* decimal_fixed_point_definition();

  class  Digits_constraintContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Digits_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIGITS();
    ExpressionContext *expression();
    Range_constraintContext *range_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Digits_constraintContext* digits_constraint();

  class  Array_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Array_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unconstrained_array_definitionContext *unconstrained_array_definition();
    Constrained_array_definitionContext *constrained_array_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_type_definitionContext* array_type_definition();

  class  Unconstrained_array_definitionContext : public antlr4::ParserRuleContext {
  public:
    Unconstrained_array_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LP();
    std::vector<Index_subtype_definitionContext *> index_subtype_definition();
    Index_subtype_definitionContext* index_subtype_definition(size_t i);
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *OF();
    Component_definitionContext *component_definition();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unconstrained_array_definitionContext* unconstrained_array_definition();

  class  Index_subtype_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Index_subtype_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RangeContext *range();
    antlr4::tree::TerminalNode *BOX();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Index_subtype_definitionContext* index_subtype_definition();

  class  Constrained_array_definitionContext : public antlr4::ParserRuleContext {
  public:
    Constrained_array_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LP();
    std::vector<Discrete_subtype_definitionContext *> discrete_subtype_definition();
    Discrete_subtype_definitionContext* discrete_subtype_definition(size_t i);
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *OF();
    Component_definitionContext *component_definition();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Constrained_array_definitionContext* constrained_array_definition();

  class  Discrete_subtype_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Subtype_indicationContext *discrete_subtype_indication = nullptr;
    Discrete_subtype_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subtype_indicationContext *subtype_indication();
    RangeContext *range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discrete_subtype_definitionContext* discrete_subtype_definition();

  class  Component_definitionContext : public antlr4::ParserRuleContext {
  public:
    Component_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subtype_indicationContext *subtype_indication();
    antlr4::tree::TerminalNode *ALIASED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_definitionContext* component_definition();

  class  Index_constraintContext : public antlr4::ParserRuleContext {
  public:
    Index_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Discrete_rangeContext *> discrete_range();
    Discrete_rangeContext* discrete_range(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Index_constraintContext* index_constraint();

  class  Discrete_rangeContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Subtype_indicationContext *discrete_subtype_indication = nullptr;
    Discrete_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subtype_indicationContext *subtype_indication();
    RangeContext *range();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discrete_rangeContext* discrete_range();

  class  Discriminant_partContext : public antlr4::ParserRuleContext {
  public:
    Discriminant_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unknown_discriminant_partContext *unknown_discriminant_part();
    Known_discriminant_partContext *known_discriminant_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discriminant_partContext* discriminant_part();

  class  Unknown_discriminant_partContext : public antlr4::ParserRuleContext {
  public:
    Unknown_discriminant_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *BOX();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unknown_discriminant_partContext* unknown_discriminant_part();

  class  Known_discriminant_partContext : public antlr4::ParserRuleContext {
  public:
    Known_discriminant_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Discriminant_specificationContext *> discriminant_specification();
    Discriminant_specificationContext* discriminant_specification(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Known_discriminant_partContext* known_discriminant_part();

  class  Discriminant_specificationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Discriminant_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    Default_expressionContext *default_expression();
    Access_definitionContext *access_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discriminant_specificationContext* discriminant_specification();

  class  Default_expressionContext : public antlr4::ParserRuleContext {
  public:
    Default_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Default_expressionContext* default_expression();

  class  Discriminant_constraintContext : public antlr4::ParserRuleContext {
  public:
    Discriminant_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Discriminant_associationContext *> discriminant_association();
    Discriminant_associationContext* discriminant_association(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discriminant_constraintContext* discriminant_constraint();

  class  Discriminant_associationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Selector_nameContext *discriminant_selector_name = nullptr;
    Discriminant_associationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ARROW();
    std::vector<Selector_nameContext *> selector_name();
    Selector_nameContext* selector_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VL();
    antlr4::tree::TerminalNode* VL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discriminant_associationContext* discriminant_association();

  class  Record_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Record_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Record_definitionContext *record_definition();
    antlr4::tree::TerminalNode *TAGGED();
    antlr4::tree::TerminalNode *LIMITED();
    antlr4::tree::TerminalNode *ABSTRACT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_type_definitionContext* record_type_definition();

  class  Record_definitionContext : public antlr4::ParserRuleContext {
  public:
    Record_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> RECORD();
    antlr4::tree::TerminalNode* RECORD(size_t i);
    Component_listContext *component_list();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *NULL_();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_definitionContext* record_definition();

  class  Component_listContext : public antlr4::ParserRuleContext {
  public:
    Component_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Component_itemContext *> component_item();
    Component_itemContext* component_item(size_t i);
    Variant_partContext *variant_part();
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_listContext* component_list();

  class  Component_itemContext : public antlr4::ParserRuleContext {
  public:
    Component_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Component_declarationContext *component_declaration();
    Aspect_clauseContext *aspect_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_itemContext* component_item();

  class  Component_declarationContext : public antlr4::ParserRuleContext {
  public:
    Component_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Component_definitionContext *component_definition();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *ASSIGN();
    Default_expressionContext *default_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_declarationContext* component_declaration();

  class  Variant_partContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Direct_nameContext *discriminant_direct_name = nullptr;
    Variant_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CASE();
    antlr4::tree::TerminalNode* CASE(size_t i);
    antlr4::tree::TerminalNode *IS();
    std::vector<VariantContext *> variant();
    VariantContext* variant(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    Direct_nameContext *direct_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Variant_partContext* variant_part();

  class  VariantContext : public antlr4::ParserRuleContext {
  public:
    VariantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    Discrete_choice_listContext *discrete_choice_list();
    antlr4::tree::TerminalNode *ARROW();
    Component_listContext *component_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariantContext* variant();

  class  Discrete_choice_listContext : public antlr4::ParserRuleContext {
  public:
    Discrete_choice_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Discrete_choiceContext *> discrete_choice();
    Discrete_choiceContext* discrete_choice(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VL();
    antlr4::tree::TerminalNode* VL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discrete_choice_listContext* discrete_choice_list();

  class  Discrete_choiceContext : public antlr4::ParserRuleContext {
  public:
    Discrete_choiceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Discrete_rangeContext *discrete_range();
    antlr4::tree::TerminalNode *OTHERS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Discrete_choiceContext* discrete_choice();

  class  Record_extension_partContext : public antlr4::ParserRuleContext {
  public:
    Record_extension_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    Record_definitionContext *record_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_extension_partContext* record_extension_part();

  class  Access_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Access_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Access_to_object_definitionContext *access_to_object_definition();
    Access_to_subprogram_definitionContext *access_to_subprogram_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Access_type_definitionContext* access_type_definition();

  class  Access_to_object_definitionContext : public antlr4::ParserRuleContext {
  public:
    Access_to_object_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESS();
    Subtype_indicationContext *subtype_indication();
    General_access_modifierContext *general_access_modifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Access_to_object_definitionContext* access_to_object_definition();

  class  General_access_modifierContext : public antlr4::ParserRuleContext {
  public:
    General_access_modifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *CONSTANT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  General_access_modifierContext* general_access_modifier();

  class  Access_to_subprogram_definitionContext : public antlr4::ParserRuleContext {
  public:
    Access_to_subprogram_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESS();
    antlr4::tree::TerminalNode *PROCEDURE();
    Parameter_profileContext *parameter_profile();
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *FUNCTION();
    Parameter_and_result_profileContext *parameter_and_result_profile();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Access_to_subprogram_definitionContext* access_to_subprogram_definition();

  class  Access_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Access_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCESS();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Access_definitionContext* access_definition();

  class  Incomplete_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Incomplete_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *SEMI();
    Discriminant_partContext *discriminant_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Incomplete_type_declarationContext* incomplete_type_declaration();

  class  Declarative_partContext : public antlr4::ParserRuleContext {
  public:
    Declarative_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Declarative_itemContext *> declarative_item();
    Declarative_itemContext* declarative_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declarative_partContext* declarative_part();

  class  Declarative_itemContext : public antlr4::ParserRuleContext {
  public:
    Declarative_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_declarative_itemContext *basic_declarative_item();
    BodyContext *body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declarative_itemContext* declarative_item();

  class  Basic_declarative_itemContext : public antlr4::ParserRuleContext {
  public:
    Basic_declarative_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Basic_declarationContext *basic_declaration();
    Aspect_clauseContext *aspect_clause();
    Use_clauseContext *use_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Basic_declarative_itemContext* basic_declarative_item();

  class  BodyContext : public antlr4::ParserRuleContext {
  public:
    BodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Proper_bodyContext *proper_body();
    Body_stubContext *body_stub();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BodyContext* body();

  class  Proper_bodyContext : public antlr4::ParserRuleContext {
  public:
    Proper_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_bodyContext *subprogram_body();
    Package_bodyContext *package_body();
    Task_bodyContext *task_body();
    Protected_bodyContext *protected_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Proper_bodyContext* proper_body();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *prefix = nullptr;
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Ada95Parser::NameContext *function_prefix = nullptr;
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Direct_nameContext *direct_name();
    Character_literalContext *character_literal();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *LP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    Discrete_rangeContext *discrete_range();
    Selector_nameContext *selector_name();
    antlr4::tree::TerminalNode *SQ();
    Attribute_designatorContext *attribute_designator();
    Actual_parameter_partContext *actual_parameter_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NameContext* name();
  NameContext* name(int precedence);
  class  Direct_nameContext : public antlr4::ParserRuleContext {
  public:
    Direct_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Operator_symbolContext *operator_symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Direct_nameContext* direct_name();

  class  Selector_nameContext : public antlr4::ParserRuleContext {
  public:
    Selector_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Character_literalContext *character_literal();
    Operator_symbolContext *operator_symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Selector_nameContext* selector_name();

  class  Attribute_designatorContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Attribute_designatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ACCESS();
    antlr4::tree::TerminalNode *DELTA();
    antlr4::tree::TerminalNode *DIGITS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Attribute_designatorContext* attribute_designator();

  class  Range_attribute_referenceContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *prefix = nullptr;
    Range_attribute_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SQ();
    Range_attribute_designatorContext *range_attribute_designator();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Range_attribute_referenceContext* range_attribute_reference();

  class  Range_attribute_designatorContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Range_attribute_designatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE_();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Range_attribute_designatorContext* range_attribute_designator();

  class  AggregateContext : public antlr4::ParserRuleContext {
  public:
    AggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Record_aggregateContext *record_aggregate();
    Extension_aggregateContext *extension_aggregate();
    Array_aggregateContext *array_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AggregateContext* aggregate();

  class  Record_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Record_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    Record_component_association_listContext *record_component_association_list();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_aggregateContext* record_aggregate();

  class  Record_component_association_listContext : public antlr4::ParserRuleContext {
  public:
    Record_component_association_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Record_component_associationContext *> record_component_association();
    Record_component_associationContext* record_component_association(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *RECORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_component_association_listContext* record_component_association_list();

  class  Record_component_associationContext : public antlr4::ParserRuleContext {
  public:
    Record_component_associationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Component_choice_listContext *component_choice_list();
    antlr4::tree::TerminalNode *ARROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_component_associationContext* record_component_association();

  class  Component_choice_listContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Selector_nameContext *component_selector_name = nullptr;
    Component_choice_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Selector_nameContext *> selector_name();
    Selector_nameContext* selector_name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VL();
    antlr4::tree::TerminalNode* VL(size_t i);
    antlr4::tree::TerminalNode *OTHERS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_choice_listContext* component_choice_list();

  class  Extension_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Extension_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    Ancestor_partContext *ancestor_part();
    antlr4::tree::TerminalNode *WITH();
    Record_component_association_listContext *record_component_association_list();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Extension_aggregateContext* extension_aggregate();

  class  Ancestor_partContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Ancestor_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ancestor_partContext* ancestor_part();

  class  Array_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Array_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Positional_array_aggregateContext *positional_array_aggregate();
    Named_array_aggregateContext *named_array_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_aggregateContext* array_aggregate();

  class  Positional_array_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Positional_array_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *OTHERS();
    antlr4::tree::TerminalNode *ARROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Positional_array_aggregateContext* positional_array_aggregate();

  class  Named_array_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Named_array_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Array_component_associationContext *> array_component_association();
    Array_component_associationContext* array_component_association(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Named_array_aggregateContext* named_array_aggregate();

  class  Array_component_associationContext : public antlr4::ParserRuleContext {
  public:
    Array_component_associationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Discrete_choice_listContext *discrete_choice_list();
    antlr4::tree::TerminalNode *ARROW();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Array_component_associationContext* array_component_association();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RelationContext *> relation();
    RelationContext* relation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);
    std::vector<antlr4::tree::TerminalNode *> THEN();
    antlr4::tree::TerminalNode* THEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSE();
    antlr4::tree::TerminalNode* ELSE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XOR();
    antlr4::tree::TerminalNode* XOR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  RelationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    RelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    Relational_operatorContext *relational_operator();
    antlr4::tree::TerminalNode *IN();
    RangeContext *range();
    antlr4::tree::TerminalNode *NOT();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationContext* relation();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    Unary_adding_operatorContext *unary_adding_operator();
    std::vector<Binary_adding_operatorContext *> binary_adding_operator();
    Binary_adding_operatorContext* binary_adding_operator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<Multiplying_operatorContext *> multiplying_operator();
    Multiplying_operatorContext* multiplying_operator(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrimaryContext *> primary();
    PrimaryContext* primary(size_t i);
    antlr4::tree::TerminalNode *EXPON();
    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Numeric_literalContext *numeric_literal();
    antlr4::tree::TerminalNode *NULL_();
    String_literalContext *string_literal();
    AggregateContext *aggregate();
    NameContext *name();
    Qualified_expressionContext *qualified_expression();
    AllocatorContext *allocator();
    antlr4::tree::TerminalNode *LP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrimaryContext* primary();

  class  Logical_operatorContext : public antlr4::ParserRuleContext {
  public:
    Logical_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logical_operatorContext* logical_operator();

  class  Relational_operatorContext : public antlr4::ParserRuleContext {
  public:
    Relational_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Relational_operatorContext* relational_operator();

  class  Binary_adding_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_adding_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *AMPERSAND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binary_adding_operatorContext* binary_adding_operator();

  class  Unary_adding_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_adding_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_adding_operatorContext* unary_adding_operator();

  class  Multiplying_operatorContext : public antlr4::ParserRuleContext {
  public:
    Multiplying_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *REM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Multiplying_operatorContext* multiplying_operator();

  class  Highest_precedence_operatorContext : public antlr4::ParserRuleContext {
  public:
    Highest_precedence_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPON();
    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Highest_precedence_operatorContext* highest_precedence_operator();

  class  Qualified_expressionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Qualified_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SQ();
    antlr4::tree::TerminalNode *LP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RP();
    NameContext *name();
    AggregateContext *aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Qualified_expressionContext* qualified_expression();

  class  AllocatorContext : public antlr4::ParserRuleContext {
  public:
    AllocatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    Subtype_indicationContext *subtype_indication();
    Qualified_expressionContext *qualified_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AllocatorContext* allocator();

  class  Sequence_of_statementsContext : public antlr4::ParserRuleContext {
  public:
    Sequence_of_statementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Sequence_of_statementsContext* sequence_of_statements();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_statementContext *simple_statement();
    std::vector<LabelContext *> label();
    LabelContext* label(size_t i);
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Simple_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Null_statementContext *null_statement();
    Assignment_statementContext *assignment_statement();
    Exit_statementContext *exit_statement();
    Goto_statementContext *goto_statement();
    Procedure_call_statementContext *procedure_call_statement();
    Return_statementContext *return_statement();
    Entry_call_statementContext *entry_call_statement();
    Requeue_statementContext *requeue_statement();
    Delay_statementContext *delay_statement();
    Abort_statementContext *abort_statement();
    Raise_statementContext *raise_statement();
    Code_statementContext *code_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_statementContext* simple_statement();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_statementContext *if_statement();
    Case_statementContext *case_statement();
    Loop_statementContext *loop_statement();
    Block_statementContext *block_statement();
    Accept_statementContext *accept_statement();
    Select_statementContext *select_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Null_statementContext : public antlr4::ParserRuleContext {
  public:
    Null_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Null_statementContext* null_statement();

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Statement_identifierContext *label_statement_identifier = nullptr;
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LLB();
    antlr4::tree::TerminalNode *RLB();
    Statement_identifierContext *statement_identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LabelContext* label();

  class  Statement_identifierContext : public antlr4::ParserRuleContext {
  public:
    Statement_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Direct_nameContext *direct_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Statement_identifierContext* statement_identifier();

  class  Assignment_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *variable_name = nullptr;
    Assignment_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Assignment_statementContext* assignment_statement();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IF();
    antlr4::tree::TerminalNode* IF(size_t i);
    std::vector<ConditionContext *> condition();
    ConditionContext* condition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> THEN();
    antlr4::tree::TerminalNode* THEN(size_t i);
    std::vector<Sequence_of_statementsContext *> sequence_of_statements();
    Sequence_of_statementsContext* sequence_of_statements(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<antlr4::tree::TerminalNode *> ELSIF();
    antlr4::tree::TerminalNode* ELSIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  If_statementContext* if_statement();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Boolean_expressionContext *boolean_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionContext* condition();

  class  Case_statementContext : public antlr4::ParserRuleContext {
  public:
    Case_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> CASE();
    antlr4::tree::TerminalNode* CASE(size_t i);
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IS();
    std::vector<Case_statement_alternativeContext *> case_statement_alternative();
    Case_statement_alternativeContext* case_statement_alternative(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Case_statementContext* case_statement();

  class  Case_statement_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Case_statement_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    Discrete_choice_listContext *discrete_choice_list();
    antlr4::tree::TerminalNode *ARROW();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Case_statement_alternativeContext* case_statement_alternative();

  class  Loop_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Statement_identifierContext *loop_statement_identifier = nullptr;
    Ada95Parser::IdentifierContext *loop_identifier = nullptr;
    Loop_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> LOOP();
    antlr4::tree::TerminalNode* LOOP(size_t i);
    Sequence_of_statementsContext *sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *COLON();
    Iteration_schemeContext *iteration_scheme();
    Statement_identifierContext *statement_identifier();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Loop_statementContext* loop_statement();

  class  Iteration_schemeContext : public antlr4::ParserRuleContext {
  public:
    Iteration_schemeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *FOR();
    Loop_parameter_specificationContext *loop_parameter_specification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Iteration_schemeContext* iteration_scheme();

  class  Loop_parameter_specificationContext : public antlr4::ParserRuleContext {
  public:
    Loop_parameter_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IN();
    Discrete_subtype_definitionContext *discrete_subtype_definition();
    antlr4::tree::TerminalNode *REVERSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Loop_parameter_specificationContext* loop_parameter_specification();

  class  Block_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Statement_identifierContext *block_statement_identifier = nullptr;
    Ada95Parser::IdentifierContext *block_identifier = nullptr;
    Block_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *DECLARE();
    Declarative_partContext *declarative_part();
    Statement_identifierContext *statement_identifier();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Block_statementContext* block_statement();

  class  Exit_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *loop_name = nullptr;
    Exit_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXIT();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *WHEN();
    ConditionContext *condition();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Exit_statementContext* exit_statement();

  class  Goto_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *label_name = nullptr;
    Goto_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Goto_statementContext* goto_statement();

  class  Subprogram_declarationContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_declarationContext* subprogram_declaration();

  class  Abstract_subprogram_declarationContext : public antlr4::ParserRuleContext {
  public:
    Abstract_subprogram_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Abstract_subprogram_declarationContext* abstract_subprogram_declaration();

  class  Subprogram_specificationContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE();
    Defining_program_unit_nameContext *defining_program_unit_name();
    Parameter_profileContext *parameter_profile();
    antlr4::tree::TerminalNode *FUNCTION();
    Defining_designatorContext *defining_designator();
    Parameter_and_result_profileContext *parameter_and_result_profile();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_specificationContext* subprogram_specification();

  class  DesignatorContext : public antlr4::ParserRuleContext {
  public:
    DesignatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Parent_unit_nameContext *parent_unit_name();
    antlr4::tree::TerminalNode *DOT();
    Operator_symbolContext *operator_symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DesignatorContext* designator();

  class  Defining_designatorContext : public antlr4::ParserRuleContext {
  public:
    Defining_designatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_program_unit_nameContext *defining_program_unit_name();
    Defining_operator_symbolContext *defining_operator_symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_designatorContext* defining_designator();

  class  Defining_program_unit_nameContext : public antlr4::ParserRuleContext {
  public:
    Defining_program_unit_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();
    Parent_unit_nameContext *parent_unit_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_program_unit_nameContext* defining_program_unit_name();

  class  Operator_symbolContext : public antlr4::ParserRuleContext {
  public:
    Operator_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    String_literalContext *string_literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Operator_symbolContext* operator_symbol();

  class  Defining_operator_symbolContext : public antlr4::ParserRuleContext {
  public:
    Defining_operator_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Operator_symbolContext *operator_symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Defining_operator_symbolContext* defining_operator_symbol();

  class  Parameter_profileContext : public antlr4::ParserRuleContext {
  public:
    Parameter_profileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formal_partContext *formal_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_profileContext* parameter_profile();

  class  Parameter_and_result_profileContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Parameter_and_result_profileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    NameContext *name();
    Formal_partContext *formal_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_and_result_profileContext* parameter_and_result_profile();

  class  Formal_partContext : public antlr4::ParserRuleContext {
  public:
    Formal_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Parameter_specificationContext *> parameter_specification();
    Parameter_specificationContext* parameter_specification(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_partContext* formal_part();

  class  Parameter_specificationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Parameter_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Mode_Context *mode_();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    Default_expressionContext *default_expression();
    Access_definitionContext *access_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_specificationContext* parameter_specification();

  class  Mode_Context : public antlr4::ParserRuleContext {
  public:
    Mode_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *OUT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mode_Context* mode_();

  class  Subprogram_bodyContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *IS();
    Declarative_partContext *declarative_part();
    antlr4::tree::TerminalNode *BEGIN();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    DesignatorContext *designator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_bodyContext* subprogram_body();

  class  Procedure_call_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *procedure_name = nullptr;
    Ada95Parser::NameContext *procedure_prefix = nullptr;
    Procedure_call_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    Actual_parameter_partContext *actual_parameter_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Procedure_call_statementContext* procedure_call_statement();

  class  Actual_parameter_partContext : public antlr4::ParserRuleContext {
  public:
    Actual_parameter_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Parameter_associationContext *> parameter_association();
    Parameter_associationContext* parameter_association(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Actual_parameter_partContext* actual_parameter_part();

  class  Parameter_associationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Selector_nameContext *formal_parameter_selector_name = nullptr;
    Parameter_associationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Explicit_actual_parameterContext *explicit_actual_parameter();
    antlr4::tree::TerminalNode *ARROW();
    Selector_nameContext *selector_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_associationContext* parameter_association();

  class  Explicit_actual_parameterContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *variable_name = nullptr;
    Explicit_actual_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Explicit_actual_parameterContext* explicit_actual_parameter();

  class  Return_statementContext : public antlr4::ParserRuleContext {
  public:
    Return_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Return_statementContext* return_statement();

  class  Package_declarationContext : public antlr4::ParserRuleContext {
  public:
    Package_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_specificationContext *package_specification();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Package_declarationContext* package_declaration();

  class  Package_specificationContext : public antlr4::ParserRuleContext {
  public:
    Package_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    Defining_program_unit_nameContext *defining_program_unit_name();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *END();
    std::vector<Basic_declarative_itemContext *> basic_declarative_item();
    Basic_declarative_itemContext* basic_declarative_item(size_t i);
    antlr4::tree::TerminalNode *PRIVATE();
    IdentifierContext *identifier();
    Parent_unit_nameContext *parent_unit_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Package_specificationContext* package_specification();

  class  Package_bodyContext : public antlr4::ParserRuleContext {
  public:
    Package_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    antlr4::tree::TerminalNode *BODY_();
    Defining_program_unit_nameContext *defining_program_unit_name();
    antlr4::tree::TerminalNode *IS();
    Declarative_partContext *declarative_part();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *BEGIN();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    IdentifierContext *identifier();
    Parent_unit_nameContext *parent_unit_name();
    antlr4::tree::TerminalNode *DOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Package_bodyContext* package_body();

  class  Private_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Private_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *SEMI();
    Discriminant_partContext *discriminant_part();
    antlr4::tree::TerminalNode *TAGGED();
    antlr4::tree::TerminalNode *LIMITED();
    antlr4::tree::TerminalNode *ABSTRACT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Private_type_declarationContext* private_type_declaration();

  class  Private_extension_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Subtype_indicationContext *ancestor_subtype_indication = nullptr;
    Private_extension_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *SEMI();
    Subtype_indicationContext *subtype_indication();
    Discriminant_partContext *discriminant_part();
    antlr4::tree::TerminalNode *ABSTRACT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Private_extension_declarationContext* private_extension_declaration();

  class  Use_clauseContext : public antlr4::ParserRuleContext {
  public:
    Use_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Use_package_clauseContext *use_package_clause();
    Use_type_clauseContext *use_type_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Use_clauseContext* use_clause();

  class  Use_package_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *package_name = nullptr;
    Ada95Parser::NameContext *package_nam = nullptr;
    Use_package_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Use_package_clauseContext* use_package_clause();

  class  Use_type_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Use_type_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Use_type_clauseContext* use_type_clause();

  class  Renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Object_renaming_declarationContext *object_renaming_declaration();
    Exception_renaming_declarationContext *exception_renaming_declaration();
    Package_renaming_declarationContext *package_renaming_declaration();
    Subprogram_renaming_declarationContext *subprogram_renaming_declaration();
    Generic_renaming_declarationContext *generic_renaming_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Renaming_declarationContext* renaming_declaration();

  class  Object_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Ada95Parser::NameContext *object_name = nullptr;
    Object_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *RENAMES();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Object_renaming_declarationContext* object_renaming_declaration();

  class  Exception_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *exception_name = nullptr;
    Exception_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *EXCEPTION();
    antlr4::tree::TerminalNode *RENAMES();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Exception_renaming_declarationContext* exception_renaming_declaration();

  class  Package_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *package_name = nullptr;
    Package_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    Defining_program_unit_nameContext *defining_program_unit_name();
    antlr4::tree::TerminalNode *RENAMES();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Package_renaming_declarationContext* package_renaming_declaration();

  class  Subprogram_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *callable_entity_name = nullptr;
    Subprogram_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *RENAMES();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_renaming_declarationContext* subprogram_renaming_declaration();

  class  Generic_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *generic_package_name = nullptr;
    Ada95Parser::NameContext *generic_procedure_name = nullptr;
    Ada95Parser::NameContext *generic_function_name = nullptr;
    Generic_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GENERIC();
    antlr4::tree::TerminalNode *PACKAGE();
    Defining_program_unit_nameContext *defining_program_unit_name();
    antlr4::tree::TerminalNode *RENAMES();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    antlr4::tree::TerminalNode *PROCEDURE();
    antlr4::tree::TerminalNode *FUNCTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_renaming_declarationContext* generic_renaming_declaration();

  class  Task_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Task_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TASK();
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *SEMI();
    Known_discriminant_partContext *known_discriminant_part();
    antlr4::tree::TerminalNode *IS();
    Task_definitionContext *task_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Task_type_declarationContext* task_type_declaration();

  class  Single_task_declarationContext : public antlr4::ParserRuleContext {
  public:
    Single_task_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TASK();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *IS();
    Task_definitionContext *task_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_task_declarationContext* single_task_declaration();

  class  Task_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *task_identifier = nullptr;
    Task_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    std::vector<Task_itemContext *> task_item();
    Task_itemContext* task_item(size_t i);
    antlr4::tree::TerminalNode *PRIVATE();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Task_definitionContext* task_definition();

  class  Task_itemContext : public antlr4::ParserRuleContext {
  public:
    Task_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Entry_declarationContext *entry_declaration();
    Aspect_clauseContext *aspect_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Task_itemContext* task_item();

  class  Task_bodyContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *task_identifier = nullptr;
    Task_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TASK();
    antlr4::tree::TerminalNode *BODY_();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Declarative_partContext *declarative_part();
    antlr4::tree::TerminalNode *BEGIN();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Task_bodyContext* task_body();

  class  Protected_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Protected_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Protected_definitionContext *protected_definition();
    antlr4::tree::TerminalNode *SEMI();
    Known_discriminant_partContext *known_discriminant_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_type_declarationContext* protected_type_declaration();

  class  Single_protected_declarationContext : public antlr4::ParserRuleContext {
  public:
    Single_protected_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROTECTED();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Protected_definitionContext *protected_definition();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Single_protected_declarationContext* single_protected_declaration();

  class  Protected_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *protected_identifier = nullptr;
    Protected_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    std::vector<Protected_operation_declarationContext *> protected_operation_declaration();
    Protected_operation_declarationContext* protected_operation_declaration(size_t i);
    antlr4::tree::TerminalNode *PRIVATE();
    IdentifierContext *identifier();
    std::vector<Protected_element_declarationContext *> protected_element_declaration();
    Protected_element_declarationContext* protected_element_declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_definitionContext* protected_definition();

  class  Protected_operation_declarationContext : public antlr4::ParserRuleContext {
  public:
    Protected_operation_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_declarationContext *subprogram_declaration();
    Entry_declarationContext *entry_declaration();
    Aspect_clauseContext *aspect_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_operation_declarationContext* protected_operation_declaration();

  class  Protected_element_declarationContext : public antlr4::ParserRuleContext {
  public:
    Protected_element_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Protected_operation_declarationContext *protected_operation_declaration();
    Component_declarationContext *component_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_element_declarationContext* protected_element_declaration();

  class  Protected_bodyContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *protected_identifier = nullptr;
    Protected_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *BODY_();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<Protected_operation_itemContext *> protected_operation_item();
    Protected_operation_itemContext* protected_operation_item(size_t i);
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_bodyContext* protected_body();

  class  Protected_operation_itemContext : public antlr4::ParserRuleContext {
  public:
    Protected_operation_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_declarationContext *subprogram_declaration();
    Subprogram_bodyContext *subprogram_body();
    Entry_bodyContext *entry_body();
    Aspect_clauseContext *aspect_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_operation_itemContext* protected_operation_item();

  class  Entry_declarationContext : public antlr4::ParserRuleContext {
  public:
    Entry_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENTRY();
    Defining_identifierContext *defining_identifier();
    Parameter_profileContext *parameter_profile();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *LP();
    Discrete_subtype_definitionContext *discrete_subtype_definition();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_declarationContext* entry_declaration();

  class  Accept_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Direct_nameContext *entry_direct_name = nullptr;
    Ada95Parser::IdentifierContext *entry_identifier = nullptr;
    Accept_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCEPT_();
    Parameter_profileContext *parameter_profile();
    antlr4::tree::TerminalNode *SEMI();
    Direct_nameContext *direct_name();
    antlr4::tree::TerminalNode *LP();
    Entry_indexContext *entry_index();
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *DO();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Accept_statementContext* accept_statement();

  class  Entry_indexContext : public antlr4::ParserRuleContext {
  public:
    Entry_indexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_indexContext* entry_index();

  class  Entry_bodyContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *entry_identifier = nullptr;
    Entry_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENTRY();
    Defining_identifierContext *defining_identifier();
    Entry_body_formal_partContext *entry_body_formal_part();
    Entry_barrierContext *entry_barrier();
    antlr4::tree::TerminalNode *IS();
    Declarative_partContext *declarative_part();
    antlr4::tree::TerminalNode *BEGIN();
    Handled_sequence_of_statementsContext *handled_sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_bodyContext* entry_body();

  class  Entry_body_formal_partContext : public antlr4::ParserRuleContext {
  public:
    Entry_body_formal_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_profileContext *parameter_profile();
    antlr4::tree::TerminalNode *LP();
    Entry_index_specificationContext *entry_index_specification();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_body_formal_partContext* entry_body_formal_part();

  class  Entry_barrierContext : public antlr4::ParserRuleContext {
  public:
    Entry_barrierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    ConditionContext *condition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_barrierContext* entry_barrier();

  class  Entry_index_specificationContext : public antlr4::ParserRuleContext {
  public:
    Entry_index_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IN();
    Discrete_subtype_definitionContext *discrete_subtype_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_index_specificationContext* entry_index_specification();

  class  Entry_call_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *entry_name = nullptr;
    Entry_call_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    Actual_parameter_partContext *actual_parameter_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_call_statementContext* entry_call_statement();

  class  Requeue_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *entry_name = nullptr;
    Requeue_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REQUEUE();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *ABORT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Requeue_statementContext* requeue_statement();

  class  Delay_statementContext : public antlr4::ParserRuleContext {
  public:
    Delay_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_until_statementContext *delay_until_statement();
    Delay_relative_statementContext *delay_relative_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delay_statementContext* delay_statement();

  class  Delay_until_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *delay_expression = nullptr;
    Delay_until_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delay_until_statementContext* delay_until_statement();

  class  Delay_relative_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *delay_expression = nullptr;
    Delay_relative_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delay_relative_statementContext* delay_relative_statement();

  class  Select_statementContext : public antlr4::ParserRuleContext {
  public:
    Select_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Selective_acceptContext *selective_accept();
    Timed_entry_callContext *timed_entry_call();
    Conditional_entry_callContext *conditional_entry_call();
    Asynchronous_selectContext *asynchronous_select();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Select_statementContext* select_statement();

  class  Selective_acceptContext : public antlr4::ParserRuleContext {
  public:
    Selective_acceptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SELECT();
    antlr4::tree::TerminalNode* SELECT(size_t i);
    std::vector<Select_alternativeContext *> select_alternative();
    Select_alternativeContext* select_alternative(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<GuardContext *> guard();
    GuardContext* guard(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Selective_acceptContext* selective_accept();

  class  GuardContext : public antlr4::ParserRuleContext {
  public:
    GuardContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    ConditionContext *condition();
    antlr4::tree::TerminalNode *ARROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  GuardContext* guard();

  class  Select_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Select_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Accept_alternativeContext *accept_alternative();
    Delay_alternativeContext *delay_alternative();
    Terminate_alternativeContext *terminate_alternative();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Select_alternativeContext* select_alternative();

  class  Accept_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Accept_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Accept_statementContext *accept_statement();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Accept_alternativeContext* accept_alternative();

  class  Delay_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Delay_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_statementContext *delay_statement();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delay_alternativeContext* delay_alternative();

  class  Terminate_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Terminate_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TERMINATE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Terminate_alternativeContext* terminate_alternative();

  class  Timed_entry_callContext : public antlr4::ParserRuleContext {
  public:
    Timed_entry_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SELECT();
    antlr4::tree::TerminalNode* SELECT(size_t i);
    Entry_call_alternativeContext *entry_call_alternative();
    antlr4::tree::TerminalNode *OR();
    Delay_alternativeContext *delay_alternative();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Timed_entry_callContext* timed_entry_call();

  class  Entry_call_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Entry_call_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Entry_call_statementContext *entry_call_statement();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Entry_call_alternativeContext* entry_call_alternative();

  class  Conditional_entry_callContext : public antlr4::ParserRuleContext {
  public:
    Conditional_entry_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SELECT();
    antlr4::tree::TerminalNode* SELECT(size_t i);
    Entry_call_alternativeContext *entry_call_alternative();
    antlr4::tree::TerminalNode *ELSE();
    Sequence_of_statementsContext *sequence_of_statements();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Conditional_entry_callContext* conditional_entry_call();

  class  Asynchronous_selectContext : public antlr4::ParserRuleContext {
  public:
    Asynchronous_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SELECT();
    antlr4::tree::TerminalNode* SELECT(size_t i);
    Triggering_alternativeContext *triggering_alternative();
    antlr4::tree::TerminalNode *THEN();
    antlr4::tree::TerminalNode *ABORT();
    Abortable_partContext *abortable_part();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Asynchronous_selectContext* asynchronous_select();

  class  Triggering_alternativeContext : public antlr4::ParserRuleContext {
  public:
    Triggering_alternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Triggering_statementContext *triggering_statement();
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Triggering_alternativeContext* triggering_alternative();

  class  Triggering_statementContext : public antlr4::ParserRuleContext {
  public:
    Triggering_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Entry_call_statementContext *entry_call_statement();
    Delay_statementContext *delay_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Triggering_statementContext* triggering_statement();

  class  Abortable_partContext : public antlr4::ParserRuleContext {
  public:
    Abortable_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_of_statementsContext *sequence_of_statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Abortable_partContext* abortable_part();

  class  Abort_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *task_name = nullptr;
    Abort_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABORT();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Abort_statementContext* abort_statement();

  class  CompilationContext : public antlr4::ParserRuleContext {
  public:
    CompilationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Compilation_unitContext *> compilation_unit();
    Compilation_unitContext* compilation_unit(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CompilationContext* compilation();

  class  Compilation_unitContext : public antlr4::ParserRuleContext {
  public:
    Compilation_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Context_clauseContext *context_clause();
    Library_itemContext *library_item();
    SubunitContext *subunit();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compilation_unitContext* compilation_unit();

  class  Library_itemContext : public antlr4::ParserRuleContext {
  public:
    Library_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Library_unit_declarationContext *library_unit_declaration();
    antlr4::tree::TerminalNode *PRIVATE();
    Library_unit_bodyContext *library_unit_body();
    Library_unit_renaming_declarationContext *library_unit_renaming_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Library_itemContext* library_item();

  class  Library_unit_declarationContext : public antlr4::ParserRuleContext {
  public:
    Library_unit_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_declarationContext *subprogram_declaration();
    Package_declarationContext *package_declaration();
    Generic_declarationContext *generic_declaration();
    Generic_instantiationContext *generic_instantiation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Library_unit_declarationContext* library_unit_declaration();

  class  Library_unit_renaming_declarationContext : public antlr4::ParserRuleContext {
  public:
    Library_unit_renaming_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_renaming_declarationContext *package_renaming_declaration();
    Generic_renaming_declarationContext *generic_renaming_declaration();
    Subprogram_renaming_declarationContext *subprogram_renaming_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Library_unit_renaming_declarationContext* library_unit_renaming_declaration();

  class  Library_unit_bodyContext : public antlr4::ParserRuleContext {
  public:
    Library_unit_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_bodyContext *subprogram_body();
    Package_bodyContext *package_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Library_unit_bodyContext* library_unit_body();

  class  Parent_unit_nameContext : public antlr4::ParserRuleContext {
  public:
    Parent_unit_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parent_unit_nameContext* parent_unit_name();

  class  Context_clauseContext : public antlr4::ParserRuleContext {
  public:
    Context_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Context_itemContext *> context_item();
    Context_itemContext* context_item(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Context_clauseContext* context_clause();

  class  Context_itemContext : public antlr4::ParserRuleContext {
  public:
    Context_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    With_clauseContext *with_clause();
    Use_clauseContext *use_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Context_itemContext* context_item();

  class  With_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *library_unit_name = nullptr;
    With_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *SEMI();
    std::vector<NameContext *> name();
    NameContext* name(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  With_clauseContext* with_clause();

  class  Body_stubContext : public antlr4::ParserRuleContext {
  public:
    Body_stubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_body_stubContext *subprogram_body_stub();
    Package_body_stubContext *package_body_stub();
    Task_body_stubContext *task_body_stub();
    Protected_body_stubContext *protected_body_stub();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Body_stubContext* body_stub();

  class  Subprogram_body_stubContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_body_stubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *SEPARATE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_body_stubContext* subprogram_body_stub();

  class  Package_body_stubContext : public antlr4::ParserRuleContext {
  public:
    Package_body_stubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    antlr4::tree::TerminalNode *BODY_();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *SEPARATE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Package_body_stubContext* package_body_stub();

  class  Task_body_stubContext : public antlr4::ParserRuleContext {
  public:
    Task_body_stubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TASK();
    antlr4::tree::TerminalNode *BODY_();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *SEPARATE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Task_body_stubContext* task_body_stub();

  class  Protected_body_stubContext : public antlr4::ParserRuleContext {
  public:
    Protected_body_stubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROTECTED();
    antlr4::tree::TerminalNode *BODY_();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *SEPARATE();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Protected_body_stubContext* protected_body_stub();

  class  SubunitContext : public antlr4::ParserRuleContext {
  public:
    SubunitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEPARATE();
    antlr4::tree::TerminalNode *LP();
    Parent_unit_nameContext *parent_unit_name();
    antlr4::tree::TerminalNode *RP();
    Proper_bodyContext *proper_body();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubunitContext* subunit();

  class  Exception_declarationContext : public antlr4::ParserRuleContext {
  public:
    Exception_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *EXCEPTION();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Exception_declarationContext* exception_declaration();

  class  Handled_sequence_of_statementsContext : public antlr4::ParserRuleContext {
  public:
    Handled_sequence_of_statementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_of_statementsContext *sequence_of_statements();
    antlr4::tree::TerminalNode *EXCEPTION();
    std::vector<Exception_handlerContext *> exception_handler();
    Exception_handlerContext* exception_handler(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Handled_sequence_of_statementsContext* handled_sequence_of_statements();

  class  Exception_handlerContext : public antlr4::ParserRuleContext {
  public:
    Exception_handlerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    std::vector<Exception_choiceContext *> exception_choice();
    Exception_choiceContext* exception_choice(size_t i);
    antlr4::tree::TerminalNode *ARROW();
    Sequence_of_statementsContext *sequence_of_statements();
    Choice_parameter_specificationContext *choice_parameter_specification();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> VL();
    antlr4::tree::TerminalNode* VL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Exception_handlerContext* exception_handler();

  class  Choice_parameter_specificationContext : public antlr4::ParserRuleContext {
  public:
    Choice_parameter_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifierContext *defining_identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Choice_parameter_specificationContext* choice_parameter_specification();

  class  Exception_choiceContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *exception_name = nullptr;
    Exception_choiceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();
    antlr4::tree::TerminalNode *OTHERS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Exception_choiceContext* exception_choice();

  class  Raise_statementContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *exception_name = nullptr;
    Raise_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAISE();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Raise_statementContext* raise_statement();

  class  Generic_declarationContext : public antlr4::ParserRuleContext {
  public:
    Generic_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Generic_subprogram_declarationContext *generic_subprogram_declaration();
    Generic_package_declarationContext *generic_package_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_declarationContext* generic_declaration();

  class  Generic_subprogram_declarationContext : public antlr4::ParserRuleContext {
  public:
    Generic_subprogram_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Generic_formal_partContext *generic_formal_part();
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_subprogram_declarationContext* generic_subprogram_declaration();

  class  Generic_package_declarationContext : public antlr4::ParserRuleContext {
  public:
    Generic_package_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Generic_formal_partContext *generic_formal_part();
    Package_specificationContext *package_specification();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_package_declarationContext* generic_package_declaration();

  class  Generic_formal_partContext : public antlr4::ParserRuleContext {
  public:
    Generic_formal_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GENERIC();
    std::vector<Generic_formal_parameter_declarationContext *> generic_formal_parameter_declaration();
    Generic_formal_parameter_declarationContext* generic_formal_parameter_declaration(size_t i);
    std::vector<Use_clauseContext *> use_clause();
    Use_clauseContext* use_clause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_formal_partContext* generic_formal_part();

  class  Generic_formal_parameter_declarationContext : public antlr4::ParserRuleContext {
  public:
    Generic_formal_parameter_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formal_object_declarationContext *formal_object_declaration();
    Formal_type_declarationContext *formal_type_declaration();
    Formal_subprogram_declarationContext *formal_subprogram_declaration();
    Formal_package_declarationContext *formal_package_declaration();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_formal_parameter_declarationContext* generic_formal_parameter_declaration();

  class  Generic_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *generic_package_name = nullptr;
    Ada95Parser::NameContext *generic_procedure_name = nullptr;
    Ada95Parser::NameContext *generic_function_name = nullptr;
    Generic_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE();
    Defining_program_unit_nameContext *defining_program_unit_name();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NEW();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    Generic_actual_partContext *generic_actual_part();
    antlr4::tree::TerminalNode *PROCEDURE();
    antlr4::tree::TerminalNode *FUNCTION();
    Defining_designatorContext *defining_designator();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_instantiationContext* generic_instantiation();

  class  Generic_actual_partContext : public antlr4::ParserRuleContext {
  public:
    Generic_actual_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<Generic_associationContext *> generic_association();
    Generic_associationContext* generic_association(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_actual_partContext* generic_actual_part();

  class  Generic_associationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Selector_nameContext *generic_formal_parameter_selector_name = nullptr;
    Generic_associationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Explicit_generic_actual_parameterContext *explicit_generic_actual_parameter();
    antlr4::tree::TerminalNode *ARROW();
    Selector_nameContext *selector_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Generic_associationContext* generic_association();

  class  Explicit_generic_actual_parameterContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *variable_name = nullptr;
    Ada95Parser::NameContext *subprogram_name = nullptr;
    Ada95Parser::NameContext *entry_name = nullptr;
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Ada95Parser::NameContext *package_instance_name = nullptr;
    Explicit_generic_actual_parameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Explicit_generic_actual_parameterContext* explicit_generic_actual_parameter();

  class  Formal_object_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Formal_object_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Defining_identifier_listContext *defining_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Mode_Context *mode_();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    antlr4::tree::TerminalNode *ASSIGN();
    Default_expressionContext *default_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_object_declarationContext* formal_object_declaration();

  class  Formal_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Formal_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    Formal_type_definitionContext *formal_type_definition();
    antlr4::tree::TerminalNode *SEMI();
    Discriminant_partContext *discriminant_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_type_declarationContext* formal_type_declaration();

  class  Formal_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formal_private_type_definitionContext *formal_private_type_definition();
    Formal_derived_type_definitionContext *formal_derived_type_definition();
    Formal_discrete_type_definitionContext *formal_discrete_type_definition();
    Formal_signed_integer_type_definitionContext *formal_signed_integer_type_definition();
    Formal_modular_type_definitionContext *formal_modular_type_definition();
    Formal_floating_point_definitionContext *formal_floating_point_definition();
    Formal_ordinary_fixed_point_definitionContext *formal_ordinary_fixed_point_definition();
    Formal_decimal_fixed_point_definitionContext *formal_decimal_fixed_point_definition();
    Formal_array_type_definitionContext *formal_array_type_definition();
    Formal_access_type_definitionContext *formal_access_type_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_type_definitionContext* formal_type_definition();

  class  Formal_private_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_private_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *TAGGED();
    antlr4::tree::TerminalNode *LIMITED();
    antlr4::tree::TerminalNode *ABSTRACT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_private_type_definitionContext* formal_private_type_definition();

  class  Formal_derived_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *subtype_mark = nullptr;
    Formal_derived_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEW();
    NameContext *name();
    antlr4::tree::TerminalNode *ABSTRACT();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *PRIVATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_derived_type_definitionContext* formal_derived_type_definition();

  class  Formal_discrete_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_discrete_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *BOX();
    antlr4::tree::TerminalNode *RP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_discrete_type_definitionContext* formal_discrete_type_definition();

  class  Formal_signed_integer_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_signed_integer_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE_();
    antlr4::tree::TerminalNode *BOX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_signed_integer_type_definitionContext* formal_signed_integer_type_definition();

  class  Formal_modular_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_modular_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *BOX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_modular_type_definitionContext* formal_modular_type_definition();

  class  Formal_floating_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_floating_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIGITS();
    antlr4::tree::TerminalNode *BOX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_floating_point_definitionContext* formal_floating_point_definition();

  class  Formal_ordinary_fixed_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_ordinary_fixed_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELTA();
    antlr4::tree::TerminalNode *BOX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_ordinary_fixed_point_definitionContext* formal_ordinary_fixed_point_definition();

  class  Formal_decimal_fixed_point_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_decimal_fixed_point_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELTA();
    std::vector<antlr4::tree::TerminalNode *> BOX();
    antlr4::tree::TerminalNode* BOX(size_t i);
    antlr4::tree::TerminalNode *DIGITS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_decimal_fixed_point_definitionContext* formal_decimal_fixed_point_definition();

  class  Formal_array_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_array_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_type_definitionContext *array_type_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_array_type_definitionContext* formal_array_type_definition();

  class  Formal_access_type_definitionContext : public antlr4::ParserRuleContext {
  public:
    Formal_access_type_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Access_type_definitionContext *access_type_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_access_type_definitionContext* formal_access_type_definition();

  class  Formal_subprogram_declarationContext : public antlr4::ParserRuleContext {
  public:
    Formal_subprogram_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    Subprogram_specificationContext *subprogram_specification();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *IS();
    Subprogram_defaultContext *subprogram_default();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_subprogram_declarationContext* formal_subprogram_declaration();

  class  Subprogram_defaultContext : public antlr4::ParserRuleContext {
  public:
    Subprogram_defaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Default_nameContext *default_name();
    antlr4::tree::TerminalNode *BOX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subprogram_defaultContext* subprogram_default();

  class  Default_nameContext : public antlr4::ParserRuleContext {
  public:
    Default_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Default_nameContext* default_name();

  class  Formal_package_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *generic_package_name = nullptr;
    Formal_package_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *PACKAGE();
    Defining_identifierContext *defining_identifier();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NEW();
    Formal_package_actual_partContext *formal_package_actual_part();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_package_declarationContext* formal_package_declaration();

  class  Formal_package_actual_partContext : public antlr4::ParserRuleContext {
  public:
    Formal_package_actual_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *BOX();
    antlr4::tree::TerminalNode *RP();
    Generic_actual_partContext *generic_actual_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Formal_package_actual_partContext* formal_package_actual_part();

  class  Aspect_clauseContext : public antlr4::ParserRuleContext {
  public:
    Aspect_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attribute_definition_clauseContext *attribute_definition_clause();
    Enumeration_representation_clauseContext *enumeration_representation_clause();
    Record_representation_clauseContext *record_representation_clause();
    At_clauseContext *at_clause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Aspect_clauseContext* aspect_clause();

  class  Local_nameContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *library_unit_name = nullptr;
    Local_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Direct_nameContext *direct_name();
    antlr4::tree::TerminalNode *SQ();
    Attribute_designatorContext *attribute_designator();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Local_nameContext* local_name();

  class  Attribute_definition_clauseContext : public antlr4::ParserRuleContext {
  public:
    Attribute_definition_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Local_nameContext *local_name();
    antlr4::tree::TerminalNode *SQ();
    Attribute_designatorContext *attribute_designator();
    antlr4::tree::TerminalNode *USE();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Attribute_definition_clauseContext* attribute_definition_clause();

  class  Enumeration_representation_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *first_subtype_local_name = nullptr;
    Enumeration_representation_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *USE();
    Enumeration_aggregateContext *enumeration_aggregate();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enumeration_representation_clauseContext* enumeration_representation_clause();

  class  Enumeration_aggregateContext : public antlr4::ParserRuleContext {
  public:
    Enumeration_aggregateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_aggregateContext *array_aggregate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enumeration_aggregateContext* enumeration_aggregate();

  class  Record_representation_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *first_subtype_local_name = nullptr;
    Record_representation_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *USE();
    std::vector<antlr4::tree::TerminalNode *> RECORD();
    antlr4::tree::TerminalNode* RECORD(size_t i);
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();
    Mod_clauseContext *mod_clause();
    std::vector<Component_clauseContext *> component_clause();
    Component_clauseContext* component_clause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Record_representation_clauseContext* record_representation_clause();

  class  Component_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::NameContext *component_local_name = nullptr;
    Component_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    PositionContext *position();
    antlr4::tree::TerminalNode *RANGE_();
    First_bitContext *first_bit();
    antlr4::tree::TerminalNode *DOTDOT();
    Last_bitContext *last_bit();
    antlr4::tree::TerminalNode *SEMI();
    NameContext *name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Component_clauseContext* component_clause();

  class  PositionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    PositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PositionContext* position();

  class  First_bitContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Simple_expressionContext *static_simple_expression = nullptr;
    First_bitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  First_bitContext* first_bit();

  class  Last_bitContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::Simple_expressionContext *static_simple_expression = nullptr;
    Last_bitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_expressionContext *simple_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Last_bitContext* last_bit();

  class  Code_statementContext : public antlr4::ParserRuleContext {
  public:
    Code_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Qualified_expressionContext *qualified_expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Code_statementContext* code_statement();

  class  RestrictionContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::IdentifierContext *restriction_identifier = nullptr;
    Ada95Parser::IdentifierContext *restriction_parameter_identifier = nullptr;
    RestrictionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *ARROW();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RestrictionContext* restriction();

  class  At_clauseContext : public antlr4::ParserRuleContext {
  public:
    At_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    Direct_nameContext *direct_name();
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *AT();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SEMI();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  At_clauseContext* at_clause();

  class  Delta_constraintContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Delta_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELTA();
    ExpressionContext *expression();
    Range_constraintContext *range_constraint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Delta_constraintContext* delta_constraint();

  class  Mod_clauseContext : public antlr4::ParserRuleContext {
  public:
    Ada95Parser::ExpressionContext *static_expression = nullptr;
    Mod_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *SEMI();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mod_clauseContext* mod_clause();

  class  Boolean_expressionContext : public antlr4::ParserRuleContext {
  public:
    Boolean_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Boolean_expressionContext* boolean_expression();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool nameSempred(NameContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

