/**
* @file test_main.cpp
* @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
* @brief Main test runner
* @version 0.1
* @date 2023-07-29
* 
* @copyright Copyright (c) 2023
* 
*/

#include <gtest/gtest.h>

int main(int argc, char** argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}