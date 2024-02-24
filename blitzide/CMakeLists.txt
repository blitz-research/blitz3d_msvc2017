cmake_minimum_required(VERSION 3.16)

project(blitzide)

add_executable(blitzide WIN32
        about.cpp
        blitzide.cpp
        editor.cpp
        funclist.cpp
        htmlhelp.cpp
        libs.cpp
        mainframe.cpp
        prefs.cpp
        stdafx.cpp
        tabber.cpp
        blitzide.rc
        about.h
        blitzide.h
        editor.h
        funclist.h
        htmlhelp.h
        libs.h
        mainframe.h
        prefs.h
        stdafx.h
        tabber.h
)

target_compile_options(blitzide PRIVATE /Gz)

copy_exe_to_release(blitzide bin/ide)
