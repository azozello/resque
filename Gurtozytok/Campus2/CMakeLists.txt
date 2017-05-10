cmake_minimum_required(VERSION 3.7)
project(Campus2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp human/Human.cpp human/Human.h human/Staff.cpp human/Staff.h human/Manager.cpp human/Manager.h human/Student.cpp human/Student.h area/Hostel.cpp area/Hostel.h area/Room.cpp area/Room.h)
add_executable(Campus2 ${SOURCE_FILES})