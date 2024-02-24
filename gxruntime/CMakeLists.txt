cmake_minimum_required(VERSION 3.16)

project(gxruntime)

add_library(gxruntime
		std.cpp
		ddutil.cpp
		asmcoder.h
		ddutil.cpp
		ddutil.h
		gxaudio.cpp
		gxaudio.h
		gxcanvas.cpp
		gxcanvas.h
		gxchannel.cpp
		gxchannel.h
		gxdevice.cpp
		gxdevice.h
		gxdir.cpp
		gxdir.h
		gxfilesystem.cpp
		gxfilesystem.h
		gxfont.cpp
		gxfont.h
		gxgraphics.cpp
		gxgraphics.h
		gxinput.cpp
		gxinput.h
		gxlight.cpp
		gxlight.h
		gxmesh.cpp
		gxmesh.h
		gxmovie.cpp
		gxmovie.h
		gxruntime.cpp>
		gxruntime.h
		gxscene.cpp
		gxscene.h
		gxsound.cpp
		gxsound.h
		gxtimer.cpp
		gxtimer.h
		std.cpp
		std.h
)

target_compile_options(gxruntime PRIVATE /Gz)

add_compile_options(gxruntime "/Gz")

target_link_libraries(gxruntime stdutil freeimage fmod375 wsock32.lib amstrmid winmm dxguid ddraw dsound dinput8)