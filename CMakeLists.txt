cmake_minimum_required(VERSION 3.30)
project(Phonebook)

set(CMAKE_CXX_STANDARD 20)

set(SRC
bst.cpp
bst.hpp
person.cpp
person.h
main.cpp)

set(TEST_SRC
        UnitTests.cpp
        personTest.cpp)

set(PHONEBOOK_SRC
main.cpp)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Catch)

add_library(phonebook ${SRC})

add_executable(tests catch.hpp ${TEST_SRC} ${SRC})
target_link_libraries(tests pthread)

add_executable(main ${PHONEBOOK_SRC})
target_link_libraries(main phonebook)