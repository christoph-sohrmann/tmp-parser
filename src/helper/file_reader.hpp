/*
 * file_reader.hpp
 *
 *  Created on: 02.11.2015
 *      Author: sohrmann
 */

#ifndef FILE_READER_HPP_
#define FILE_READER_HPP_

#include <fstream>

/*
 * Helper function to read a file into a std::string
 */
struct FileReader {
	static bool AsString(std::string filename, std::string& file_contents) {
		std::ifstream f(filename.c_str());
		if (!f.good()) {
			f.close();
			return false;
		}
		file_contents =
				std::string((std::istreambuf_iterator<char>(f)),
						std::istreambuf_iterator<char>());
		return true;
	}
};

#endif /* FILE_READER_HPP_ */
