#include "Real_CPU.h"
#include "Def_types.h"

Sfml_CPU::Sfml_CPU(): Audio(), Video(), Memory(), Keyboard() {
	//// write program in memory, initialize MEM_END, init subclasses
	initStateTable();
}

static void(Sfml_CPU::*stateTable[35])(two_byte cmd);

void Sfml_CPU::initStateTable() {
	stateTable[S_00EE] = &Sfml_CPU::RET;
	(this->*stateTable[S_00EE])(0x0000);
	// stateTable[] = 
}

void Sfml_CPU::do_cycle() {
	while (/*Memory.end(PC)*/true) {
		two_byte current_signal = decode(fetch());
		(this->*stateTable[current_signal])(current_signal); // check != NULL
	}
}

two_byte Sfml_CPU::fetch() {
	return Memory.getFromStack(SP);
}

two_byte Sfml_CPU::decode(two_byte instruction) {
	byte id_pos = 3;
	// const char bits_count = 4; 
	two_byte first_command_id = instruction && masks[id_pos];
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
		id_pos = 0;
		return instruction && masks[id_pos] + 10;
	}
	if (0x8000 < first_command_id && first_command_id < 0xE000)
		return (first_command_id >> 12) + 10;
	if (first_command_id == 0xE000) {
		if (instruction && 0x00FF == 0xE09E) return 24;
		if (instruction && 0x00FF == 0xE0A1) return 25;
	}
	if (first_command_id == 0xF000) {
		two_byte arr[9] = {0x0007, 0x000A, 0x0015, 0x0018, 0x001E, 0x0029, 0x0033, 0x0055, 0x0065};
		id_pos = 2;
		for (byte i = 0; i < 9; i++) {
			if (instruction && 0x00FF == arr[i])
				return i + 26;
		}
	}
	return 35;
}
