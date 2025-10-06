#include <Arduino.h>
#include "lab_1/lab_1.h"

#define LAB_1

void setup()
{
#ifdef LAB_1
  lab_1_init();
#endif
}

void loop()
{
#ifdef LAB_1
  lab_1_run();
#endif
}