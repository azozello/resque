cmake_minimum_required(VERSION 3.7)
project(Barbershop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Manager.cpp classes/h/Manager.h classes/cpp/HairDress.cpp classes/h/HairDress.h classes/cpp/HairDresser.cpp classes/h/HairDresser.h classes/cpp/Order.cpp classes/h/Order.h)
add_executable(Barbershop ${SOURCE_FILES})