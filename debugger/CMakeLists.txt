cmake_minimum_required(VERSION 3.16)

project(debugger)

add_library(debugger MODULE
		debugger.h
		debugger.rc
		debuggerapp.cpp
		debuggerapp.h
		debugtree.cpp
		debugtree.h
		mainframe.cpp
		mainframe.h
		prefs.cpp
		prefs.h
		sourcefile.cpp
		sourcefile.h
		stdafx.cpp
		stdafx.h
		stdutil.cpp
		tabber.cpp
		tabber.h
)

target_compile_options(debugger PRIVATE /Gz)

# Need this for MFC based DLLs.
target_compile_definitions(debugger PRIVATE _USRDLL)

copy_dll_to_release(debugger bin/debugger)
