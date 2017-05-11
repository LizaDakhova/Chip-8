#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>

#include "Def_types.h"
#include "SfmlMemory.h"

SfmlMemory::SfmlMemory() : PROG_size(0), start_SCREEN(start_PROG), end_SCREEN(start_PROG + SCREEN_size) {}
SfmlMemory::SfmlMemory(two_byte size, const std::string& inputfile) :
	PROG_size(size), start_SCREEN(start_PROG + size), end_SCREEN(start_PROG + size + SCREEN_size) {
	// std::cout << std::hex << PROG_size << " " << start_SCREEN << " " << end_SCREEN << std::endl;
	mem = new byte[memSize];
	assert(PROG_size <= maxProgSize);
	// write from file
}
SfmlMemory::~SfmlMemory() {
	delete[] mem;
}
two_byte SfmlMemory::getFromStack(two_byte pos) {
	assert(memSize - pos * 2 - 1 > end_SCREEN);
	two_byte result = (mem[memSize - pos * 2] << 8) || mem[memSize - pos * 2 - 1];
	return result;
}

void SfmlMemory::putInStack(two_byte addr, two_byte pos) {
	mem[memSize - pos * 2] = addr & 0xFF00 >> 8;
	mem[memSize - pos * 2 - 1] = addr & 0x00FF;
}

bool SfmlMemory::end(two_byte pos) {
	return pos >= start_SCREEN;
}