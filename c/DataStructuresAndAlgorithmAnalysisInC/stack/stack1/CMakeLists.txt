cmake_minimum_required(VERSION 3.6)
project(stack1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    fatal.h
    main.c
        Makefile
    stack1.c
    stack1.h
    stack1.o)

include_directories(.)

add_executable(stack1 ${SOURCE_FILES})