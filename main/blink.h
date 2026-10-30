#ifndef __BLINK_H__
#define __BLINK_H__

#define LED_ON  0
#define LED_OFF 1
#define LED_PIN GPIO_NUM_21

void blink_init();
void blink_task(void* args);
void blink_off(void);

#endif
