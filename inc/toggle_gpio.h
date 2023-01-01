/**
* @file toggle_gpio.h
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Functions to toggle gpio
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#ifndef TOGGLE_GPIO_H_
#define TOGGLE_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "esp_err.h"
#include "gpio_num.h"

#define ONE_SECOND 1000000
#define HIGH 255
#define LOW 0

extern esp_err_t ConfigureGPIO(gpio_num_t PinNumber);
extern esp_err_t ToggleGPIO(gpio_num_t PinNumber);

#ifdef __cplusplus
}
#endif

#endif //TOGGLE_GPIO_H_