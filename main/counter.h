#ifndef __COUNTER_H__
#define __COUNTER_H__

#include <stdint.h>

#define READY_TICKS 20

void counter_init(void);
void counter_task(void* args);
uint8_t get_ticks(void);

#endif
