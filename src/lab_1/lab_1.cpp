#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Arduino.h>
#include "dd_led.h"
#include "lab_1.h"
#include "dd_serial_io.h"

void lab_1_init()
{
    led_init();
    serial_io_init();
}

void lab_1_run()
{
    char deviceStr[21];
    char commandStr[11];

    printf("Select the device, available [%s]: ", LED_DEVICE_NAME);
    scanf(" %20s", deviceStr);

    if (strcasecmp(deviceStr, LED_DEVICE_NAME) == 0)
    {
        printf("\nAvailable commands: ");
        for (int i = 0; i < LED_COMMAND_COUNT; i++)
        {
            printf("%s", LED_COMMANDS[i]);
            if (i < LED_COMMAND_COUNT - 1)
            {
                printf(", ");
            }
        }

        do
        {
            printf("\nEnter command to execute: ");
            scanf(" %10s", commandStr);
            led_execute_command(commandStr);
        } while (strcasecmp(commandStr, "e") != 0);
    }
    else
    {
        printf("\nUnknown device: %s\n", deviceStr);
    }
}
