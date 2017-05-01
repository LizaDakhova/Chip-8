#ifndef __BASE_CPU_H_V
#define __BASE_CPU_H_V
#include "Base_CPU.h"
class BaseVideo {
protected:
	const int MAX_WIDTH = 64 * 10;
	const int MAX_HIGHT = 32 * 10;
public:
	BaseVideo();	
	void load();
	void play();
	int service_regs();

};

#endif