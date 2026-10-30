#include "blink.h"
#include "buzzer.h"
#include "counter.h"
#include "freertos/idf_additions.h"
#include "global.h"
#include "screen.h"
#include <freertos/FreeRTOS.h>

static void bomb_once();

void app_main(void) {
    blink_init();
    buzzer_init();
    screen_init();
    counter_init();

    screen_draw_string(DEFAULT_TEXT);

    bomb_once();
}

static void bomb_once() {
    TaskHandlers* handlers = get_task_handlers();

    xTaskCreate(blink_task,
        "blink_task", 
        2048,
        NULL,
        10, 
        &handlers->blink_task
    );

    xTaskCreate(buzzer_task,
        "buzzer_task", 
        2048,
        NULL,
        10,
        &handlers->buzzer_task
    );

    xTaskCreate(counter_task, 
        "counter_task", 
        2048,
        NULL,
        10,
        &handlers->counter_task
    );
}
