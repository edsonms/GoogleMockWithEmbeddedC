# /**
# * @file CMakeLists.txt
# * @author Edson Manoel da Silva (https://www.linkedin.com/in/edsonms/)
# * @brief bottom level cmakelists
# * @version 0.1
# * @date 2023-07-29
# * 
# * @copyright Copyright (c) 2023
# * 
# */

cmake_minimum_required(VERSION 3.21)
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

#google test and google mock
include_directories(test/googletest/include/)
include_directories(test/googletest/googlemock/include/gmock/)
#include test files
include_directories(
    "${CMAKE_SOURCE_DIR}/test/inc/"
    "${CMAKE_SOURCE_DIR}/test/doubles/mocks/"
    "${CMAKE_SOURCE_DIR}/test/doubles/stubs/"
    "${CMAKE_SOURCE_DIR}/test/doubles/fakes/"
#production code files
    "${CMAKE_SOURCE_DIR}/inc/"
    "${CMAKE_SOURCE_DIR}/src/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/driver/gpio/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/hal/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/soc/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/soc/esp32/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/soc/esp32/include/soc/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/esp_system/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/esp_common/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/esp_rom/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/nvs_flash/test_nvs_host/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/esp_timer/include/"
    "${CMAKE_SOURCE_DIR}/esp-idf/components/esp_hw_support/include/")

#set the files to be compiled. We are only interested in compiling test code here
file(GLOB_RECURSE SOURCES RELATIVE 
    "${CMAKE_SOURCE_DIR}/test"
    "src/*.cpp" "googletest/*.cpp" "doubles/**/*.cpp")

#build executable
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC gtest gmock gcov)