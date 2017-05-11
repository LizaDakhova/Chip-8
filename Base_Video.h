#ifndef BASE_VID_H
#define BASE_VID_H

#include "Base_CPU.h"
class BaseVideo {
protected:
	const int MAX_WIDTH = 64 * 10;
	const int MAX_HIGHT = 32 * 10;
public:
	virtual ~BaseVideo() {}
	// void load();
	// void play();
	// int service_regs();

};

#endif