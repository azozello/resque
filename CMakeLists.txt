cmake_minimum_required(VERSION 3.7)
project(Shop)

enable_testing()

set(CMAKE_CXX_STANDARD 11)

set(UNIT_TESTS tests/Test.cpp)
set(MAIN_FILE main.cpp)
set(FILES_TO_TEST classes/cpp/Cash.cpp classes/cpp/Item.cpp classes/cpp/Stock.cpp classes/cpp/Manager.cpp)

set(SOURCE_FILES main.cpp classes/cpp/Shop.cpp classes/h/Shop.h classes/cpp/Manager.cpp classes/h/Manager.h classes/cpp/Order.cpp classes/h/Order.h classes/cpp/Item.cpp classes/h/Item.h classes/cpp/Cash.cpp classes/h/Cash.h classes/cpp/Stock.cpp classes/h/Stock.h)
add_executable(Shop ${SOURCE_FILES})

add_library(codeToTest ${FILES_TO_TEST})

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread codeToTest)