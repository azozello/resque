cmake_minimum_required(VERSION 3.7)
project(GasStation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp core/store/Oil.cpp core/store/Oil.h core/store/Petrol.cpp core/store/Petrol.h core/buisness/Order.cpp core/buisness/Order.h)
add_executable(GasStation ${SOURCE_FILES})