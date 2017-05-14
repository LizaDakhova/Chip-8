#ifndef BASE_CPU_H
#define BASE_CPU_H

#include <fstream>
#include <assert.h>
#include <string>

#include "Base_Audio.h"
#include "Base_Video.h"
#include "Base_Memory.h"
#include "Base_Keyboard.h"
#include "Def_types.h"

//abstract Base class
class Base_CPU {
public:
	Base_CPU(two_byte size) : PROG_size(size) {
		assert(PROG_size <= maxProgSize);
	}
	virtual ~Base_CPU() {}
	two_byte filesize(const std::string& inputfile);

protected:
	BaseAudio* Audio;
	BaseVideo* Video;
	BaseMemory* Memory;
	BaseKeyboard* Keyboard;
	const two_byte maxProgSize = 0x0D00;
	const two_byte PROG_size;
};

#endif