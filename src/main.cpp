//============================================================================
// Name        : main.cpp
// Author      : Christoph Sohrmann
// Version     :
// Copyright   : N/A
// Description : Simple asm interpreter
//============================================================================

#include <iostream>
#include "helper/file_reader.hpp"
#include "parser/parser.hpp"
#include "grammar/asm_grammar.hpp"
#include "processor/processor.hpp"
#include "processor/asm_processor.hpp"

int main(int argc, char *argv[]) {
	/// check arguments
	if (argc<2) {
		std::cerr << "Please specify an input file!" << std::endl;
		return -1;
	}

	/// try reading file
	std::string file_contents = "";
	if (!FileReader::AsString(argv[1], file_contents)) {
		std::cerr << "[ERROR] Cannot read input file: " << argv[1] << std::endl;
		return -1;
	}

	/// try parsing file contents
	parser::Parser<Processor> parser(file_contents);
	if (!parser.parse(asm_grammar::grammar)) {
		std::cerr << "[ERROR] Syntax error in input file at " << parser.get_error_state().as_string() << std::endl;
		return -1;
	}

	return 0;
}
