cmake_minimum_required(VERSION 3.7)
project(Campus)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp classes/cpp/Human.cpp classes/h/Human.h classes/cpp/Liver.cpp classes/h/Liver.h classes/cpp/Staff.cpp classes/h/Staff.h classes/cpp/Teacher.cpp classes/h/Teacher.h classes/cpp/Student.cpp classes/h/Student.h classes/cpp/Hostel.cpp classes/h/Hostel.h classes/cpp/Room.cpp classes/h/Room.h)
add_executable(Campus ${SOURCE_FILES})