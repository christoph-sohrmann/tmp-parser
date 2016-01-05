/*
 * character_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef CHARACTER_TYPE_HPP_
#define CHARACTER_TYPE_HPP_

namespace parser {

/// character needs to match
template <char C>
struct character_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return parser.consume_character(C);
	}
};

}  // namespace parser

#endif /* CHARACTER_TYPE_HPP_ */
