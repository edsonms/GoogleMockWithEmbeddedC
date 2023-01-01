/**
* @file test_gpio.cpp
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Test toggle GPIO function
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h> 
#include "gpio_mock.hpp"

using ::testing::Pointee;
using ::testing::AtLeast;
using ::testing::Return;

namespace GpioTests
{
    #include "toggle_gpio.c"

    class GpioAPIsTest : public ::testing::Test
    {
    protected:

        void SetUp() override
        {
            //Set up mock object
            gpioMockObj = new gpioMock;

            //Replace the original function to the mock one using pointers
            gpio_config_ptr = gpio_config;
            gpio_set_level_ptr = gpio_set_level;
        }

        void TearDown() override
        {
            //Clean up the mock object used
            delete gpioMockObj;
        }
        //Function pointers definition
        esp_err_t (*gpio_config_ptr)(const gpio_config_t *pGPIOConfig);
        esp_err_t (*gpio_set_level_ptr)(gpio_num_t gpio_num, uint32_t level);
    };


    TEST_F(GpioAPIsTest,TestConfigureGPIO)
    {
    //List of tests to be done
    //1 - Test passing a correct pin number, check if response is OK and if the pin was set to low       
    //2 - Test passing invalid pin number and if the function returns an error
    
    }

    TEST_F(GpioAPIsTest, TestToggleGpio)
    {
    //List of tests to be done
    //1 - Test toggling from LOW to HIGH   
    //2 - Test toggling from HIGH to LOW
    //3 - Test if passing invalid pin number returns an error
    
    }
}