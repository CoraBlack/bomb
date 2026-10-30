#ifndef __SCREEN_H__
#define __SCREEN_H__

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_PIN_SCL GPIO_NUM_5
#define SCREEN_PIN_SDA GPIO_NUM_6

#define DEFAULT_TEXT "   BOOM!!!!!!   "

void screen_init(void);
void screen_draw_string(const char* msg);
void screen_draw_number(int number);

#endif
