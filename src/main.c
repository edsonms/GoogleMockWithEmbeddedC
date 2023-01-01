/**
* @file main.c
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Main production code
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#include <stdint.h>
#include "blink_gpio.h"

int main(void)
{
    const uint8_t PinNumber = 2;
    (void)ConfigureGPIO(PinNumber);
    while(1)
    {
        (void)ToggleGPIO(PinNumber);
    }
}