#include "screen.h"
#include "ssd1306.h"
#include <string.h>

SSD1306_t dev;

void screen_init(void) {
    i2c_master_init(&dev, SCREEN_PIN_SDA, SCREEN_PIN_SCL, 0);
    ssd1306_init(&dev, SCREEN_WIDTH, SCREEN_WIDTH);
    ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
}

void screen_draw_string(const char* msg) {
    ssd1306_display_text(&dev, 0, msg, strlen(msg), false);
}

void screen_draw_number(int number) {

}
