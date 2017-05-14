cmake_minimum_required(VERSION 3.7)
project(Radio)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Caster.cpp classes/h/Caster.h classes/cpp/Item.cpp classes/h/Item.h classes/cpp/Advertise.cpp classes/h/Advertise.h classes/cpp/Song.cpp classes/h/Song.h classes/cpp/Programm.cpp classes/h/Programm.h)
add_executable(Radio ${SOURCE_FILES})