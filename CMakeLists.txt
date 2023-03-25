cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Person.cpp Person.h Customer.cpp Customer.h Mechanic.cpp Mechanic.h QueueTemp.h)
