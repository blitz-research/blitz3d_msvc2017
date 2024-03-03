cmake_minimum_required(VERSION 3.16)

project(freetype)

add_library(freetype INTERFACE)

target_link_libraries(freetype INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/freetype.lib)

target_include_directories(freetype INTERFACE include)

