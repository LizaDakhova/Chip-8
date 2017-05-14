#ifndef SFML_MEM_H
#define SFML_MEM_H

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <vector>

#include "Def_types.h"

class SfmlMemory {
public:
	// SfmlMemory();
	SfmlMemory(two_byte start, const std::string& inputfile): 
		start_SCREEN(start), end_SCREEN(start + SCREEN_size) {
		// std::cout << std::hex << PROG_size << " " << start_SCREEN << " " << end_SCREEN << std::endl;
		mem = new byte[memSize];
		for (int i = 0; i < 80; i++) {
			mem[i] = standard_sprites[i];
		}
		// write from file
	}
	~SfmlMemory() {
		delete[] mem;
	}

	byte read(two_byte pos, bool access_id) const {
		return mem[pos];
	}
	void write(byte value, two_byte pos, bool access_id) {
		assert(!(inVideoMemory(pos) ^ access_id));
		mem[pos] = value;
	}
	two_byte size() const {
		return memSize;
	}
private:
	bool inVideoMemory(two_byte pos) {
		return (start_SCREEN <= pos && pos < end_SCREEN ||
			start_standard_sprites <= pos && pos < end_standard_sprites);
	}

	const two_byte memSize = 0x1000;
	byte* mem;

	const two_byte SCREEN_size = 0x0100;
	const two_byte start_SCREEN;
	const two_byte end_SCREEN;

	const two_byte start_standard_sprites = 0x0000;
	const two_byte end_standard_sprites = 0x0050;
	const byte standard_sprites[16 * 5] = {
		0xF0, 0x90, 0x90, 0x90, 0xF0,
		0x20, 0x60, 0x20, 0x20, 0x70,
		0xF0, 0x10, 0xF0, 0x80, 0xF0,
		0xF0, 0x10, 0xF0, 0x10, 0xF0,
		0x90, 0x90, 0xF0, 0x10, 0x10,
		0xF0, 0x80, 0xF0, 0x10, 0xF0,
		0xF0, 0x80, 0xF0, 0x90, 0xF0,
		0xF0, 0x10, 0x20, 0x40, 0x40,
		0xF0, 0x90, 0xF0, 0x90, 0xF0,
		0xF0, 0x90, 0xF0, 0x10, 0xF0,
		0xF0, 0x90, 0xF0, 0x90, 0x90,
		0xE0, 0x90, 0xE0, 0x90, 0xE0,
		0xF0, 0x80, 0x80, 0x80, 0xF0,
		0xE0, 0x90, 0x90, 0x90, 0xE0,
		0xF0, 0x80, 0xF0, 0x80, 0xF0,
		0xF0, 0x80, 0xF0, 0x80, 0x80
	};
};

#endif