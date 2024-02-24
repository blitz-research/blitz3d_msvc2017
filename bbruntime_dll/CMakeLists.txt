cmake_minimum_required(VERSION 3.16)

project(bbruntime_dll)

add_library(bbruntime_dll MODULE
        bbexe.ico
        bbruntime_dll.cpp
        bbruntime_dll.h
        bbruntime_dll.rc
        resource.h
        )

target_compile_options(bbruntime_dll PRIVATE /Gz)

target_link_options(bbruntime_dll PRIVATE /SUBSYSTEM:WINDOWS)

target_link_libraries(bbruntime_dll bbruntime)

copy_dll_to_release(bbruntime_dll bin/runtime)
