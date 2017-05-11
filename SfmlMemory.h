#ifndef SFML_MEM_H
#define SFML_MEM_H

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>

#include "Def_types.h"

class SfmlMemory {
public:
	SfmlMemory();
	SfmlMemory(two_byte size, const std::string& inputfile);
	~SfmlMemory();

	two_byte getFromStack(two_byte pos);
	void putInStack(two_byte addr, two_byte pos);
	bool end(two_byte pos);
	// byte getNextCommand(two_byte pos);
private:
	const two_byte memSize = 0x1000;
	const two_byte maxProgSize = 0x0D00;
	const two_byte start_PROG = 0x0200;
	const two_byte SCREEN_size = 0x0100;
	const two_byte PROG_size;
	const two_byte start_SCREEN;
	const two_byte end_SCREEN;
	byte* mem;
};

#endif