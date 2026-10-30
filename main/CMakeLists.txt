idf_component_register(SRCS "global.c" "counter.c" "screen.c" "buzzer.c" "blink.c" "bomb.c"
                    INCLUDE_DIRS "."
                    PRIV_REQUIRES esp_driver_gpio esp_driver_i2c esp_lcd esp_timer)

set(EXTRA_COMPONENT_DIRS ../components/ssd1306)
