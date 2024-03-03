cmake_minimum_required(VERSION 3.16)

set(CMAKE_VERBOSE_MAKEFILE OFF)

project("Blitz3D")

if (NOT (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC"))
	message(FATAL_ERROR "Blitz3D must be built using MSVC.")
endif ()

if (NOT (CMAKE_SIZEOF_VOID_P EQUAL 4))
	message(FATAL_ERROR "Blitz3D must be built in 32 bit mode: Pass '-DCMAKE_GENERATOR_PLATFORM=Win32' to cmake when configuring.")
endif ()

message(STATUS "Configuring Blitz3D for build type ${CMAKE_BUILD_TYPE}")

set(BB_BLITZ3D_ENABLED 1)
set(BB_LIBSGD_ENABLED 0)

if(BB_BLITZ3D_ENABLED)
	add_compile_definitions(BB_BLITZ3D_ENABLED=1)
endif()

if(BB_LIBSGD_ENABLED)
	add_compile_definitions(BB_LIBSGD_ENABLED=1)
endif()

if(NOT BB_BLITZ3D_ENABLED AND NOT BB_LIBSGD_ENABLED)
	set(BB_HEADLESS 1)
	add_compile_definitions(BB_HEADLESS=1)
endif ()

# Using C++ 14
set(CMAKE_CXX_STANDARD 14)

# Add our root include directory
include_directories(${CMAKE_SOURCE_DIR})

# Use static CRT
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

function(copy_dll_to_release target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.dll)
	set(DST ${CMAKE_SOURCE_DIR}/_release/${dst}.dll)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

function(copy_exe_to_release target dst)
	set(SRC $<TARGET_FILE_DIR:${target}>/${target}.exe)
	set(DST ${CMAKE_SOURCE_DIR}/_release/${dst}.exe)
	add_custom_command(TARGET ${target} POST_BUILD VERBATIM
			COMMAND ${CMAKE_COMMAND} -E echo "Copying ${target} output file \"${SRC}\" to \"${DST}\""
			COMMAND ${CMAKE_COMMAND} -E copy ${SRC} ${DST})
endfunction()

add_subdirectory(config)
add_subdirectory(stdutil)
add_subdirectory(compiler)
add_subdirectory(blitz)
add_subdirectory(linker)
add_subdirectory(linker_dll)
add_subdirectory(debugger)
add_subdirectory(blitzide)
add_subdirectory(fmod375)
add_subdirectory(gxruntime)
add_subdirectory(bbruntime)
add_subdirectory(bbruntime_dll)
add_subdirectory(bblaunch)

if (BB_BLITZ3D_ENABLED)
	add_subdirectory(freeimage)
	add_subdirectory(blitz3D)
elseif(BB_LIBSGD_ENABLED)
	add_subdirectory(libsgd)
endif ()
