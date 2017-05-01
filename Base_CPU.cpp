#ifndef __BASE_CPU_C
#define __BASE_CPU_C
#include "Base_CPU.h"
void Base_CPU::do_cycle() {
	fetch();
	decode();
	executive();
}
#endif