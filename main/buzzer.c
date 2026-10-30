#include "buzzer.h"
#include "esp_err.h"
#include "hal/gpio_types.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <stdbool.h>

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
        vTaskDelay(pdMS_TO_TICKS(800));
        gpio_set_level(BUZZER_PIN, BUZZER_ON);
        vTaskDelay(pdMS_TO_TICKS(200));
        gpio_set_level(BUZZER_PIN, BUZZER_OFF);
    }
}

void buzzer_off(void) {
    gpio_set_level(BUZZER_PIN, BUZZER_OFF);
}
