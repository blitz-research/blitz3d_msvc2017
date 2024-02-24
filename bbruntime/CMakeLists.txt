cmake_minimum_required(VERSION 3.16)

project(bbruntime)

add_library(bbruntime
        basic.cpp
        basic.h
        bbaudio.cpp
        bbaudio.h
        bbbank.cpp
        bbbank.h
        bbblitz3d.cpp
        bbblitz3d.h
        bbfilesystem.cpp
        bbfilesystem.h
        bbgraphics.cpp
        bbgraphics.h
        bbinput.cpp
        bbinput.h
        bbmath.cpp
        bbmath.h
        bbruntime.cpp
        bbruntime.h
        bbsockets.cpp
        bbsockets.h
        bbstream.cpp
        bbstream.h
        bbstring.cpp
        bbstring.h
        bbsys.cpp
        bbsys.h
        std.cpp
        std.h
        userlibs.cpp
        userlibs.h
        )

target_compile_options(bbruntime PRIVATE /Gz)

target_link_libraries(bbruntime blitz3d)
