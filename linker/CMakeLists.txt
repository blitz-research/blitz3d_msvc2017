cmake_minimum_required(VERSION 3.16)

project(linker)

add_library(linker
        image_util.cpp
        image_util.h
        linker.cpp
        linker.h
        std.cpp
        std.h
)

target_compile_options(linker PRIVATE /Gz)

target_link_libraries(linker stdutil)
