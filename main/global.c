#include "global.h"

static TaskHandlers handlers = {
    .blink_task   = NULL,
    .buzzer_task  = NULL,
    .counter_task = NULL
};

TaskHandlers* get_task_handlers(void) {
    return &handlers;
}