cmake_minimum_required(VERSION 3.16)

project(compiler)

add_library(compiler
		assem_x86/asm_insts.cpp
		assem_x86/assem_x86.cpp
		assem_x86/operand.cpp
		codegen_x86/codegen_x86.cpp
		codegen_x86/tile.cpp
		decl.cpp
		declnode.cpp
		environ.cpp
		exprnode.cpp
		node.cpp
		parser.cpp
		prognode.cpp
		std.cpp
		stmtnode.cpp
		toker.cpp
		type.cpp
		varnode.cpp
		assem.h
		assem_x86/assem_x86.h
		assem_x86/insts.h
		assem_x86/operand.h
		codegen.h
		codegen_x86/codegen_x86.h
		codegen_x86/tile.h
		decl.h
		declnode.h
		environ.h
		ex.h
		exprnode.h
		label.h
		node.h
		nodes.h
		parser.h
		prognode.h
		std.h
		stmtnode.h
		toker.h
		type.h
		varnode.h
)

target_compile_options(compiler PRIVATE /Gz)

target_link_libraries(compiler stdutil)
