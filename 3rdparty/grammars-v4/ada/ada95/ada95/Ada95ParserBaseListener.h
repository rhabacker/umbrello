
// Generated from ada95/Ada95Parser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "Ada95ParserListener.h"


/**
 * This class provides an empty implementation of Ada95ParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  Ada95ParserBaseListener : public Ada95ParserListener {
public:

  virtual void enterIdentifier(Ada95Parser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(Ada95Parser::IdentifierContext * /*ctx*/) override { }

  virtual void enterNumeric_literal(Ada95Parser::Numeric_literalContext * /*ctx*/) override { }
  virtual void exitNumeric_literal(Ada95Parser::Numeric_literalContext * /*ctx*/) override { }

  virtual void enterCharacter_literal(Ada95Parser::Character_literalContext * /*ctx*/) override { }
  virtual void exitCharacter_literal(Ada95Parser::Character_literalContext * /*ctx*/) override { }

  virtual void enterString_literal(Ada95Parser::String_literalContext * /*ctx*/) override { }
  virtual void exitString_literal(Ada95Parser::String_literalContext * /*ctx*/) override { }

  virtual void enterBasic_declaration(Ada95Parser::Basic_declarationContext * /*ctx*/) override { }
  virtual void exitBasic_declaration(Ada95Parser::Basic_declarationContext * /*ctx*/) override { }

  virtual void enterDefining_identifier(Ada95Parser::Defining_identifierContext * /*ctx*/) override { }
  virtual void exitDefining_identifier(Ada95Parser::Defining_identifierContext * /*ctx*/) override { }

  virtual void enterType_declaration(Ada95Parser::Type_declarationContext * /*ctx*/) override { }
  virtual void exitType_declaration(Ada95Parser::Type_declarationContext * /*ctx*/) override { }

  virtual void enterFull_type_declaration(Ada95Parser::Full_type_declarationContext * /*ctx*/) override { }
  virtual void exitFull_type_declaration(Ada95Parser::Full_type_declarationContext * /*ctx*/) override { }

  virtual void enterType_definition(Ada95Parser::Type_definitionContext * /*ctx*/) override { }
  virtual void exitType_definition(Ada95Parser::Type_definitionContext * /*ctx*/) override { }

  virtual void enterSubtype_declaration(Ada95Parser::Subtype_declarationContext * /*ctx*/) override { }
  virtual void exitSubtype_declaration(Ada95Parser::Subtype_declarationContext * /*ctx*/) override { }

  virtual void enterSubtype_indication(Ada95Parser::Subtype_indicationContext * /*ctx*/) override { }
  virtual void exitSubtype_indication(Ada95Parser::Subtype_indicationContext * /*ctx*/) override { }

  virtual void enterConstraint(Ada95Parser::ConstraintContext * /*ctx*/) override { }
  virtual void exitConstraint(Ada95Parser::ConstraintContext * /*ctx*/) override { }

  virtual void enterScalar_constraint(Ada95Parser::Scalar_constraintContext * /*ctx*/) override { }
  virtual void exitScalar_constraint(Ada95Parser::Scalar_constraintContext * /*ctx*/) override { }

  virtual void enterComposite_constraint(Ada95Parser::Composite_constraintContext * /*ctx*/) override { }
  virtual void exitComposite_constraint(Ada95Parser::Composite_constraintContext * /*ctx*/) override { }

  virtual void enterObject_declaration(Ada95Parser::Object_declarationContext * /*ctx*/) override { }
  virtual void exitObject_declaration(Ada95Parser::Object_declarationContext * /*ctx*/) override { }

  virtual void enterDefining_identifier_list(Ada95Parser::Defining_identifier_listContext * /*ctx*/) override { }
  virtual void exitDefining_identifier_list(Ada95Parser::Defining_identifier_listContext * /*ctx*/) override { }

  virtual void enterNumber_declaration(Ada95Parser::Number_declarationContext * /*ctx*/) override { }
  virtual void exitNumber_declaration(Ada95Parser::Number_declarationContext * /*ctx*/) override { }

  virtual void enterDerived_type_definition(Ada95Parser::Derived_type_definitionContext * /*ctx*/) override { }
  virtual void exitDerived_type_definition(Ada95Parser::Derived_type_definitionContext * /*ctx*/) override { }

  virtual void enterRange_constraint(Ada95Parser::Range_constraintContext * /*ctx*/) override { }
  virtual void exitRange_constraint(Ada95Parser::Range_constraintContext * /*ctx*/) override { }

  virtual void enterRange(Ada95Parser::RangeContext * /*ctx*/) override { }
  virtual void exitRange(Ada95Parser::RangeContext * /*ctx*/) override { }

  virtual void enterEnumeration_type_definition(Ada95Parser::Enumeration_type_definitionContext * /*ctx*/) override { }
  virtual void exitEnumeration_type_definition(Ada95Parser::Enumeration_type_definitionContext * /*ctx*/) override { }

  virtual void enterEnumeration_literal_specification(Ada95Parser::Enumeration_literal_specificationContext * /*ctx*/) override { }
  virtual void exitEnumeration_literal_specification(Ada95Parser::Enumeration_literal_specificationContext * /*ctx*/) override { }

  virtual void enterDefining_character_literal(Ada95Parser::Defining_character_literalContext * /*ctx*/) override { }
  virtual void exitDefining_character_literal(Ada95Parser::Defining_character_literalContext * /*ctx*/) override { }

  virtual void enterInteger_type_definition(Ada95Parser::Integer_type_definitionContext * /*ctx*/) override { }
  virtual void exitInteger_type_definition(Ada95Parser::Integer_type_definitionContext * /*ctx*/) override { }

  virtual void enterSigned_integer_type_definition(Ada95Parser::Signed_integer_type_definitionContext * /*ctx*/) override { }
  virtual void exitSigned_integer_type_definition(Ada95Parser::Signed_integer_type_definitionContext * /*ctx*/) override { }

  virtual void enterModular_type_definition(Ada95Parser::Modular_type_definitionContext * /*ctx*/) override { }
  virtual void exitModular_type_definition(Ada95Parser::Modular_type_definitionContext * /*ctx*/) override { }

  virtual void enterReal_type_definition(Ada95Parser::Real_type_definitionContext * /*ctx*/) override { }
  virtual void exitReal_type_definition(Ada95Parser::Real_type_definitionContext * /*ctx*/) override { }

  virtual void enterFloating_point_definition(Ada95Parser::Floating_point_definitionContext * /*ctx*/) override { }
  virtual void exitFloating_point_definition(Ada95Parser::Floating_point_definitionContext * /*ctx*/) override { }

  virtual void enterReal_range_specification(Ada95Parser::Real_range_specificationContext * /*ctx*/) override { }
  virtual void exitReal_range_specification(Ada95Parser::Real_range_specificationContext * /*ctx*/) override { }

  virtual void enterFixed_point_definition(Ada95Parser::Fixed_point_definitionContext * /*ctx*/) override { }
  virtual void exitFixed_point_definition(Ada95Parser::Fixed_point_definitionContext * /*ctx*/) override { }

  virtual void enterOrdinary_fixed_point_definition(Ada95Parser::Ordinary_fixed_point_definitionContext * /*ctx*/) override { }
  virtual void exitOrdinary_fixed_point_definition(Ada95Parser::Ordinary_fixed_point_definitionContext * /*ctx*/) override { }

  virtual void enterDecimal_fixed_point_definition(Ada95Parser::Decimal_fixed_point_definitionContext * /*ctx*/) override { }
  virtual void exitDecimal_fixed_point_definition(Ada95Parser::Decimal_fixed_point_definitionContext * /*ctx*/) override { }

  virtual void enterDigits_constraint(Ada95Parser::Digits_constraintContext * /*ctx*/) override { }
  virtual void exitDigits_constraint(Ada95Parser::Digits_constraintContext * /*ctx*/) override { }

  virtual void enterArray_type_definition(Ada95Parser::Array_type_definitionContext * /*ctx*/) override { }
  virtual void exitArray_type_definition(Ada95Parser::Array_type_definitionContext * /*ctx*/) override { }

  virtual void enterUnconstrained_array_definition(Ada95Parser::Unconstrained_array_definitionContext * /*ctx*/) override { }
  virtual void exitUnconstrained_array_definition(Ada95Parser::Unconstrained_array_definitionContext * /*ctx*/) override { }

  virtual void enterIndex_subtype_definition(Ada95Parser::Index_subtype_definitionContext * /*ctx*/) override { }
  virtual void exitIndex_subtype_definition(Ada95Parser::Index_subtype_definitionContext * /*ctx*/) override { }

  virtual void enterConstrained_array_definition(Ada95Parser::Constrained_array_definitionContext * /*ctx*/) override { }
  virtual void exitConstrained_array_definition(Ada95Parser::Constrained_array_definitionContext * /*ctx*/) override { }

  virtual void enterDiscrete_subtype_definition(Ada95Parser::Discrete_subtype_definitionContext * /*ctx*/) override { }
  virtual void exitDiscrete_subtype_definition(Ada95Parser::Discrete_subtype_definitionContext * /*ctx*/) override { }

  virtual void enterComponent_definition(Ada95Parser::Component_definitionContext * /*ctx*/) override { }
  virtual void exitComponent_definition(Ada95Parser::Component_definitionContext * /*ctx*/) override { }

  virtual void enterIndex_constraint(Ada95Parser::Index_constraintContext * /*ctx*/) override { }
  virtual void exitIndex_constraint(Ada95Parser::Index_constraintContext * /*ctx*/) override { }

  virtual void enterDiscrete_range(Ada95Parser::Discrete_rangeContext * /*ctx*/) override { }
  virtual void exitDiscrete_range(Ada95Parser::Discrete_rangeContext * /*ctx*/) override { }

  virtual void enterDiscriminant_part(Ada95Parser::Discriminant_partContext * /*ctx*/) override { }
  virtual void exitDiscriminant_part(Ada95Parser::Discriminant_partContext * /*ctx*/) override { }

  virtual void enterUnknown_discriminant_part(Ada95Parser::Unknown_discriminant_partContext * /*ctx*/) override { }
  virtual void exitUnknown_discriminant_part(Ada95Parser::Unknown_discriminant_partContext * /*ctx*/) override { }

  virtual void enterKnown_discriminant_part(Ada95Parser::Known_discriminant_partContext * /*ctx*/) override { }
  virtual void exitKnown_discriminant_part(Ada95Parser::Known_discriminant_partContext * /*ctx*/) override { }

  virtual void enterDiscriminant_specification(Ada95Parser::Discriminant_specificationContext * /*ctx*/) override { }
  virtual void exitDiscriminant_specification(Ada95Parser::Discriminant_specificationContext * /*ctx*/) override { }

  virtual void enterDefault_expression(Ada95Parser::Default_expressionContext * /*ctx*/) override { }
  virtual void exitDefault_expression(Ada95Parser::Default_expressionContext * /*ctx*/) override { }

  virtual void enterDiscriminant_constraint(Ada95Parser::Discriminant_constraintContext * /*ctx*/) override { }
  virtual void exitDiscriminant_constraint(Ada95Parser::Discriminant_constraintContext * /*ctx*/) override { }

  virtual void enterDiscriminant_association(Ada95Parser::Discriminant_associationContext * /*ctx*/) override { }
  virtual void exitDiscriminant_association(Ada95Parser::Discriminant_associationContext * /*ctx*/) override { }

  virtual void enterRecord_type_definition(Ada95Parser::Record_type_definitionContext * /*ctx*/) override { }
  virtual void exitRecord_type_definition(Ada95Parser::Record_type_definitionContext * /*ctx*/) override { }

  virtual void enterRecord_definition(Ada95Parser::Record_definitionContext * /*ctx*/) override { }
  virtual void exitRecord_definition(Ada95Parser::Record_definitionContext * /*ctx*/) override { }

  virtual void enterComponent_list(Ada95Parser::Component_listContext * /*ctx*/) override { }
  virtual void exitComponent_list(Ada95Parser::Component_listContext * /*ctx*/) override { }

  virtual void enterComponent_item(Ada95Parser::Component_itemContext * /*ctx*/) override { }
  virtual void exitComponent_item(Ada95Parser::Component_itemContext * /*ctx*/) override { }

  virtual void enterComponent_declaration(Ada95Parser::Component_declarationContext * /*ctx*/) override { }
  virtual void exitComponent_declaration(Ada95Parser::Component_declarationContext * /*ctx*/) override { }

  virtual void enterVariant_part(Ada95Parser::Variant_partContext * /*ctx*/) override { }
  virtual void exitVariant_part(Ada95Parser::Variant_partContext * /*ctx*/) override { }

  virtual void enterVariant(Ada95Parser::VariantContext * /*ctx*/) override { }
  virtual void exitVariant(Ada95Parser::VariantContext * /*ctx*/) override { }

  virtual void enterDiscrete_choice_list(Ada95Parser::Discrete_choice_listContext * /*ctx*/) override { }
  virtual void exitDiscrete_choice_list(Ada95Parser::Discrete_choice_listContext * /*ctx*/) override { }

  virtual void enterDiscrete_choice(Ada95Parser::Discrete_choiceContext * /*ctx*/) override { }
  virtual void exitDiscrete_choice(Ada95Parser::Discrete_choiceContext * /*ctx*/) override { }

  virtual void enterRecord_extension_part(Ada95Parser::Record_extension_partContext * /*ctx*/) override { }
  virtual void exitRecord_extension_part(Ada95Parser::Record_extension_partContext * /*ctx*/) override { }

  virtual void enterAccess_type_definition(Ada95Parser::Access_type_definitionContext * /*ctx*/) override { }
  virtual void exitAccess_type_definition(Ada95Parser::Access_type_definitionContext * /*ctx*/) override { }

  virtual void enterAccess_to_object_definition(Ada95Parser::Access_to_object_definitionContext * /*ctx*/) override { }
  virtual void exitAccess_to_object_definition(Ada95Parser::Access_to_object_definitionContext * /*ctx*/) override { }

  virtual void enterGeneral_access_modifier(Ada95Parser::General_access_modifierContext * /*ctx*/) override { }
  virtual void exitGeneral_access_modifier(Ada95Parser::General_access_modifierContext * /*ctx*/) override { }

  virtual void enterAccess_to_subprogram_definition(Ada95Parser::Access_to_subprogram_definitionContext * /*ctx*/) override { }
  virtual void exitAccess_to_subprogram_definition(Ada95Parser::Access_to_subprogram_definitionContext * /*ctx*/) override { }

  virtual void enterAccess_definition(Ada95Parser::Access_definitionContext * /*ctx*/) override { }
  virtual void exitAccess_definition(Ada95Parser::Access_definitionContext * /*ctx*/) override { }

  virtual void enterIncomplete_type_declaration(Ada95Parser::Incomplete_type_declarationContext * /*ctx*/) override { }
  virtual void exitIncomplete_type_declaration(Ada95Parser::Incomplete_type_declarationContext * /*ctx*/) override { }

  virtual void enterDeclarative_part(Ada95Parser::Declarative_partContext * /*ctx*/) override { }
  virtual void exitDeclarative_part(Ada95Parser::Declarative_partContext * /*ctx*/) override { }

  virtual void enterDeclarative_item(Ada95Parser::Declarative_itemContext * /*ctx*/) override { }
  virtual void exitDeclarative_item(Ada95Parser::Declarative_itemContext * /*ctx*/) override { }

  virtual void enterBasic_declarative_item(Ada95Parser::Basic_declarative_itemContext * /*ctx*/) override { }
  virtual void exitBasic_declarative_item(Ada95Parser::Basic_declarative_itemContext * /*ctx*/) override { }

  virtual void enterBody(Ada95Parser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(Ada95Parser::BodyContext * /*ctx*/) override { }

  virtual void enterProper_body(Ada95Parser::Proper_bodyContext * /*ctx*/) override { }
  virtual void exitProper_body(Ada95Parser::Proper_bodyContext * /*ctx*/) override { }

  virtual void enterName(Ada95Parser::NameContext * /*ctx*/) override { }
  virtual void exitName(Ada95Parser::NameContext * /*ctx*/) override { }

  virtual void enterDirect_name(Ada95Parser::Direct_nameContext * /*ctx*/) override { }
  virtual void exitDirect_name(Ada95Parser::Direct_nameContext * /*ctx*/) override { }

  virtual void enterSelector_name(Ada95Parser::Selector_nameContext * /*ctx*/) override { }
  virtual void exitSelector_name(Ada95Parser::Selector_nameContext * /*ctx*/) override { }

  virtual void enterAttribute_designator(Ada95Parser::Attribute_designatorContext * /*ctx*/) override { }
  virtual void exitAttribute_designator(Ada95Parser::Attribute_designatorContext * /*ctx*/) override { }

  virtual void enterRange_attribute_reference(Ada95Parser::Range_attribute_referenceContext * /*ctx*/) override { }
  virtual void exitRange_attribute_reference(Ada95Parser::Range_attribute_referenceContext * /*ctx*/) override { }

  virtual void enterRange_attribute_designator(Ada95Parser::Range_attribute_designatorContext * /*ctx*/) override { }
  virtual void exitRange_attribute_designator(Ada95Parser::Range_attribute_designatorContext * /*ctx*/) override { }

  virtual void enterAggregate(Ada95Parser::AggregateContext * /*ctx*/) override { }
  virtual void exitAggregate(Ada95Parser::AggregateContext * /*ctx*/) override { }

  virtual void enterRecord_aggregate(Ada95Parser::Record_aggregateContext * /*ctx*/) override { }
  virtual void exitRecord_aggregate(Ada95Parser::Record_aggregateContext * /*ctx*/) override { }

  virtual void enterRecord_component_association_list(Ada95Parser::Record_component_association_listContext * /*ctx*/) override { }
  virtual void exitRecord_component_association_list(Ada95Parser::Record_component_association_listContext * /*ctx*/) override { }

  virtual void enterRecord_component_association(Ada95Parser::Record_component_associationContext * /*ctx*/) override { }
  virtual void exitRecord_component_association(Ada95Parser::Record_component_associationContext * /*ctx*/) override { }

  virtual void enterComponent_choice_list(Ada95Parser::Component_choice_listContext * /*ctx*/) override { }
  virtual void exitComponent_choice_list(Ada95Parser::Component_choice_listContext * /*ctx*/) override { }

  virtual void enterExtension_aggregate(Ada95Parser::Extension_aggregateContext * /*ctx*/) override { }
  virtual void exitExtension_aggregate(Ada95Parser::Extension_aggregateContext * /*ctx*/) override { }

  virtual void enterAncestor_part(Ada95Parser::Ancestor_partContext * /*ctx*/) override { }
  virtual void exitAncestor_part(Ada95Parser::Ancestor_partContext * /*ctx*/) override { }

  virtual void enterArray_aggregate(Ada95Parser::Array_aggregateContext * /*ctx*/) override { }
  virtual void exitArray_aggregate(Ada95Parser::Array_aggregateContext * /*ctx*/) override { }

  virtual void enterPositional_array_aggregate(Ada95Parser::Positional_array_aggregateContext * /*ctx*/) override { }
  virtual void exitPositional_array_aggregate(Ada95Parser::Positional_array_aggregateContext * /*ctx*/) override { }

  virtual void enterNamed_array_aggregate(Ada95Parser::Named_array_aggregateContext * /*ctx*/) override { }
  virtual void exitNamed_array_aggregate(Ada95Parser::Named_array_aggregateContext * /*ctx*/) override { }

  virtual void enterArray_component_association(Ada95Parser::Array_component_associationContext * /*ctx*/) override { }
  virtual void exitArray_component_association(Ada95Parser::Array_component_associationContext * /*ctx*/) override { }

  virtual void enterExpression(Ada95Parser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Ada95Parser::ExpressionContext * /*ctx*/) override { }

  virtual void enterRelation(Ada95Parser::RelationContext * /*ctx*/) override { }
  virtual void exitRelation(Ada95Parser::RelationContext * /*ctx*/) override { }

  virtual void enterSimple_expression(Ada95Parser::Simple_expressionContext * /*ctx*/) override { }
  virtual void exitSimple_expression(Ada95Parser::Simple_expressionContext * /*ctx*/) override { }

  virtual void enterTerm(Ada95Parser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(Ada95Parser::TermContext * /*ctx*/) override { }

  virtual void enterFactor(Ada95Parser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(Ada95Parser::FactorContext * /*ctx*/) override { }

  virtual void enterPrimary(Ada95Parser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(Ada95Parser::PrimaryContext * /*ctx*/) override { }

  virtual void enterLogical_operator(Ada95Parser::Logical_operatorContext * /*ctx*/) override { }
  virtual void exitLogical_operator(Ada95Parser::Logical_operatorContext * /*ctx*/) override { }

  virtual void enterRelational_operator(Ada95Parser::Relational_operatorContext * /*ctx*/) override { }
  virtual void exitRelational_operator(Ada95Parser::Relational_operatorContext * /*ctx*/) override { }

  virtual void enterBinary_adding_operator(Ada95Parser::Binary_adding_operatorContext * /*ctx*/) override { }
  virtual void exitBinary_adding_operator(Ada95Parser::Binary_adding_operatorContext * /*ctx*/) override { }

  virtual void enterUnary_adding_operator(Ada95Parser::Unary_adding_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_adding_operator(Ada95Parser::Unary_adding_operatorContext * /*ctx*/) override { }

  virtual void enterMultiplying_operator(Ada95Parser::Multiplying_operatorContext * /*ctx*/) override { }
  virtual void exitMultiplying_operator(Ada95Parser::Multiplying_operatorContext * /*ctx*/) override { }

  virtual void enterHighest_precedence_operator(Ada95Parser::Highest_precedence_operatorContext * /*ctx*/) override { }
  virtual void exitHighest_precedence_operator(Ada95Parser::Highest_precedence_operatorContext * /*ctx*/) override { }

  virtual void enterQualified_expression(Ada95Parser::Qualified_expressionContext * /*ctx*/) override { }
  virtual void exitQualified_expression(Ada95Parser::Qualified_expressionContext * /*ctx*/) override { }

  virtual void enterAllocator(Ada95Parser::AllocatorContext * /*ctx*/) override { }
  virtual void exitAllocator(Ada95Parser::AllocatorContext * /*ctx*/) override { }

  virtual void enterSequence_of_statements(Ada95Parser::Sequence_of_statementsContext * /*ctx*/) override { }
  virtual void exitSequence_of_statements(Ada95Parser::Sequence_of_statementsContext * /*ctx*/) override { }

  virtual void enterStatement(Ada95Parser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Ada95Parser::StatementContext * /*ctx*/) override { }

  virtual void enterSimple_statement(Ada95Parser::Simple_statementContext * /*ctx*/) override { }
  virtual void exitSimple_statement(Ada95Parser::Simple_statementContext * /*ctx*/) override { }

  virtual void enterCompound_statement(Ada95Parser::Compound_statementContext * /*ctx*/) override { }
  virtual void exitCompound_statement(Ada95Parser::Compound_statementContext * /*ctx*/) override { }

  virtual void enterNull_statement(Ada95Parser::Null_statementContext * /*ctx*/) override { }
  virtual void exitNull_statement(Ada95Parser::Null_statementContext * /*ctx*/) override { }

  virtual void enterLabel(Ada95Parser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(Ada95Parser::LabelContext * /*ctx*/) override { }

  virtual void enterStatement_identifier(Ada95Parser::Statement_identifierContext * /*ctx*/) override { }
  virtual void exitStatement_identifier(Ada95Parser::Statement_identifierContext * /*ctx*/) override { }

  virtual void enterAssignment_statement(Ada95Parser::Assignment_statementContext * /*ctx*/) override { }
  virtual void exitAssignment_statement(Ada95Parser::Assignment_statementContext * /*ctx*/) override { }

  virtual void enterIf_statement(Ada95Parser::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(Ada95Parser::If_statementContext * /*ctx*/) override { }

  virtual void enterCondition(Ada95Parser::ConditionContext * /*ctx*/) override { }
  virtual void exitCondition(Ada95Parser::ConditionContext * /*ctx*/) override { }

  virtual void enterCase_statement(Ada95Parser::Case_statementContext * /*ctx*/) override { }
  virtual void exitCase_statement(Ada95Parser::Case_statementContext * /*ctx*/) override { }

  virtual void enterCase_statement_alternative(Ada95Parser::Case_statement_alternativeContext * /*ctx*/) override { }
  virtual void exitCase_statement_alternative(Ada95Parser::Case_statement_alternativeContext * /*ctx*/) override { }

  virtual void enterLoop_statement(Ada95Parser::Loop_statementContext * /*ctx*/) override { }
  virtual void exitLoop_statement(Ada95Parser::Loop_statementContext * /*ctx*/) override { }

  virtual void enterIteration_scheme(Ada95Parser::Iteration_schemeContext * /*ctx*/) override { }
  virtual void exitIteration_scheme(Ada95Parser::Iteration_schemeContext * /*ctx*/) override { }

  virtual void enterLoop_parameter_specification(Ada95Parser::Loop_parameter_specificationContext * /*ctx*/) override { }
  virtual void exitLoop_parameter_specification(Ada95Parser::Loop_parameter_specificationContext * /*ctx*/) override { }

  virtual void enterBlock_statement(Ada95Parser::Block_statementContext * /*ctx*/) override { }
  virtual void exitBlock_statement(Ada95Parser::Block_statementContext * /*ctx*/) override { }

  virtual void enterExit_statement(Ada95Parser::Exit_statementContext * /*ctx*/) override { }
  virtual void exitExit_statement(Ada95Parser::Exit_statementContext * /*ctx*/) override { }

  virtual void enterGoto_statement(Ada95Parser::Goto_statementContext * /*ctx*/) override { }
  virtual void exitGoto_statement(Ada95Parser::Goto_statementContext * /*ctx*/) override { }

  virtual void enterPragma_statement(Ada95Parser::Pragma_statementContext * /*ctx*/) override { }
  virtual void exitPragma_statement(Ada95Parser::Pragma_statementContext * /*ctx*/) override { }

  virtual void enterPragma_argument_association(Ada95Parser::Pragma_argument_associationContext * /*ctx*/) override { }
  virtual void exitPragma_argument_association(Ada95Parser::Pragma_argument_associationContext * /*ctx*/) override { }

  virtual void enterSubprogram_declaration(Ada95Parser::Subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitSubprogram_declaration(Ada95Parser::Subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterAbstract_subprogram_declaration(Ada95Parser::Abstract_subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitAbstract_subprogram_declaration(Ada95Parser::Abstract_subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterSubprogram_specification(Ada95Parser::Subprogram_specificationContext * /*ctx*/) override { }
  virtual void exitSubprogram_specification(Ada95Parser::Subprogram_specificationContext * /*ctx*/) override { }

  virtual void enterDesignator(Ada95Parser::DesignatorContext * /*ctx*/) override { }
  virtual void exitDesignator(Ada95Parser::DesignatorContext * /*ctx*/) override { }

  virtual void enterDefining_designator(Ada95Parser::Defining_designatorContext * /*ctx*/) override { }
  virtual void exitDefining_designator(Ada95Parser::Defining_designatorContext * /*ctx*/) override { }

  virtual void enterDefining_program_unit_name(Ada95Parser::Defining_program_unit_nameContext * /*ctx*/) override { }
  virtual void exitDefining_program_unit_name(Ada95Parser::Defining_program_unit_nameContext * /*ctx*/) override { }

  virtual void enterOperator_symbol(Ada95Parser::Operator_symbolContext * /*ctx*/) override { }
  virtual void exitOperator_symbol(Ada95Parser::Operator_symbolContext * /*ctx*/) override { }

  virtual void enterDefining_operator_symbol(Ada95Parser::Defining_operator_symbolContext * /*ctx*/) override { }
  virtual void exitDefining_operator_symbol(Ada95Parser::Defining_operator_symbolContext * /*ctx*/) override { }

  virtual void enterParameter_profile(Ada95Parser::Parameter_profileContext * /*ctx*/) override { }
  virtual void exitParameter_profile(Ada95Parser::Parameter_profileContext * /*ctx*/) override { }

  virtual void enterParameter_and_result_profile(Ada95Parser::Parameter_and_result_profileContext * /*ctx*/) override { }
  virtual void exitParameter_and_result_profile(Ada95Parser::Parameter_and_result_profileContext * /*ctx*/) override { }

  virtual void enterFormal_part(Ada95Parser::Formal_partContext * /*ctx*/) override { }
  virtual void exitFormal_part(Ada95Parser::Formal_partContext * /*ctx*/) override { }

  virtual void enterParameter_specification(Ada95Parser::Parameter_specificationContext * /*ctx*/) override { }
  virtual void exitParameter_specification(Ada95Parser::Parameter_specificationContext * /*ctx*/) override { }

  virtual void enterMode_(Ada95Parser::Mode_Context * /*ctx*/) override { }
  virtual void exitMode_(Ada95Parser::Mode_Context * /*ctx*/) override { }

  virtual void enterSubprogram_body(Ada95Parser::Subprogram_bodyContext * /*ctx*/) override { }
  virtual void exitSubprogram_body(Ada95Parser::Subprogram_bodyContext * /*ctx*/) override { }

  virtual void enterProcedure_call_statement(Ada95Parser::Procedure_call_statementContext * /*ctx*/) override { }
  virtual void exitProcedure_call_statement(Ada95Parser::Procedure_call_statementContext * /*ctx*/) override { }

  virtual void enterActual_parameter_part(Ada95Parser::Actual_parameter_partContext * /*ctx*/) override { }
  virtual void exitActual_parameter_part(Ada95Parser::Actual_parameter_partContext * /*ctx*/) override { }

  virtual void enterParameter_association(Ada95Parser::Parameter_associationContext * /*ctx*/) override { }
  virtual void exitParameter_association(Ada95Parser::Parameter_associationContext * /*ctx*/) override { }

  virtual void enterExplicit_actual_parameter(Ada95Parser::Explicit_actual_parameterContext * /*ctx*/) override { }
  virtual void exitExplicit_actual_parameter(Ada95Parser::Explicit_actual_parameterContext * /*ctx*/) override { }

  virtual void enterReturn_statement(Ada95Parser::Return_statementContext * /*ctx*/) override { }
  virtual void exitReturn_statement(Ada95Parser::Return_statementContext * /*ctx*/) override { }

  virtual void enterPackage_declaration(Ada95Parser::Package_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_declaration(Ada95Parser::Package_declarationContext * /*ctx*/) override { }

  virtual void enterPackage_specification(Ada95Parser::Package_specificationContext * /*ctx*/) override { }
  virtual void exitPackage_specification(Ada95Parser::Package_specificationContext * /*ctx*/) override { }

  virtual void enterPackage_body(Ada95Parser::Package_bodyContext * /*ctx*/) override { }
  virtual void exitPackage_body(Ada95Parser::Package_bodyContext * /*ctx*/) override { }

  virtual void enterPrivate_type_declaration(Ada95Parser::Private_type_declarationContext * /*ctx*/) override { }
  virtual void exitPrivate_type_declaration(Ada95Parser::Private_type_declarationContext * /*ctx*/) override { }

  virtual void enterPrivate_extension_declaration(Ada95Parser::Private_extension_declarationContext * /*ctx*/) override { }
  virtual void exitPrivate_extension_declaration(Ada95Parser::Private_extension_declarationContext * /*ctx*/) override { }

  virtual void enterUse_clause(Ada95Parser::Use_clauseContext * /*ctx*/) override { }
  virtual void exitUse_clause(Ada95Parser::Use_clauseContext * /*ctx*/) override { }

  virtual void enterUse_package_clause(Ada95Parser::Use_package_clauseContext * /*ctx*/) override { }
  virtual void exitUse_package_clause(Ada95Parser::Use_package_clauseContext * /*ctx*/) override { }

  virtual void enterUse_type_clause(Ada95Parser::Use_type_clauseContext * /*ctx*/) override { }
  virtual void exitUse_type_clause(Ada95Parser::Use_type_clauseContext * /*ctx*/) override { }

  virtual void enterRenaming_declaration(Ada95Parser::Renaming_declarationContext * /*ctx*/) override { }
  virtual void exitRenaming_declaration(Ada95Parser::Renaming_declarationContext * /*ctx*/) override { }

  virtual void enterObject_renaming_declaration(Ada95Parser::Object_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitObject_renaming_declaration(Ada95Parser::Object_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterException_renaming_declaration(Ada95Parser::Exception_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitException_renaming_declaration(Ada95Parser::Exception_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterPackage_renaming_declaration(Ada95Parser::Package_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitPackage_renaming_declaration(Ada95Parser::Package_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterSubprogram_renaming_declaration(Ada95Parser::Subprogram_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitSubprogram_renaming_declaration(Ada95Parser::Subprogram_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterGeneric_renaming_declaration(Ada95Parser::Generic_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitGeneric_renaming_declaration(Ada95Parser::Generic_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterTask_type_declaration(Ada95Parser::Task_type_declarationContext * /*ctx*/) override { }
  virtual void exitTask_type_declaration(Ada95Parser::Task_type_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_task_declaration(Ada95Parser::Single_task_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_task_declaration(Ada95Parser::Single_task_declarationContext * /*ctx*/) override { }

  virtual void enterTask_definition(Ada95Parser::Task_definitionContext * /*ctx*/) override { }
  virtual void exitTask_definition(Ada95Parser::Task_definitionContext * /*ctx*/) override { }

  virtual void enterTask_item(Ada95Parser::Task_itemContext * /*ctx*/) override { }
  virtual void exitTask_item(Ada95Parser::Task_itemContext * /*ctx*/) override { }

  virtual void enterTask_body(Ada95Parser::Task_bodyContext * /*ctx*/) override { }
  virtual void exitTask_body(Ada95Parser::Task_bodyContext * /*ctx*/) override { }

  virtual void enterProtected_type_declaration(Ada95Parser::Protected_type_declarationContext * /*ctx*/) override { }
  virtual void exitProtected_type_declaration(Ada95Parser::Protected_type_declarationContext * /*ctx*/) override { }

  virtual void enterSingle_protected_declaration(Ada95Parser::Single_protected_declarationContext * /*ctx*/) override { }
  virtual void exitSingle_protected_declaration(Ada95Parser::Single_protected_declarationContext * /*ctx*/) override { }

  virtual void enterProtected_definition(Ada95Parser::Protected_definitionContext * /*ctx*/) override { }
  virtual void exitProtected_definition(Ada95Parser::Protected_definitionContext * /*ctx*/) override { }

  virtual void enterProtected_operation_declaration(Ada95Parser::Protected_operation_declarationContext * /*ctx*/) override { }
  virtual void exitProtected_operation_declaration(Ada95Parser::Protected_operation_declarationContext * /*ctx*/) override { }

  virtual void enterProtected_element_declaration(Ada95Parser::Protected_element_declarationContext * /*ctx*/) override { }
  virtual void exitProtected_element_declaration(Ada95Parser::Protected_element_declarationContext * /*ctx*/) override { }

  virtual void enterProtected_body(Ada95Parser::Protected_bodyContext * /*ctx*/) override { }
  virtual void exitProtected_body(Ada95Parser::Protected_bodyContext * /*ctx*/) override { }

  virtual void enterProtected_operation_item(Ada95Parser::Protected_operation_itemContext * /*ctx*/) override { }
  virtual void exitProtected_operation_item(Ada95Parser::Protected_operation_itemContext * /*ctx*/) override { }

  virtual void enterEntry_declaration(Ada95Parser::Entry_declarationContext * /*ctx*/) override { }
  virtual void exitEntry_declaration(Ada95Parser::Entry_declarationContext * /*ctx*/) override { }

  virtual void enterAccept_statement(Ada95Parser::Accept_statementContext * /*ctx*/) override { }
  virtual void exitAccept_statement(Ada95Parser::Accept_statementContext * /*ctx*/) override { }

  virtual void enterEntry_index(Ada95Parser::Entry_indexContext * /*ctx*/) override { }
  virtual void exitEntry_index(Ada95Parser::Entry_indexContext * /*ctx*/) override { }

  virtual void enterEntry_body(Ada95Parser::Entry_bodyContext * /*ctx*/) override { }
  virtual void exitEntry_body(Ada95Parser::Entry_bodyContext * /*ctx*/) override { }

  virtual void enterEntry_body_formal_part(Ada95Parser::Entry_body_formal_partContext * /*ctx*/) override { }
  virtual void exitEntry_body_formal_part(Ada95Parser::Entry_body_formal_partContext * /*ctx*/) override { }

  virtual void enterEntry_barrier(Ada95Parser::Entry_barrierContext * /*ctx*/) override { }
  virtual void exitEntry_barrier(Ada95Parser::Entry_barrierContext * /*ctx*/) override { }

  virtual void enterEntry_index_specification(Ada95Parser::Entry_index_specificationContext * /*ctx*/) override { }
  virtual void exitEntry_index_specification(Ada95Parser::Entry_index_specificationContext * /*ctx*/) override { }

  virtual void enterEntry_call_statement(Ada95Parser::Entry_call_statementContext * /*ctx*/) override { }
  virtual void exitEntry_call_statement(Ada95Parser::Entry_call_statementContext * /*ctx*/) override { }

  virtual void enterRequeue_statement(Ada95Parser::Requeue_statementContext * /*ctx*/) override { }
  virtual void exitRequeue_statement(Ada95Parser::Requeue_statementContext * /*ctx*/) override { }

  virtual void enterDelay_statement(Ada95Parser::Delay_statementContext * /*ctx*/) override { }
  virtual void exitDelay_statement(Ada95Parser::Delay_statementContext * /*ctx*/) override { }

  virtual void enterDelay_until_statement(Ada95Parser::Delay_until_statementContext * /*ctx*/) override { }
  virtual void exitDelay_until_statement(Ada95Parser::Delay_until_statementContext * /*ctx*/) override { }

  virtual void enterDelay_relative_statement(Ada95Parser::Delay_relative_statementContext * /*ctx*/) override { }
  virtual void exitDelay_relative_statement(Ada95Parser::Delay_relative_statementContext * /*ctx*/) override { }

  virtual void enterSelect_statement(Ada95Parser::Select_statementContext * /*ctx*/) override { }
  virtual void exitSelect_statement(Ada95Parser::Select_statementContext * /*ctx*/) override { }

  virtual void enterSelective_accept(Ada95Parser::Selective_acceptContext * /*ctx*/) override { }
  virtual void exitSelective_accept(Ada95Parser::Selective_acceptContext * /*ctx*/) override { }

  virtual void enterGuard(Ada95Parser::GuardContext * /*ctx*/) override { }
  virtual void exitGuard(Ada95Parser::GuardContext * /*ctx*/) override { }

  virtual void enterSelect_alternative(Ada95Parser::Select_alternativeContext * /*ctx*/) override { }
  virtual void exitSelect_alternative(Ada95Parser::Select_alternativeContext * /*ctx*/) override { }

  virtual void enterAccept_alternative(Ada95Parser::Accept_alternativeContext * /*ctx*/) override { }
  virtual void exitAccept_alternative(Ada95Parser::Accept_alternativeContext * /*ctx*/) override { }

  virtual void enterDelay_alternative(Ada95Parser::Delay_alternativeContext * /*ctx*/) override { }
  virtual void exitDelay_alternative(Ada95Parser::Delay_alternativeContext * /*ctx*/) override { }

  virtual void enterTerminate_alternative(Ada95Parser::Terminate_alternativeContext * /*ctx*/) override { }
  virtual void exitTerminate_alternative(Ada95Parser::Terminate_alternativeContext * /*ctx*/) override { }

  virtual void enterTimed_entry_call(Ada95Parser::Timed_entry_callContext * /*ctx*/) override { }
  virtual void exitTimed_entry_call(Ada95Parser::Timed_entry_callContext * /*ctx*/) override { }

  virtual void enterEntry_call_alternative(Ada95Parser::Entry_call_alternativeContext * /*ctx*/) override { }
  virtual void exitEntry_call_alternative(Ada95Parser::Entry_call_alternativeContext * /*ctx*/) override { }

  virtual void enterConditional_entry_call(Ada95Parser::Conditional_entry_callContext * /*ctx*/) override { }
  virtual void exitConditional_entry_call(Ada95Parser::Conditional_entry_callContext * /*ctx*/) override { }

  virtual void enterAsynchronous_select(Ada95Parser::Asynchronous_selectContext * /*ctx*/) override { }
  virtual void exitAsynchronous_select(Ada95Parser::Asynchronous_selectContext * /*ctx*/) override { }

  virtual void enterTriggering_alternative(Ada95Parser::Triggering_alternativeContext * /*ctx*/) override { }
  virtual void exitTriggering_alternative(Ada95Parser::Triggering_alternativeContext * /*ctx*/) override { }

  virtual void enterTriggering_statement(Ada95Parser::Triggering_statementContext * /*ctx*/) override { }
  virtual void exitTriggering_statement(Ada95Parser::Triggering_statementContext * /*ctx*/) override { }

  virtual void enterAbortable_part(Ada95Parser::Abortable_partContext * /*ctx*/) override { }
  virtual void exitAbortable_part(Ada95Parser::Abortable_partContext * /*ctx*/) override { }

  virtual void enterAbort_statement(Ada95Parser::Abort_statementContext * /*ctx*/) override { }
  virtual void exitAbort_statement(Ada95Parser::Abort_statementContext * /*ctx*/) override { }

  virtual void enterCompilation(Ada95Parser::CompilationContext * /*ctx*/) override { }
  virtual void exitCompilation(Ada95Parser::CompilationContext * /*ctx*/) override { }

  virtual void enterCompilation_unit(Ada95Parser::Compilation_unitContext * /*ctx*/) override { }
  virtual void exitCompilation_unit(Ada95Parser::Compilation_unitContext * /*ctx*/) override { }

  virtual void enterLibrary_item(Ada95Parser::Library_itemContext * /*ctx*/) override { }
  virtual void exitLibrary_item(Ada95Parser::Library_itemContext * /*ctx*/) override { }

  virtual void enterLibrary_unit_declaration(Ada95Parser::Library_unit_declarationContext * /*ctx*/) override { }
  virtual void exitLibrary_unit_declaration(Ada95Parser::Library_unit_declarationContext * /*ctx*/) override { }

  virtual void enterLibrary_unit_renaming_declaration(Ada95Parser::Library_unit_renaming_declarationContext * /*ctx*/) override { }
  virtual void exitLibrary_unit_renaming_declaration(Ada95Parser::Library_unit_renaming_declarationContext * /*ctx*/) override { }

  virtual void enterLibrary_unit_body(Ada95Parser::Library_unit_bodyContext * /*ctx*/) override { }
  virtual void exitLibrary_unit_body(Ada95Parser::Library_unit_bodyContext * /*ctx*/) override { }

  virtual void enterParent_unit_name(Ada95Parser::Parent_unit_nameContext * /*ctx*/) override { }
  virtual void exitParent_unit_name(Ada95Parser::Parent_unit_nameContext * /*ctx*/) override { }

  virtual void enterContext_clause(Ada95Parser::Context_clauseContext * /*ctx*/) override { }
  virtual void exitContext_clause(Ada95Parser::Context_clauseContext * /*ctx*/) override { }

  virtual void enterContext_item(Ada95Parser::Context_itemContext * /*ctx*/) override { }
  virtual void exitContext_item(Ada95Parser::Context_itemContext * /*ctx*/) override { }

  virtual void enterWith_clause(Ada95Parser::With_clauseContext * /*ctx*/) override { }
  virtual void exitWith_clause(Ada95Parser::With_clauseContext * /*ctx*/) override { }

  virtual void enterBody_stub(Ada95Parser::Body_stubContext * /*ctx*/) override { }
  virtual void exitBody_stub(Ada95Parser::Body_stubContext * /*ctx*/) override { }

  virtual void enterSubprogram_body_stub(Ada95Parser::Subprogram_body_stubContext * /*ctx*/) override { }
  virtual void exitSubprogram_body_stub(Ada95Parser::Subprogram_body_stubContext * /*ctx*/) override { }

  virtual void enterPackage_body_stub(Ada95Parser::Package_body_stubContext * /*ctx*/) override { }
  virtual void exitPackage_body_stub(Ada95Parser::Package_body_stubContext * /*ctx*/) override { }

  virtual void enterTask_body_stub(Ada95Parser::Task_body_stubContext * /*ctx*/) override { }
  virtual void exitTask_body_stub(Ada95Parser::Task_body_stubContext * /*ctx*/) override { }

  virtual void enterProtected_body_stub(Ada95Parser::Protected_body_stubContext * /*ctx*/) override { }
  virtual void exitProtected_body_stub(Ada95Parser::Protected_body_stubContext * /*ctx*/) override { }

  virtual void enterSubunit(Ada95Parser::SubunitContext * /*ctx*/) override { }
  virtual void exitSubunit(Ada95Parser::SubunitContext * /*ctx*/) override { }

  virtual void enterException_declaration(Ada95Parser::Exception_declarationContext * /*ctx*/) override { }
  virtual void exitException_declaration(Ada95Parser::Exception_declarationContext * /*ctx*/) override { }

  virtual void enterHandled_sequence_of_statements(Ada95Parser::Handled_sequence_of_statementsContext * /*ctx*/) override { }
  virtual void exitHandled_sequence_of_statements(Ada95Parser::Handled_sequence_of_statementsContext * /*ctx*/) override { }

  virtual void enterException_handler(Ada95Parser::Exception_handlerContext * /*ctx*/) override { }
  virtual void exitException_handler(Ada95Parser::Exception_handlerContext * /*ctx*/) override { }

  virtual void enterChoice_parameter_specification(Ada95Parser::Choice_parameter_specificationContext * /*ctx*/) override { }
  virtual void exitChoice_parameter_specification(Ada95Parser::Choice_parameter_specificationContext * /*ctx*/) override { }

  virtual void enterException_choice(Ada95Parser::Exception_choiceContext * /*ctx*/) override { }
  virtual void exitException_choice(Ada95Parser::Exception_choiceContext * /*ctx*/) override { }

  virtual void enterRaise_statement(Ada95Parser::Raise_statementContext * /*ctx*/) override { }
  virtual void exitRaise_statement(Ada95Parser::Raise_statementContext * /*ctx*/) override { }

  virtual void enterGeneric_declaration(Ada95Parser::Generic_declarationContext * /*ctx*/) override { }
  virtual void exitGeneric_declaration(Ada95Parser::Generic_declarationContext * /*ctx*/) override { }

  virtual void enterGeneric_subprogram_declaration(Ada95Parser::Generic_subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitGeneric_subprogram_declaration(Ada95Parser::Generic_subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterGeneric_package_declaration(Ada95Parser::Generic_package_declarationContext * /*ctx*/) override { }
  virtual void exitGeneric_package_declaration(Ada95Parser::Generic_package_declarationContext * /*ctx*/) override { }

  virtual void enterGeneric_formal_part(Ada95Parser::Generic_formal_partContext * /*ctx*/) override { }
  virtual void exitGeneric_formal_part(Ada95Parser::Generic_formal_partContext * /*ctx*/) override { }

  virtual void enterGeneric_formal_parameter_declaration(Ada95Parser::Generic_formal_parameter_declarationContext * /*ctx*/) override { }
  virtual void exitGeneric_formal_parameter_declaration(Ada95Parser::Generic_formal_parameter_declarationContext * /*ctx*/) override { }

  virtual void enterGeneric_instantiation(Ada95Parser::Generic_instantiationContext * /*ctx*/) override { }
  virtual void exitGeneric_instantiation(Ada95Parser::Generic_instantiationContext * /*ctx*/) override { }

  virtual void enterGeneric_actual_part(Ada95Parser::Generic_actual_partContext * /*ctx*/) override { }
  virtual void exitGeneric_actual_part(Ada95Parser::Generic_actual_partContext * /*ctx*/) override { }

  virtual void enterGeneric_association(Ada95Parser::Generic_associationContext * /*ctx*/) override { }
  virtual void exitGeneric_association(Ada95Parser::Generic_associationContext * /*ctx*/) override { }

  virtual void enterExplicit_generic_actual_parameter(Ada95Parser::Explicit_generic_actual_parameterContext * /*ctx*/) override { }
  virtual void exitExplicit_generic_actual_parameter(Ada95Parser::Explicit_generic_actual_parameterContext * /*ctx*/) override { }

  virtual void enterFormal_object_declaration(Ada95Parser::Formal_object_declarationContext * /*ctx*/) override { }
  virtual void exitFormal_object_declaration(Ada95Parser::Formal_object_declarationContext * /*ctx*/) override { }

  virtual void enterFormal_type_declaration(Ada95Parser::Formal_type_declarationContext * /*ctx*/) override { }
  virtual void exitFormal_type_declaration(Ada95Parser::Formal_type_declarationContext * /*ctx*/) override { }

  virtual void enterFormal_type_definition(Ada95Parser::Formal_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_type_definition(Ada95Parser::Formal_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_private_type_definition(Ada95Parser::Formal_private_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_private_type_definition(Ada95Parser::Formal_private_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_derived_type_definition(Ada95Parser::Formal_derived_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_derived_type_definition(Ada95Parser::Formal_derived_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_discrete_type_definition(Ada95Parser::Formal_discrete_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_discrete_type_definition(Ada95Parser::Formal_discrete_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_signed_integer_type_definition(Ada95Parser::Formal_signed_integer_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_signed_integer_type_definition(Ada95Parser::Formal_signed_integer_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_modular_type_definition(Ada95Parser::Formal_modular_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_modular_type_definition(Ada95Parser::Formal_modular_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_floating_point_definition(Ada95Parser::Formal_floating_point_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_floating_point_definition(Ada95Parser::Formal_floating_point_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_ordinary_fixed_point_definition(Ada95Parser::Formal_ordinary_fixed_point_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_ordinary_fixed_point_definition(Ada95Parser::Formal_ordinary_fixed_point_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_decimal_fixed_point_definition(Ada95Parser::Formal_decimal_fixed_point_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_decimal_fixed_point_definition(Ada95Parser::Formal_decimal_fixed_point_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_array_type_definition(Ada95Parser::Formal_array_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_array_type_definition(Ada95Parser::Formal_array_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_access_type_definition(Ada95Parser::Formal_access_type_definitionContext * /*ctx*/) override { }
  virtual void exitFormal_access_type_definition(Ada95Parser::Formal_access_type_definitionContext * /*ctx*/) override { }

  virtual void enterFormal_subprogram_declaration(Ada95Parser::Formal_subprogram_declarationContext * /*ctx*/) override { }
  virtual void exitFormal_subprogram_declaration(Ada95Parser::Formal_subprogram_declarationContext * /*ctx*/) override { }

  virtual void enterSubprogram_default(Ada95Parser::Subprogram_defaultContext * /*ctx*/) override { }
  virtual void exitSubprogram_default(Ada95Parser::Subprogram_defaultContext * /*ctx*/) override { }

  virtual void enterDefault_name(Ada95Parser::Default_nameContext * /*ctx*/) override { }
  virtual void exitDefault_name(Ada95Parser::Default_nameContext * /*ctx*/) override { }

  virtual void enterFormal_package_declaration(Ada95Parser::Formal_package_declarationContext * /*ctx*/) override { }
  virtual void exitFormal_package_declaration(Ada95Parser::Formal_package_declarationContext * /*ctx*/) override { }

  virtual void enterFormal_package_actual_part(Ada95Parser::Formal_package_actual_partContext * /*ctx*/) override { }
  virtual void exitFormal_package_actual_part(Ada95Parser::Formal_package_actual_partContext * /*ctx*/) override { }

  virtual void enterAspect_clause(Ada95Parser::Aspect_clauseContext * /*ctx*/) override { }
  virtual void exitAspect_clause(Ada95Parser::Aspect_clauseContext * /*ctx*/) override { }

  virtual void enterLocal_name(Ada95Parser::Local_nameContext * /*ctx*/) override { }
  virtual void exitLocal_name(Ada95Parser::Local_nameContext * /*ctx*/) override { }

  virtual void enterAttribute_definition_clause(Ada95Parser::Attribute_definition_clauseContext * /*ctx*/) override { }
  virtual void exitAttribute_definition_clause(Ada95Parser::Attribute_definition_clauseContext * /*ctx*/) override { }

  virtual void enterEnumeration_representation_clause(Ada95Parser::Enumeration_representation_clauseContext * /*ctx*/) override { }
  virtual void exitEnumeration_representation_clause(Ada95Parser::Enumeration_representation_clauseContext * /*ctx*/) override { }

  virtual void enterEnumeration_aggregate(Ada95Parser::Enumeration_aggregateContext * /*ctx*/) override { }
  virtual void exitEnumeration_aggregate(Ada95Parser::Enumeration_aggregateContext * /*ctx*/) override { }

  virtual void enterRecord_representation_clause(Ada95Parser::Record_representation_clauseContext * /*ctx*/) override { }
  virtual void exitRecord_representation_clause(Ada95Parser::Record_representation_clauseContext * /*ctx*/) override { }

  virtual void enterComponent_clause(Ada95Parser::Component_clauseContext * /*ctx*/) override { }
  virtual void exitComponent_clause(Ada95Parser::Component_clauseContext * /*ctx*/) override { }

  virtual void enterPosition(Ada95Parser::PositionContext * /*ctx*/) override { }
  virtual void exitPosition(Ada95Parser::PositionContext * /*ctx*/) override { }

  virtual void enterFirst_bit(Ada95Parser::First_bitContext * /*ctx*/) override { }
  virtual void exitFirst_bit(Ada95Parser::First_bitContext * /*ctx*/) override { }

  virtual void enterLast_bit(Ada95Parser::Last_bitContext * /*ctx*/) override { }
  virtual void exitLast_bit(Ada95Parser::Last_bitContext * /*ctx*/) override { }

  virtual void enterCode_statement(Ada95Parser::Code_statementContext * /*ctx*/) override { }
  virtual void exitCode_statement(Ada95Parser::Code_statementContext * /*ctx*/) override { }

  virtual void enterRestriction(Ada95Parser::RestrictionContext * /*ctx*/) override { }
  virtual void exitRestriction(Ada95Parser::RestrictionContext * /*ctx*/) override { }

  virtual void enterAt_clause(Ada95Parser::At_clauseContext * /*ctx*/) override { }
  virtual void exitAt_clause(Ada95Parser::At_clauseContext * /*ctx*/) override { }

  virtual void enterDelta_constraint(Ada95Parser::Delta_constraintContext * /*ctx*/) override { }
  virtual void exitDelta_constraint(Ada95Parser::Delta_constraintContext * /*ctx*/) override { }

  virtual void enterMod_clause(Ada95Parser::Mod_clauseContext * /*ctx*/) override { }
  virtual void exitMod_clause(Ada95Parser::Mod_clauseContext * /*ctx*/) override { }

  virtual void enterBoolean_expression(Ada95Parser::Boolean_expressionContext * /*ctx*/) override { }
  virtual void exitBoolean_expression(Ada95Parser::Boolean_expressionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

