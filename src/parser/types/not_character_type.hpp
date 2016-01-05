/*
 * not_character_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef NOT_CHARACTER_TYPE_HPP_
#define NOT_CHARACTER_TYPE_HPP_

namespace parser {

/// anything but the specified character
template <char C>
struct not_character_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return parser.consume_unless_character(C);
	}
};

/// convenience operator !
template <char C>
not_character_type<C> operator!(character_type<C>) {
	return not_character_type<C>();
}

}  // namespace parser

#endif /* NOT_CHARACTER_TYPE_HPP_ */
