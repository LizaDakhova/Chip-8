#ifndef __BASE_CPU_C
#define __BASE_CPU_C
#include "Base_CPU.h"
class CPU : public Base_CPU {
	virtual void fetch() = 0;
	virtual void decode() = 0;
	virtual void executive() = 0;
};

#endif