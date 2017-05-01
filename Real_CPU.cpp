#include "Real_CPU.h"

Sfml_CPU::Sfml_CPU(): Audio(), Video(), Memory(), Keyboard() {
	//// write program in memory, initialize MEM_END, init subclasses
	initStateTable();
}

void Sfml_CPU::initStateTable() {
	// stateTable[] = 
}

void Sfml_CPU::do_cycle() {
	while (PC != MEM_END) {
		token current_signal = decode(fetch());
		execute = stateTable[current_signal.command];
		execute(current_signal); // check != NULL
	}
}

char Sfml_CPU::fetch() {
	return 0;
}

Sfml_CPU::token Sfml_CPU::decode(short instruction) {
	if (instruction && masks[0] == 0x8000) {
		return { 10 + instruction && masks[3], 2, instruction && masks[1], instruction && masks[2] };
	}
	return { 0, 0 };
}
