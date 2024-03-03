cmake_minimum_required(VERSION 3.16)

project("libsgd")

add_library(libsgd INTERFACE)

#target_include_directories(libsgd INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(libsgd INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libsgd_static.lib)

target_include_directories(libsgd INTERFACE ${CMAKE_SOURCE_DIR}/../libsgd/libsgd/include)
target_link_libraries(libsgd INTERFACE ${CMAKE_SOURCE_DIR}/../libsgd/cmake-build-windows-32-bit-release/libsgd/libsgd_static.lib)
