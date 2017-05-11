#include <fstream>

#include "Real_CPU.h"
#include "Def_types.h"

static void(Sfml_CPU::*stateTable[35])(two_byte cmd);

void Sfml_CPU::initStateTable() {
	std::cout << "init state table\n";
	// stateTable[S_0NNN] =
	// stateTable[S_00E0] = 
	stateTable[S_00EE] = &Sfml_CPU::RET;
	stateTable[S_1NNN] = &Sfml_CPU::JP_addr;
	stateTable[S_2NNN] = &Sfml_CPU::CALL_addr;
	stateTable[S_3Xkk] = &Sfml_CPU::SKIP_E;
	stateTable[S_4Xkk] = &Sfml_CPU::SKIP_NE;
	stateTable[S_5XY0] = &Sfml_CPU::SKIP_REG_E;
	// S_6Xkk, S_7Xkk, S_8XY0, S_8XY1, S_8XY2, S_8XY3
	// S_8XY4, S_8XY5, S_8XY6, S_8XY7, S_8XYE
	stateTable[S_9XY0] = &Sfml_CPU::SKIP_REG_NE;
}

void Sfml_CPU::do_cycle() {
	while (Memory.end(PC)) {
		two_byte current_signal = decode(fetch());
		(this->*stateTable[current_signal])(current_signal); // check != NULL
	}
}

two_byte Sfml_CPU::fetch() {
	return Memory.getFromStack(SP);
}

two_byte Sfml_CPU::decode(two_byte instruction) {
	// const char bits_count = 4; 
	two_byte first_command_id = instruction && 0xF000;
	if (first_command_id == 0x0000) {
		if (instruction == 0x0E0)
			return 0;
		if (instruction == 0x0EE)
			return 1;
		return 2;
	}
	if (0x0000 < first_command_id && first_command_id < 0x8000)
		return (first_command_id >> 12) + 2;
	if (first_command_id == 0x8000) {
		return instruction && 0x000F + 10;
	}
	if (0x8000 < first_command_id && first_command_id < 0xE000)
		return (first_command_id >> 12) + 10;
	if (first_command_id == 0xE000) {
		if (instruction && 0x00FF == 0xE09E) return 24;
		if (instruction && 0x00FF == 0xE0A1) return 25;
	}
	if (first_command_id == 0xF000) {
		two_byte arr[9] = {0x0007, 0x000A, 0x0015, 0x0018, 0x001E, 0x0029, 0x0033, 0x0055, 0x0065};
		for (byte i = 0; i < 9; i++) {
			if (instruction && 0x00FF == arr[i])
				return i + 26;
		}
	}
	return 35;
}
