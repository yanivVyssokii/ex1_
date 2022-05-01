cmake_minimum_required(VERSION 3.0.0)

project(ex1 VERSION 0.1.0 LANGUAGES C)

add_library(RLEList.h STATIC RLEList.c)
add_library(tool/AsciiArtTool.h STATIC tool/AsciiArtTool.c)

set(MTM_FLAG_DEBUG "-std=c99 --pedantic-errors -Wall -Werror")
set(MTM_FLAG_DEBUG "${MTM_FLAGS_DEBUG} -DNDEBUG")

set(CMAKE_C_FLAGS ${MTM_FLAGS_DEBUG})

add_link_options()
add_executable(RLEList RLEList.c RLEList.h tool/AsciiArtTool.h tool/AsciiArtTool.c tool/main.c)
