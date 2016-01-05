/*
 * processor.hpp
 *
 *  Created on: 09.11.2015
 *      Author: sohrmann
 */

#ifndef PROCESSOR_HPP_
#define PROCESSOR_HPP_

#include <map>
#include <sstream>

/*
 * Processor class holding registers and stack.
 * Function "instruction" will be called by the parser for
 * each rule which is defined as an instruction_type<T>.
 */

class Processor final {
protected:
	std::map<std::string,double> reg_;
	std::stack<double> stack_;
public:
	explicit Processor();
	Processor(const Processor&) = delete;
    Processor& operator=(const Processor&) = delete;

	bool is_number(std::string s);
	double get_value(std::string param);
	template <typename T>
	void instruction(std::vector<std::string>& params, int line, int position);
};

///////////////////////////////////////////////////////////

Processor::Processor() {
	reg_["ax"] = 0;
	reg_["bx"] = 0;
	reg_["cx"] = 0;
}

bool Processor::is_number(std::string s) {
	 std::stringstream ss;
	 ss << s;
	 double num;
	 return !(ss >> num).fail();
}

double Processor::get_value(std::string param) {
	if (is_number(param))
		return std::stod(param);
	else
		return reg_[param];
}

#endif /* PROCESSOR_HPP_ */
