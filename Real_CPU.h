#ifndef SFML_CPU_H
#define SFML_CPU_H

#include "SfmlMemory.h"
#include "SfmlVideo.h"
#include "SfmlKeyboard.h"
#include "Def_types.h"
#include "Base_CPU.h"

#include <fstream>
#include <iostream>
#include <string>

class Sfml_CPU : public Base_CPU {
public:
	Sfml_CPU(const std::string& inputfile) : Base_CPU(filesize(inputfile)),
		PC(start_PROG), SP(0),
		start_SCREEN(start_PROG + PROG_size), end_SCREEN(start_PROG + PROG_size + SCREEN_size) {

		// init Regs, numReg, numTimers, I
		// init subclasses
		Memory = new SfmlMemory(PROG_size, inputfile);
		Audio = new SfmlAudio();
		Video = new SfmlVideo(10, inputfile, Memory);
		Keyboard = new SfmlKeyboard();

		initStateTable();
	}
	~Sfml_CPU() {
		delete Audio;
		delete Video;
		delete Memory;
		delete Keyboard;
	}

protected:
	SfmlAudio* Audio;
	SfmlVideo* Video;
	SfmlMemory* Memory;
	SfmlKeyboard* Keyboard;
private:
	byte Regs[16];
	byte numReg;
	byte numTimers;
	two_byte PC;
	two_byte SP;
	two_byte I;

	const two_byte start_PROG = 0x0200;
	const two_byte SCREEN_size = 0x0100;
	const two_byte start_SCREEN;
	const two_byte end_SCREEN;

	enum signals { 
		S_0NNN, S_00E0, S_00EE, S_1NNN, S_2NNN, 
		S_3Xkk, S_4Xkk, S_5XY0, S_6Xkk, S_7Xkk,
		S_8XY0, S_8XY1, S_8XY2, S_8XY3, S_8XY4,
		S_8XY5, S_8XY6, S_8XY7, S_8XYE, 
		S_9XY0,
		S_ANNN, S_BNNN, S_CXkk, S_DXYN,
		S_EX9E, S_EXA1,
		S_FX07, S_FX0A, S_FX15, S_FX18, S_FX1E, S_FX29, S_FX33, S_FX55, S_Fx65
	};

	void initStateTable();
	two_byte getFromStack(two_byte pos);
	void putInStack(two_byte addr, two_byte pos);
	void do_cycle();
	two_byte fetch();
	two_byte decode(two_byte instruction);

	void RET(two_byte cmd);
	void JP_addr(two_byte cmd);
	void CALL_addr(two_byte cmd);
	void SKIP_E(two_byte cmd);
	void SKIP_NE(two_byte cmd);
	void SKIP_REG_E(two_byte cmd);
	void SKIP_REG_NE(two_byte cmd);
	void SET_I_ADDR(two_byte cmd);
	void JP_ADDR_V0(two_byte cmd);
	void SET_VX_RND(two_byte cmd);
	void DRW_NIBBLE(two_byte cmd);
};

#endif