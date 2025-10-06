#include "dd_serial_io.h"
#include <Arduino.h>

static FILE uart_stream;

static int uart_putc(char c, FILE *stream)
{
    if (c == '\n') {
        Serial.write('\r');
    }
    Serial.write(c);
    return 0;
}

static int uart_getc(FILE *stream)
{
    while (!Serial.available())
        ;
    int ch = Serial.read();
    Serial.write(ch);
    return ch;
}

void serial_io_init()
{
    Serial.begin(BAUD_RATE);
    while (!Serial)
        ;
    fdev_setup_stream(&uart_stream, uart_putc, uart_getc, _FDEV_SETUP_RW);
    stdin = stdout = &uart_stream;
}