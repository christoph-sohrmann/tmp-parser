/*
 * parser.hpp
 *
 *  Created on: 08.11.2015
 *      Author: sohrmann
 */

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <stack>
#include <vector>

#include "state.hpp"
#include "types/and_type.hpp"
#include "types/character_type.hpp"
#include "types/digit_type.hpp"
#include "types/instruction_type.hpp"
#include "types/not_character_type.hpp"
#include "types/one_or_more_type.hpp"
#include "types/optional_type.hpp"
#include "types/or_type.hpp"
#include "types/parameter_type.hpp"
#include "types/text_type.hpp"
#include "types/zero_or_more_type.hpp"

namespace parser {

/// create instances to work with convenience operators
digit_type digit;
character_type<'.'> DOT;
character_type<','> COMMA;
character_type<' '> WS;
character_type<'"'> DQ;
character_type<'\n'> NL;

/*
 * The parser class holding and lexing the input string.
 * Instructions will be forwared to a user-defined processor class
 * of type ProcessorType.
 *
 */
template <typename ProcessorType>
class Parser {
protected:
	std::string data_;
	State state_;
	State error_state_;
	std::stack<std::string> stack_;
	ProcessorType processor_;
public:

	/// c'tor
	Parser(std::string input_data) :
		data_(input_data),
		state_(data_.begin()),
		error_state_(data_.begin())
	{}

	/// return state
	State& get_state() {
		return state_;
	}

	/// set state
	void set_state(State value) {
		state_ = value;
	}

	/// return error state
	State& get_error_state() {
		return error_state_;
	}

	/// copy state to error state
	void error() {
		error_state_ = state_;
	}

	/// check if we have reached end of input
	bool eof() {
		return state_.iterator == data_.end();
	}

	/// run the parser and return success
	template <typename T>
	bool parse(T& grammar) {
		return grammar.match(*this) && eof();
	}

	/// move on if we have a digit
	bool consume_digit() {
		if (!eof() && std::isdigit(*(state_.iterator))) {
			stack_.push(std::string(1, *(state_.iterator)));
			state_.advance();
			return true;
		} else
			return false;
	}

	/// move on if we find character c
	bool consume_character(const char c) {
		if (!eof() && *(state_.iterator) == c) {
			stack_.push(std::string(1, *(state_.iterator)));
			state_.advance();
			return true;
		} else
			return false;
	}

	/// move on unless we find character c
	bool consume_unless_character(const char c) {
		if (!eof() && *(state_.iterator) != c) {
			stack_.push(std::string(1, *(state_.iterator)));
			state_.advance();
			return true;
		} else
			return false;
	}

	/// reduce stack by given amount n
	void reduce_stack(std::size_t n) {
		if (n <= 0) return;
		std::string reduced_value = "";
		for (std::size_t i = 0; i < n && !stack_.empty(); ++i) {
			reduced_value = stack_.top() + reduced_value;
			stack_.pop();
		}
		stack_.push(reduced_value);
		state_.parameters.push_back(reduced_value);
	}

	/// called by parameter_type<T>
	template <typename T>
	bool parameter() {
		std::size_t old_stack_size = stack_.size();
		if (T::match(*this)) {
			reduce_stack(stack_.size() - old_stack_size);
			return true;
		} else
			return false;
	}

	/// called by instruction_type<T>
	template <typename T>
	bool instruction() {
		if (T::match(*this)) {
			// caution: user will only catch instruction_type<T>
			processor_.template instruction<T>(state_.parameters, state_.line, state_.position);
			state_.parameters.clear();
			return true;
		} else
			return false;
	}
};

}  // namespace parser

#endif /* PARSER_HPP_ */
