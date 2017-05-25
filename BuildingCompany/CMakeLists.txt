cmake_minimum_required(VERSION 3.7)
project(BuildingCompany)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/Flat.cpp classes/Flat.h classes/Building.cpp classes/Building.h classes/Manager.cpp classes/Manager.h)
add_executable(BuildingCompany ${SOURCE_FILES})