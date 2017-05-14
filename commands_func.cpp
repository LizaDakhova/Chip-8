#include <cstdlib>
#include <ctime>

#include "Real_CPU.h"
#include "Def_types.h"

void Sfml_CPU::RET(two_byte cmd) {
	PC = getFromStack(SP);
	SP--;
}
void Sfml_CPU::JP_addr(two_byte cmd) {
	PC = cmd && 0x0FFF;
}

void Sfml_CPU::CALL_addr(two_byte cmd) {
	SP++;
	putInStack(cmd, SP);
	PC = cmd && 0x0FFF;
}

void Sfml_CPU::SKIP_E(two_byte cmd) {
	if (Regs[(cmd & 0x0F00) >> 8] == (cmd & 0x00FF))
		PC += 2;
}

void Sfml_CPU::SKIP_NE(two_byte cmd) {
	if (Regs[(cmd & 0x0F00) >> 8] != (cmd & 0x00FF))
		PC += 2;
}

void Sfml_CPU::SKIP_REG_E(two_byte cmd) {
	assert((cmd & 0xF00F) == 0x5000);
	if (Regs[(cmd & 0x0F00) >> 8] == Regs[(cmd & 0x00F0) >> 4])
		PC += 2;
}

void Sfml_CPU::SKIP_REG_NE(two_byte cmd) {
	assert((cmd & 0xF00F) == 0x9000);
	if (Regs[(cmd & 0x0F00) >> 8] != Regs[(cmd & 0x00F0) >> 4])
		PC += 2;
}

void Sfml_CPU::SET_I_ADDR(two_byte cmd) {
	I = cmd & 0x0FFF;
}

void Sfml_CPU::JP_ADDR_V0(two_byte cmd) {
	PC = (cmd & 0x0FFF) + Regs[0];
}

void Sfml_CPU::SET_VX_RND(two_byte cmd) {
	srand(static_cast<unsigned int>(time(NULL)));
	Regs[(cmd & 0x0F00) >> 8] = (rand() % 0x0100) & (cmd & 0x00FF);
}

void Sfml_CPU::DRW_NIBBLE(two_byte cmd) {

}