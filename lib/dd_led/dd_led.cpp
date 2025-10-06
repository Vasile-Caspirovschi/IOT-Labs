#include "dd_led.h"
#include <Arduino.h>

void led_init()
{
    pinMode(LED_PIN, OUTPUT);
}

void led_on()
{
    digitalWrite(LED_PIN, HIGH);
}

void led_off()
{
    digitalWrite(LED_PIN, LOW);
}

void led_blink()
{
    printf("\nBlinking... press 'e' to stop.\n");

    while (1)
    {
        if (Serial.available())
        {
            char c = getchar();
            if (c == 'e' || c == 'E')
            {
                printf("\nStopping blink.\n");
                break;
            }
        }

        digitalWrite(LED_PIN, HIGH);
        delay(200);
        digitalWrite(LED_PIN, LOW);
        delay(200);
    }
}

void led_execute_command(char *command)
{
    if (strcmp(command, LED_COMMANDS[0]) == 0)
    {
        printf("\nTurning LED ON\n");
        led_on();
    }
    else if (strcmp(command, LED_COMMANDS[1]) == 0)
    {
        printf("\nTurning LED OFF\n");
        led_off();
    }
    else if (strcmp(command, LED_COMMANDS[2]) == 0)
    {
        led_blink();
    }
    else if (command == "e")
    {
        printf("\nExiting\n");
    }
    else
    {
        printf("\nUnknown command %s\n", command);
    }
}
