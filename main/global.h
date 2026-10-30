#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <freertos/FreeRTOS.h>

typedef struct {
    TaskHandle_t blink_task;
    TaskHandle_t buzzer_task;
    TaskHandle_t counter_task;
} TaskHandlers;

TaskHandlers* get_task_handlers(void);

#endif
