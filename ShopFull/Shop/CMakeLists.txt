cmake_minimum_required(VERSION 3.7)
project(Shop)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Manager.cpp classes/h/Manager.h classes/cpp/Order.cpp classes/h/Order.h classes/cpp/Item.cpp classes/h/Item.h classes/cpp/Cash.cpp classes/h/Cash.h classes/cpp/Stock.cpp classes/h/Stock.h classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Serializer.cpp classes/h/Serializer.h)
add_executable(Shop ${SOURCE_FILES})
