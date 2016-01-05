/*
 * instruction_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef INSTRUCTION_TYPE_HPP_
#define INSTRUCTION_TYPE_HPP_

namespace parser {

/// instruction forwards parameters to the processor
template <typename T>
struct instruction_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return parser.template instruction<T>();
	}
};

/// convenience function instruction()
template <typename T>
instruction_type<T> instruction(T&) {
	// note: reference forces use of lvalue
	return instruction_type<T>();
}

}  // namespace parser

#endif /* INSTRUCTION_TYPE_HPP_ */
