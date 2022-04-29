cmake_minimum_required(VERSION 3.0.0)

project(hw1 VERSION 0.1.0 LANGUAGES C)

add_library(RLEList.h STATIC RLEList.c)
add_library(AsciiArtTool.h STATIC AsciiArtTool.c)

set(MTM_FLAG_DEBUG "-std=c99 --pedantic-errors -Wall -Werror")
set(MTM_FLAG_DEBUG "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})

add_link_options()
add_executable(RLEList RLEList.c RLEList.h AsciiArtTool.h AsciiArtTool.c main.c)
