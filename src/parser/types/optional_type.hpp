/*
 * optional_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef OPTIONAL_TYPE_HPP_
#define OPTIONAL_TYPE_HPP_

namespace parser {

/// zero or one of T
template <typename T>
struct optional_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		T::match(parser);
		return true;
	}
};

/// convenience operator ~
template <typename T>
optional_type<T> operator~(T) {
	return optional_type<T>();
}

}  // namespace parser

#endif /* OPTIONAL_TYPE_HPP_ */
