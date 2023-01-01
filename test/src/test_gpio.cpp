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

#include <iostream>


using ::testing::_;
using ::testing::Return;
using namespace std;

namespace GpioTests
{
    //System under test
    #include "toggle_gpio.c"

    class GpioAPIsTest : public ::testing::Test
    {
    protected:

        void SetUp() override
        {
            //Set up mock object
            gpioMockObj = new gpioMock;

            //Replace the original function to the mock one using pointers
            //gpio_config_ptr = gpio_config;
            //gpio_set_level_ptr = gpio_set_level;
        }

        void TearDown() override
        {
            //Clean up the mock object used
            delete gpioMockObj;
        }
        //Function pointers definition
        //esp_err_t (*gpio_config_ptr)(const gpio_config_t *pGPIOConfig);
        //esp_err_t (*gpio_set_level_ptr)(gpio_num_t gpio_num, uint32_t level);
    };


    TEST_F(GpioAPIsTest,TestConfigureGPIO)
    {
        //List of tests to be done for function TestConfigureGPIO
        //1 - Test returning success from gpio_config and gpio_set_level
        //2 - Test returning error from gpio_config
        //3 - Test returning error from gpio_set_level

        bool TestHasError = 0;
        esp_err_t test_return = ESP_ERR_INVALID_ARG;

        //////////////////////////////////////////////// Test 1 /////////////////////////////////////////////////////////////////////////////////////
        cout << endl << "[   INFO   ] Test 1 - Test returning success from gpio_config and gpio_set_level" << endl;
        
        EXPECT_CALL(*gpioMockObj,gpio_config(_)) //The called argument is a pointer, so we will test call expectation with the any argument pararameter
        .Times(1)
        .WillOnce(Return(ESP_OK));
        
        EXPECT_CALL(*gpioMockObj,gpio_set_level(GPIO_NUM_2,LOW))
        .Times(1)
        .WillOnce(Return(ESP_OK));

        test_return = ConfigureGPIO(GPIO_NUM_2);
        
        EXPECT_EQ(ESP_OK, test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 1 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 1 pass" <<endl;         

        //////////////////////////////////////////////// Test 2 /////////////////////////////////////////////////////////////////////////////////////
        TestHasError = 0;
        test_return = ESP_OK;
        cout << endl << "[   INFO   ] Test 2 - Test returning error from gpio_config" << endl;

        EXPECT_CALL(*gpioMockObj,gpio_config(_)) //The called argument is a pointer, so we will test call expectation with the any argument pararameter
        .Times(1)
        .WillOnce(Return(ESP_ERR_INVALID_ARG));

        test_return = ConfigureGPIO((gpio_num_t)(GPIO_NUM_38));
        
        EXPECT_EQ(ESP_ERR_INVALID_ARG, test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 2 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 2 pass" <<endl;     

        //////////////////////////////////////////////// Test 3 /////////////////////////////////////////////////////////////////////////////////////
        TestHasError = 0;
        test_return = ESP_OK;
        cout << endl << "[   INFO   ] Test 3 - Test returning error from gpio_set_level" << endl;

        EXPECT_CALL(*gpioMockObj,gpio_config(_)) //The called argument is a pointer, so we will test call expectation with the any argument pararameter
        .Times(1)
        .WillOnce(Return(ESP_OK));
        
        EXPECT_CALL(*gpioMockObj,gpio_set_level(GPIO_NUM_39,LOW))
        .Times(1)
        .WillOnce(Return(ESP_ERR_INVALID_ARG));

        test_return = ConfigureGPIO(GPIO_NUM_39);
       
        EXPECT_EQ(ESP_ERR_INVALID_ARG, test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 3 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 3 pass" <<endl << endl;       
    
    }

    TEST_F(GpioAPIsTest, TestToggleGpio)
    {
    //List of tests to be done for function ToggleGpio
    //1 - Test toggling from LOW to HIGH   
    //2 - Test toggling from HIGH to LOW
    //3 - Test gpio_set_level returning error

        bool TestHasError = 0;
        esp_err_t test_return = ESP_ERR_INVALID_ARG;

        //////////////////////////////////////////////// Test 1 /////////////////////////////////////////////////////////////////////////////////////
        cout << endl << "[   INFO   ] Test 1 - Test toggling pin from initial state LOW to HIGH" << endl;    
        
        EXPECT_CALL(*gpioMockObj,gpio_set_level(GPIO_NUM_2,HIGH))
        .Times(1)
        .WillOnce(Return(ESP_OK));

        test_return = ToggleGPIO(GPIO_NUM_2);

        EXPECT_EQ(ESP_OK,test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 1 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 1 pass" <<endl << endl;  

        //////////////////////////////////////////////// Test 2 /////////////////////////////////////////////////////////////////////////////////////
        cout << endl << "[   INFO   ] Test 2 - Test toggling pin from HIGH to LOW" << endl;   

        EXPECT_CALL(*gpioMockObj,gpio_set_level(GPIO_NUM_2,LOW))
        .Times(1)
        .WillOnce(Return(ESP_OK));

        test_return = ToggleGPIO(GPIO_NUM_2);

        EXPECT_EQ(ESP_OK,test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 2 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 2 pass" <<endl << endl;  

        //////////////////////////////////////////////// Test 3 /////////////////////////////////////////////////////////////////////////////////////
        cout << endl << "[   INFO   ] Test 3 - Test toggling pin return error" << endl;   
        EXPECT_CALL(*gpioMockObj,gpio_set_level(GPIO_NUM_2,HIGH))
        .Times(1)
        .WillOnce(Return(ESP_ERR_INVALID_ARG));

        test_return = ToggleGPIO(GPIO_NUM_2);        

        EXPECT_EQ(ESP_ERR_INVALID_ARG,test_return) << (TestHasError = true); //If expectation fails, set TestHasError to true;
        if (TestHasError)
            std::cout << "[   FAIL   ] " << "Test 3 fail" << endl;
        else
            std::cout << "[    OK    ] " << "Test 3 pass" <<endl << endl;  

    }
}