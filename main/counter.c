#include "counter.h"
#include "blink.h"
#include "buzzer.h"
#include "freertos/idf_additions.h"
#include "global.h"
#include "screen.h"
#include <esp_err.h>
#include <esp_log.h>
#include <esp_timer.h>
#include <freertos/FreeRTOS.h>
#include <stdint.h>
#include <stdio.h>

esp_timer_handle_t timer;
static volatile uint8_t tick_count = READY_TICKS;

static void counter_callback(void* args);

void counter_init(void) {
    esp_timer_create_args_t cfg = {
        .name = "counter_timer",
        .arg  = get_task_handlers(),
        .callback = counter_callback,
        .dispatch_method = ESP_TIMER_TASK
    };

    ESP_ERROR_CHECK(esp_timer_create(&cfg, &timer));
}

void counter_task(void *args) {
    (void)args;
    tick_count = READY_TICKS;
    esp_timer_start_periodic(timer, 1000000);
    vTaskDelete(NULL);
}

uint8_t get_ticks(void) {
    return tick_count;
}

static void counter_callback(void* args) {
    static const char* TAG = "Counter";
    TaskHandlers* handlers = args;

    char num_buf[32 + 1] = {0};
    sprintf(num_buf, "       %d       ", tick_count);
    screen_draw_string(num_buf);

    if (tick_count == 0){
        esp_timer_stop(timer);
        vTaskDelete(handlers->blink_task);
        vTaskDelete(handlers->buzzer_task);
        blink_off();
        buzzer_off();
        screen_draw_string(DEFAULT_TEXT);
        ESP_LOGI(TAG, "Tick finished");
    } else {
        ESP_LOGI(TAG, "Tick count: %d", tick_count);
        tick_count -= 1;
    }
}
