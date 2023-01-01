/**
* @file toggle_gpio.c
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Functions to toggle gpio
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/
#include "toggle_gpio.h"
#include <stdio.h>
#include "esp_system.h"
#include "esp_timer.h"
#include "driver/gpio.h"

esp_err_t ConfigureGPIO(gpio_num_t PinNumber) 
{
    esp_err_t ResponseStatus;
    gpio_config_t io_conf;

    //Config the pin
    io_conf.pin_bit_mask = (1ULL << PinNumber);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    ResponseStatus = gpio_config(&io_conf);

    //Check if config was ok and return its status if not
    if (ESP_OK != ResponseStatus)
        return (ResponseStatus);
    
    //If config was ok, set initial level too LOW
    ResponseStatus = gpio_set_level(PinNumber, LOW);
    
    return (ResponseStatus);
}

esp_err_t ToggleGPIO(gpio_num_t PinNumber) 
{
        static uint8_t PinLastState = LOW;
        esp_err_t ResponseStatus;

        PinLastState = ~PinLastState;
        ResponseStatus = gpio_set_level(PinNumber,PinLastState);  // Toggle pin

        return (ResponseStatus);
}