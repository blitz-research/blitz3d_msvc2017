cmake_minimum_required(VERSION 3.16)

project(bblaunch)

add_executable(bblaunch WIN32
        bblaunch.cpp
        bblaunch.ico
        bblaunch.rc
#        checkdx.cpp
#        checkdx.h
        checkie.cpp
        checkie.h
        )

target_compile_options(bblaunch PRIVATE /Gz)

copy_exe_to_release(bblaunch Blitz3D)



