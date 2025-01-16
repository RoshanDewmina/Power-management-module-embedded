cmake_minimum_required(VERSION 3.10)
project(PowerManagementModule)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(power_management src/main.cpp src/PowerManager.cpp)
add_executable(power_management_test tests/test_power_manager.cpp src/PowerManager.cpp)
