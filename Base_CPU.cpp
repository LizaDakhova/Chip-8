#include "Base_CPU.h"

#include <string>
#include <iostream>

two_byte Base_CPU::filesize(const std::string& inputfile) {
	std::ifstream input(inputfile.c_str(), std::ios_base::in);
	input.seekg(0, std::ios::end);
	two_byte result = static_cast<two_byte>(input.tellg());  //catch "failure"
	input.close();
	return result;
}