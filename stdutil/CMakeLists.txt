cmake_minimum_required(VERSION 3.16)

project(stdutil)

add_library(stdutil
		stdutil.cpp
		stdutil.h
)

target_compile_options(stdutil PRIVATE /Gz)

