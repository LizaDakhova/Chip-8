#ifndef SFML_MEM_H
#define SFML_MEM_H

#include <assert.h>

#include "Def_types.h"

class SfmlMemory {
public:
	SfmlMemory() {
		mem = new byte[memSize];
		// write from file
		// MEM_END = ...
	}
	byte getFromStack(two_byte pos) {
		assert(pos < memSize && pos >= MEM_END);
		return mem[memSize - pos];
	}
	bool end(two_byte pos) {
		return pos >= MEM_END;
	}
	// byte getNextCommand(two_byte pos);
private:
	const int memSize = 4096;
	const two_byte start_prog = 0x2000;
	two_byte MEM_END;
	byte* mem;
};

#endif