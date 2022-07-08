cmake_minimum_required(VERSION 3.21)
project(Program2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Program2 main.cpp univClass.h person.h student.h employee.h univClass.cpp person.cpp student.cpp employee.cpp)
