cmake_minimum_required(VERSION 3.7)
project(casino)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp game/Game.cpp game/Game.h game/Bones.cpp game/Bones.h game/Check.cpp game/Check.h game/Roulette.cpp game/Roulette.h game/Player.cpp game/Player.h)
add_executable(casino ${SOURCE_FILES})