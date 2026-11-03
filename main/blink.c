#include "blink.h"
#include "counter.h"
#include <esp_err.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <stdbool.h>
#include <stdint.h>

static bool is_led_on = false;

static uint16_t calculate_gap_tick(uint8_t ticks) {
    return (ticks >= READY_TICKS / 2) ? 500 : (uint16_t)((float)ticks / ((float)READY_TICKS / 2) * 500);
};

void blink_init() {
    gpio_config_t led_cfg = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ull << LED_PIN),
        .intr_type    = GPIO_INTR_DISABLE,
        .pull_up_en   = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
    };

    ESP_ERROR_CHECK(gpio_config(&led_cfg));
    ESP_ERROR_CHECK(gpio_set_level(LED_PIN, LED_OFF));
}

void blink_task(void* args) {
    while(1) {
        uint16_t gap_tick = calculate_gap_tick(get_ticks());
        vTaskDelay(pdMS_TO_TICKS(gap_tick));
        gpio_set_level(LED_PIN, is_led_on ? LED_OFF : LED_ON);
        is_led_on = !is_led_on;
    }
}

void blink_off(void) {
    gpio_set_level(LED_PIN, LED_OFF);
}
