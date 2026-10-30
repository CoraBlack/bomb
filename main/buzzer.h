#ifndef __BUZZER_H__
#define __BUZZER_H__

#define BUZZER_ON  1
#define BUZZER_OFF 0
#define BUZZER_PIN GPIO_NUM_0

void buzzer_init(void);
void buzzer_task(void* args);
void buzzer_off(void);

#endif
