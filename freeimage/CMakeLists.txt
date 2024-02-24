cmake_minimum_required(VERSION 3.16)

project(freeimage)

add_library(freeimage

        FreeImage.h
        FreeImageIO.h
        Plugin.h
        Quantizers.h
        Utilities.h

        FreeImage/BitmapAccess.cpp
        FreeImage/Conversion.cpp
        FreeImage/Conversion16_555.cpp
        FreeImage/Conversion16_565.cpp
        FreeImage/Conversion24.cpp
        FreeImage/Conversion32.cpp
        FreeImage/Conversion8.cpp
        FreeImage/FreeImage.cpp
        FreeImage/FreeImageIO.cpp
        FreeImage/GetType.cpp
        FreeImage/LoadFunctions.cpp
        FreeImage/NNQuantizer.cpp
        FreeImage/Plugin.cpp
        FreeImage/PluginBMP.cpp
        FreeImage/PluginICO.cpp
        FreeImage/PluginIFF.cpp
        FreeImage/PluginJPEG.cpp
        FreeImage/PluginKOALA.cpp
        FreeImage/PluginMNG.cpp
        FreeImage/PluginPCD.cpp
        FreeImage/PluginPCX.cpp
        FreeImage/PluginPNG.cpp
        FreeImage/PluginPNM.cpp
        FreeImage/PluginPSD.cpp
        FreeImage/PluginRAS.cpp
        FreeImage/PluginTARGA.cpp
        FreeImage/PluginTIFF.cpp
        FreeImage/PluginWBMP.cpp
        FreeImage/WuQuantizer.cpp

        LibJPEG/jcapimin.c
        LibJPEG/jcapistd.c
        LibJPEG/jccoefct.c
        LibJPEG/jccolor.c
        LibJPEG/jcdctmgr.c
        LibJPEG/jchuff.c
        LibJPEG/jcinit.c
        LibJPEG/jcmainct.c
        LibJPEG/jcmarker.c
        LibJPEG/jcmaster.c
        LibJPEG/jcomapi.c
        LibJPEG/jcparam.c
        LibJPEG/jcphuff.c
        LibJPEG/jcprepct.c
        LibJPEG/jcsample.c
        LibJPEG/jctrans.c
        LibJPEG/jdapimin.c
        LibJPEG/jdapistd.c
        LibJPEG/jdatadst.c
        LibJPEG/jdatasrc.c
        LibJPEG/jdcoefct.c
        LibJPEG/jdcolor.c
        LibJPEG/jddctmgr.c
        LibJPEG/jdhuff.c
        LibJPEG/jdinput.c
        LibJPEG/jdmainct.c
        LibJPEG/jdmarker.c
        LibJPEG/jdmaster.c
        LibJPEG/jdmerge.c
        LibJPEG/jdphuff.c
        LibJPEG/jdpostct.c
        LibJPEG/jdsample.c
        LibJPEG/jdtrans.c
        LibJPEG/jerror.c
        LibJPEG/jfdctflt.c
        LibJPEG/jfdctfst.c
        LibJPEG/jfdctint.c
        LibJPEG/jidctflt.c
        LibJPEG/jidctfst.c
        LibJPEG/jidctint.c
        LibJPEG/jidctred.c
        LibJPEG/jmemmgr.c
        LibJPEG/jmemnobs.c
        LibJPEG/jquant1.c
        LibJPEG/jquant2.c
        LibJPEG/jutils.c

        LibPNG/png.c
        LibPNG/pngerror.c
        LibPNG/pnggccrd.c
        LibPNG/pngget.c
        LibPNG/pngmem.c
        LibPNG/pngpread.c
        LibPNG/pngread.c
        LibPNG/pngrio.c
        LibPNG/pngrtran.c
        LibPNG/pngrutil.c
        LibPNG/pngset.c
        LibPNG/pngtest.c
        LibPNG/pngtrans.c
        LibPNG/pngvcrd.c
        LibPNG/pngwio.c
        LibPNG/pngwrite.c
        LibPNG/pngwtran.c
        LibPNG/pngwutil.c

        ZLib/adler32.c
        ZLib/compress.c
        ZLib/crc32.c
        ZLib/deflate.c
        ZLib/gzio.c
        ZLib/infblock.c
        ZLib/infcodes.c
        ZLib/inffast.c
        ZLib/inflate.c
        ZLib/inftrees.c
        ZLib/infutil.c
        ZLib/trees.c
        ZLib/uncompr.c
        ZLib/zutil.c
)
target_compile_options(freeimage PRIVATE /Gd)

target_compile_definitions(freeimage PRIVATE FREEIMAGE_LIB=1 _LIB=1)

target_include_directories(freeimage PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
