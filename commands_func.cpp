#include "Real_CPU.h"
#include "Def_types.h"

void Sfml_CPU::RET(two_byte cmd) {
	PC = Memory.getFromStack(SP);
	SP--;
}
void Sfml_CPU::JP_addr(two_byte cmd) {
	PC = cmd && 0x0FFF;
}