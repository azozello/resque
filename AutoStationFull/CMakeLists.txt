cmake_minimum_required(VERSION 3.7)
project(AutoStation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Car.cpp classes/h/Car.h classes/cpp/Bus.cpp classes/h/Bus.h classes/cpp/Truck.cpp classes/h/Truck.h classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Driver.cpp classes/h/Driver.h classes/cpp/Manager.cpp classes/h/Manager.h classes/cpp/Repairer.cpp classes/h/Repairer.h classes/cpp/City.cpp classes/h/City.h)
add_executable(AutoStation ${SOURCE_FILES})