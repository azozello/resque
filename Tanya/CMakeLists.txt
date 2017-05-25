cmake_minimum_required(VERSION 3.7)
project(Tanya)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/Player.cpp classes/Player.h classes/Track.cpp classes/Track.h classes/Human.cpp classes/Human.h classes/Manager.cpp classes/Manager.h)
add_executable(Tanya ${SOURCE_FILES})