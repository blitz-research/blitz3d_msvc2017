cmake_minimum_required(VERSION 3.16)

project(fmod375)

add_library(fmod375 INTERFACE)

target_link_libraries(fmod375 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/fmodvc.lib)

target_include_directories(fmod375 INTERFACE include)

