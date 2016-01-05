/*
 * text_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef TEXT_TYPE_HPP_
#define TEXT_TYPE_HPP_

namespace parser {

/// generic version
template <char ...C>
struct text_type;

/// specialization required for iteratively creating the tree
template <char C1,char ...C2>
struct text_type<C1,C2...> {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return and_type<character_type<C1>,text_type<C2...>>::match(parser);
	}
};

/// specialization required to stop the iteration
template <> struct text_type<> {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return true;
	}
};

}  // namespace parser

#endif /* TEXT_TYPE_HPP_ */
