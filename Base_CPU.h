#ifndef __BASE_AUDIO_H
#define __BASE_AUDIO_H
#include "Base_Audio.h"
#ifndef __BASE_VIDEO_H
#define __BASE_VIDEO_H
#include "Base_Video.h"
#ifndef __BASE_MEMORY_H
#define __BASE_MEMORY_H
#include "Base_Memory.h"
#ifndef __BASE_KEYBOARD_H
#define __BASE_KEYBOARD_H
#include "Base_Keyboard.h"
//virtual Base class
class Base_CPU {
protected:
	BaseAudio &Audio;
	BaseVideo &Video;
	BaseMemory &Memory;
	BaseKeyboard &Keyboard;

	unsigned char numReg;
	unsigned char numTimers;
	unsigned int *GPReg;
	unsigned int PC;
	unsigned int SP;

public:
	virtual ~Base_CPU();

	void do_cycle() = 0;
	virtual void fetch() = 0;
	virtual void decode() = 0;
	virtual void executive() = 0;
};
#endif
#endif
#endif
#endif