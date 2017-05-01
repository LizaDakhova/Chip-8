class SfmlAudio {
};
class SfmlVideo {
};
class SfmlMemory {
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
	char Regs[16];
	unsigned char numReg;
	unsigned char numTimers;
	unsigned short PC;
	unsigned short MEM_END;
	unsigned short SP;
	enum states { init, some_state, final};
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

	struct token {
		token(int _c, int _a, char _a1 = 0, char _a2 = 0, char _a3 = 0) :
			command(_c), argscount(_a), arg1(_a1), arg2(_a2), arg3(_a3) {}
		int command;
		int argscount;
		char arg1;
		char arg2;
		char arg3;
	};

	short masks[4]{
		0xC0,
		0x30,
		0x0C,
		0x03
	};

	void(*stateTable[35])(token);
	void initStateTable();
	void do_cycle();
	char fetch();
	token decode(short instruction);
	void (*execute)(token command);
};
