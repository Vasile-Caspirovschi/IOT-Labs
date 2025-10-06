#ifndef DD_LED_H
#define DD_LED_H

#define LED_PIN 13
#define LED_DEVICE_NAME "led"
#define LED_COMMAND_COUNT   3

static const char *LED_COMMANDS[] = { "on", "off", "blink" };

void led_init();
void led_on();
void led_off();
void led_blink();
void led_execute_command(char* command);

#endif