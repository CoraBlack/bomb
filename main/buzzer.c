#include "buzzer.h"
#include "counter.h"
#include "esp_err.h"
#include "hal/gpio_types.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <stdbool.h>
#include <stdint.h>

void buzzer_init() {
    gpio_config_t buzzer_cfg = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ull << BUZZER_PIN,
        .intr_type    = GPIO_INTR_DISABLE,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
    };

    ESP_ERROR_CHECK(gpio_config(&buzzer_cfg));
    ESP_ERROR_CHECK(gpio_set_level(BUZZER_PIN, BUZZER_OFF));
}

void buzzer_task(void *args) {
    while(1) {
        uint8_t  ticks  = get_ticks(); 
        uint16_t off_ms = (ticks >= READY_TICKS / 2) ? 800 : (uint16_t)((float)ticks / ((float)READY_TICKS / 2) * 800);
        uint16_t on_ms  = (ticks >= READY_TICKS / 2) ? 200 : (uint16_t)((float)ticks / ((float)READY_TICKS / 2) * 200);

        vTaskDelay(pdMS_TO_TICKS(off_ms));
        gpio_set_level(BUZZER_PIN, BUZZER_ON);
        vTaskDelay(pdMS_TO_TICKS(on_ms));
        gpio_set_level(BUZZER_PIN, BUZZER_OFF);
    }
}

void buzzer_off(void) {
    gpio_set_level(BUZZER_PIN, BUZZER_OFF);
}
