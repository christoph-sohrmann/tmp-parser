/*
 * one_or_more_type.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef ONE_OR_MORE_TYPE_HPP_
#define ONE_OR_MORE_TYPE_HPP_

#include "and_type.hpp"
#include "zero_or_more_type.hpp"

namespace parser {

/// efficiently combined ...
template <typename T>
using one_or_more_type = and_type<T, zero_or_more_type<T>>;

/// convenience operator +
template <typename T>
one_or_more_type<T> operator+(T) {
	return one_or_more_type<T>();
}

}  // namespace parser

#endif /* ONE_OR_MORE_TYPE_HPP_ */
