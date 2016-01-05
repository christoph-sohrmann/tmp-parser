/*
 * asm_grammar.hpp
 *
 *  Created on: 09.11.2015
 *      Author: sohrmann
 */

#ifndef ASM_GRAMMAR_HPP_
#define ASM_GRAMMAR_HPP_

#include "../parser/parser.hpp"

/*
 * Given grammar defined in this namespace
 * using the convenience operators.
 */
namespace asm_grammar {

/// let's drop the parser namespace
template <char ...C>
using text = parser::text_type<C...>;
template <char C>
using character = parser::character_type<C>;
using parser::digit;
using parser::WS;
using parser::DQ;
using parser::DOT;
using parser::COMMA;
using parser::NL;

/// define keywords
auto MOV = text<'m','o','v'>();
auto PUSH = text<'p','u','s','h'>();
auto POP = text<'p','o','p'>();
auto ADD = text<'a','d','d'>();
auto SUB = text<'s','u','b'>();
auto DIV = text<'d','i','v'>();
auto MUL = text<'m','u','l'>();
auto PRINT = text<'p','r','i','n','t'>();
auto AX = text<'a','x'>();
auto BX = text<'b','x'>();
auto CX = text<'c','x'>();

/// registers
auto reg = AX | BX | CX;

/// how a string looks like (inner part defined as a parameter)
auto string_literal = DQ & parameter(*(!DQ)) & DQ;

/// how a number should look like
auto sign = character<'+'>() | character<'-'>();
auto exponent = (character<'e'>() | character<'E'>()) & ~sign & +digit;
auto simple_number = (DOT & +digit) | (+digit & ~(DOT & *digit));
auto numerical_value = ~sign & simple_number & ~exponent;

/// src should not have string_literal included (!)
auto src = reg | numerical_value;
auto dest = reg;

/// define the rules
auto rule_mov = MOV & +WS & parameter( dest ) & *WS & COMMA & *WS & parameter( src );
auto rule_push = PUSH & +WS & parameter( src );
auto rule_pop = POP & +WS & parameter( dest );
auto rule_add = ADD & +WS & parameter( dest ) & *WS & COMMA & *WS & parameter( src );
auto rule_sub = SUB & +WS & parameter( dest ) & *WS & COMMA & *WS & parameter( src );
auto rule_div = DIV & +WS & parameter( dest ) & *WS & COMMA & *WS & parameter( src );
auto rule_mul = MUL & +WS & parameter( dest ) & *WS & COMMA & *WS & parameter( src );
auto rule_print_num = PRINT & +WS & parameter( src );
auto rule_print_string = PRINT & +WS & string_literal;

/// compose the rules into the final grammar
auto grammar =
		*(
				instruction( rule_mov ) |
				instruction( rule_push ) |
				instruction( rule_pop ) |
				instruction( rule_add ) |
				instruction( rule_sub ) |
				instruction( rule_div ) |
				instruction( rule_mul ) |
				instruction( rule_print_num ) |
				instruction( rule_print_string ) |
				NL
		);

} // namespace asm_grammar

#endif /* ASM_GRAMMAR_HPP_ */
