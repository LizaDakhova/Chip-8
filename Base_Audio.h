#ifndef __BASE_CPU_H_A
#define __BASE_CPU_H_A
#include "Base_CPU.h"
class BaseAudio {
public:
	BaseAudio();
	void load();
	void play();
	int service_regs();
private:

};

#endif
