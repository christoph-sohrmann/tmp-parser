/*
 * state.hpp
 *
 *  Created on: 09.11.2015
 *      Author: sohrmann
 */

#ifndef STATE_HPP_
#define STATE_HPP_

namespace parser {

/*
 * Holding the current state (i.e. position) of the parser.
 */
struct State {
	std::string::iterator iterator;
	int position;
	int line;
	std::vector<std::string> parameters;

	/// c'tor
	State(std::string::iterator iterator) :
		iterator(iterator),
		position(1),
		line(1)
	{}

	/// move iterator forward, check new line
	void advance() {
		char c = *iterator;
		std::advance(iterator, 1);
		if (c != '\n')
			position++;
		else {
			line++;
			position = 1;
		}
	}

	/// get current position in readable form
	std::string as_string() {
		return "line " + std::to_string(line) + " at position " + std::to_string(position);
	}
};

}  // namespace state

#endif /* STATE_HPP_ */
