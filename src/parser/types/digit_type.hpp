/*
 * digit_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef DIGIT_TYPE_HPP_
#define DIGIT_TYPE_HPP_

namespace parser {

/// next character should be a digit
struct digit_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return parser.consume_digit();
	}
};

}  // namespace parser

#endif /* DIGIT_TYPE_HPP_ */
