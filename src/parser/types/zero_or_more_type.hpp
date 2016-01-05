/*
 * zero_or_more_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef ZERO_OR_MORE_TYPE_HPP_
#define ZERO_OR_MORE_TYPE_HPP_

namespace parser {

/// match any number of T
template <typename T>
struct zero_or_more_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		while (T::match(parser));
		return true;
	}
};

/// convenience operator *
template <typename T>
zero_or_more_type<T> operator*(T) {
	return zero_or_more_type<T>();
}

}  // namespace parser

#endif /* ZERO_OR_MORE_TYPE_HPP_ */
