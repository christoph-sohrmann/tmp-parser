/*
 * parameter_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef PARAMETER_TYPE_HPP_
#define PARAMETER_TYPE_HPP_

namespace parser {

/// stack will be collapsed and appended to parameter list
template <typename T>
struct parameter_type {
	template <typename ParserType>
	static bool match(ParserType& parser) {
		return parser.template parameter<T>();
	}
};

/// convenience function parameter()
template <typename T>
parameter_type<T> parameter(T) {
	return parameter_type<T>();
}

}  // namespace parser

#endif /* PARAMETER_TYPE_HPP_ */
