/**
* @file gpio_mock.cpp
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Mock ESP-IDF gpio functions
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#include "gpio_mock.hpp"
#include "driver/gpio.h"

std::unique_ptr<gpioMock> gpioMockObj;

//Create mock functions definitions for link-time replacement
extern "C"
{
    esp_err_t gpio_config(const gpio_config_t *pGPIOConfig)
    {
        return gpioMockObj->gpio_config(pGPIOConfig);
    }
    esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
    {
        return gpioMockObj->gpio_set_level(gpio_num,level);
    }
}