cmake_minimum_required(VERSION 3.7)
project(OSBB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Head.cpp classes/h/Head.h classes/cpp/Member.cpp classes/h/Member.h classes/cpp/Event.cpp classes/h/Event.h classes/cpp/Good.cpp classes/h/Good.h)
add_executable(OSBB ${SOURCE_FILES})