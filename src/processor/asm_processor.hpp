/*
 * asm_processor.hpp
 *
 *  Created on: 09.11.2015
 *      Author: sohrmann
 */

#ifndef ASM_PROCESSOR_HPP_
#define ASM_PROCESSOR_HPP_

/*
 * Specializations of the instruction function of the Processor
 * in order to match the rules defined by the asm grammar.
 *
 * Basic operations implemented within the respective function.
 *
 */

template <>
void Processor::instruction<decltype(asm_grammar::rule_mov)>(std::vector<std::string>& params, int, int) {
	reg_[params[0]] = get_value(params[1]);
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_push)>(std::vector<std::string>& params, int, int) {
	stack_.push(get_value(params[0]));
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_pop)>(std::vector<std::string>& params, int, int) {
	reg_[params[0]] = stack_.top();
	stack_.pop();
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_add)>(std::vector<std::string>& params, int, int) {
	reg_[params[0]] += get_value(params[1]);
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_sub)>(std::vector<std::string>& params, int, int) {
	reg_[params[0]] -= get_value(params[1]);
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_div)>(std::vector<std::string>& params, int line , int position) {
	double denom = get_value(params[1]);
	if (denom == 0.) {
		std::cerr << "[ERROR] Division by zero encountered at line " << line << " at position " << position << std::endl;
		exit(-1);
	}
	reg_[params[0]] /= get_value(params[1]);
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_mul)>(std::vector<std::string>& params, int, int) {
	reg_[params[0]] *= get_value(params[1]);
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_print_num)>(std::vector<std::string>& params, int, int) {
	std::cout << get_value(params[0]) << std::endl;
}

template <>
void Processor::instruction<decltype(asm_grammar::rule_print_string)>(std::vector<std::string>& params, int, int) {
	std::cout << params[0] << std::endl;
}

#endif /* ASM_PROCESSOR_HPP_ */
