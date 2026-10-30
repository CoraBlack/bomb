#ifndef __COUNTER_H__
#define __COUNTER_H__

#define READY_TICKS 40

void counter_init(void);
void counter_task(void* args);

#endif
