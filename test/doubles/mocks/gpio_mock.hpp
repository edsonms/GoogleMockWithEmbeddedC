/**
* @file gpio_mock.hpp
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Mock ESP-IDF gpio functions
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#pragma once

#include <memory>
#include <gmock/gmock.h>
#include "driver/gpio.h"

//create the MOCKS
class gpioFunctions
{
    public:
        virtual ~gpioFunctions(){}
        virtual esp_err_t gpio_config(const gpio_config_t *pGPIOConfig) = 0;
        virtual esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level) = 0;
};

class gpioMock : public gpioFunctions
{
    public:
        MOCK_METHOD(esp_err_t,gpio_config,(const gpio_config_t *pGPIOConfig),(override));
        MOCK_METHOD(esp_err_t, gpio_set_level,(gpio_num_t gpio_num, uint32_t level),(override));
};

//create globl mock object
extern std::unique_ptr<gpioMock> gpioMockObj;
