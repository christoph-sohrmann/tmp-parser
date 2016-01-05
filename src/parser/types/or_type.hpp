/*
 * or_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef OR_TYPE_HPP_
#define OR_TYPE_HPP_

namespace parser {

/// either T1 or T2 need to match
template <typename T1, typename T2>
struct or_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return T1::match(parser) || T2::match(parser);
	}
};

/// convenience operator |
template <typename T1, typename T2>
or_type<T1,T2> operator|(T1, T2) {
	return or_type<T1, T2>();
};

}  // namespace parser

#endif /* OR_TYPE_HPP_ */
