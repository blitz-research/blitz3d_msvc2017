cmake_minimum_required(VERSION 3.16)

project(bbruntime)

set(SRCS
	basic.cpp
	basic.h
	bbaudio.cpp
	bbaudio.h
	bbbank.cpp
	bbbank.h
	bbfilesystem.cpp
	bbfilesystem.h
	bbinput.cpp
	bbinput.h
	bbmath.cpp
	bbmath.h
	bbruntime.cpp
	bbruntime.h
	bbsockets.cpp
	bbsockets.h
	bbstream.cpp
	bbstream.h
	bbstring.cpp
	bbstring.h
	bbsys.cpp
	bbsys.h
	std.cpp
	std.h
	userlibs.cpp
	userlibs.h
)
set(LIBS gxruntime)

if (BB_BLITZ3D_ENABLED)

	set(SRCS ${SRCS}
		bbblitz3d.cpp
		bbblitz3d.h
		bbgraphics.cpp
		bbgraphics.h
	)
	set(LIBS gxruntime blitz3d)

elseif(BB_LIBSGD_ENABLED)

	set(SRCS ${SRCS}
		bbsgd.cpp
		bbsgd.h
	)
	set(LIBS gxruntime libsgd)

endif()

add_library(bbruntime ${SRCS})

target_compile_options(bbruntime PRIVATE /Gz)

target_link_libraries(bbruntime ${LIBS})
