#ifndef BASE_CPU_H
#define BASE_CPU_H

#include <fstream>
#include <string>

#include "Base_Audio.h"
#include "Base_Video.h"
#include "Base_Memory.h"
#include "Base_Keyboard.h"
#include "Def_types.h"

//abstract Base class
class Base_CPU {
public:
	virtual ~Base_CPU() {}
	two_byte filesize(const std::string& inputfile);

//protected:
//	BaseAudio Audio;
//	BaseVideo Video;
//	BaseMemory Memory;
//	BaseKeyboard Keyboard;
};

#endif