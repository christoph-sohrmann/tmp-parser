/*
 * and_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef AND_TYPE_HPP_
#define AND_TYPE_HPP_

namespace parser {

/// both T1 and T2 need to match consecutively
template <typename T1, typename T2>
struct and_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		State old_state = parser.get_state();
		if (T1::match(parser) && T2::match(parser))
			return true;
		else {
			parser.error();
			parser.set_state(old_state);
			return false;
		}
	}
};

/// convenience operator &
template <typename T1, typename T2>
and_type<T1,T2> operator&(T1, T2) {
	return and_type<T1,T2>();
};

}  // namespace parser

#endif /* AND_TYPE_HPP_ */
