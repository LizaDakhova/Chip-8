#include "SfmlMemory.h"
#include "Def_types.h"

#include <iostream>

class SfmlAudio {
};
class SfmlVideo {
};
class SfmlKeyboard {
};

class Sfml_CPU {
public:
	Sfml_CPU();
	~Sfml_CPU() {}

protected:
	SfmlAudio Audio;
	SfmlVideo Video;
	SfmlMemory Memory;
	SfmlKeyboard Keyboard;
private:
	byte Regs[16];
	byte numReg;
	byte numTimers;
	two_byte PC;
	two_byte SP;
	enum signals { 
		S_0NNN, S_00E0, S_00EE, S_1NNN, S_2NNN, 
		S_3Xkk, S_4Xkk, S_5Xkk, S_6Xkk, S_7Xkk, 
		S_8XY0, S_8XY1, S_8XY2, S_8XY3, S_8XY4,
		S_8XY5, S_8XY6, S_8XY7, S_8XYE, 
		S_9XY0,
		S_ANNN, S_BNNN, S_CXkk, S_DXYN,
		S_EX9E, S_EXA1,
		S_FX07, S_FX0A, S_FX15, S_FX18, S_FX1E, S_FX29, S_FX33, S_FX55, S_Fx65
	};

	//struct token {
	//	token(int _c, int _a, byte _a1 = 0, byte _a2 = 0, byte _a3 = 0) :
	//		command(_c), argscount(_a), arg1(_a1), arg2(_a2), arg3(_a3) {}
	//	int command;
	//	int argscount;
	//	byte arg1;
	//	byte arg2;
	//	byte arg3;
	//};

	two_byte masks[4]{
		0x000F,
		0x00F0,
		0x0F00,
		0xF000
	};

	void initStateTable();
	void do_cycle();
	two_byte fetch();
	two_byte decode(two_byte instruction);
	void RET(two_byte cmd);
	void JP_addr(two_byte cmd);
	// void (*execute)(token command);
};
