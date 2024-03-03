cmake_minimum_required(VERSION 3.16)

project(gxruntime)

set(SRCS
	std.cpp
	std.h
	asmcoder.h
	gxaudio.cpp
	gxaudio.h
	gxchannel.cpp
	gxchannel.h
	gxdevice.cpp
	gxdevice.h
	gxdir.cpp
	gxdir.h
	gxfilesystem.cpp
	gxfilesystem.h
	gxinput.cpp
	gxinput.h
	gxruntime.cpp
	gxruntime.h
	gxsound.cpp
	gxsound.h
	gxtimer.cpp
	gxtimer.h
	std.cpp
	std.h
)

if (BB_BLITZ3D_ENABLED)
	set(SRCS ${SRCS}
		ddutil.cpp
		ddutil.h
		gxcanvas.cpp
		gxcanvas.h
		gxfont.cpp
		gxfont.h
		gxgraphics.cpp
		gxgraphics.h
		gxlight.cpp
		gxlight.h
		gxmesh.cpp
		gxmesh.h
		gxmovie.cpp
		gxmovie.h
		gxscene.cpp
		gxscene.h
	)
endif ()

add_library(gxruntime ${SRCS})

target_compile_options(gxruntime PRIVATE /Gz)

set(LIBS stdutil fmod375 winmm dsound dinput8 dxguid wsock32)

if (BB_BLITZ3D_ENABLED)
	set(LIBS ${LIBS} freeimage amstrmid ddraw)
endif ()

target_link_libraries(gxruntime ${LIBS})
