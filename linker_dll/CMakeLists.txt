cmake_minimum_required(VERSION 3.16)

project(linker_dll)

add_library(linker_dll MODULE
		linker_dll.cpp
)

target_compile_options(linker_dll PRIVATE /Gz)

target_link_libraries(linker_dll linker)

copy_dll_to_release(linker_dll bin/linker)




