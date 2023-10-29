#=============================================================================
# Makefile for MSVC
#
# This file expects an environment variable called SDL2_HOME to be defined.
# It should have the following structure:
# SDL2_home/
# |-- include/
# |   |-- SDL2/
# |       |-- header files
# |  
# |-- lib/
#     |-- SDL2main.lib
#         SDL2.lib
#         SDL2_image.lib
#         SDL2_ttf.lib
#         SDL2_mixer.lib
#         SDL2.dll
#         SDL2_image.dll
#         SDL2_ttf.dll
#         SDL2_mixer.dll
#=============================================================================

CC=cl

# The include and lib directories must exist in the SDL2_HOME directory.
INCLUDE_DIR=/I$(SDL2_HOME)\include /I..\.. /I..\..\..
LINK_DIR=/LIBPATH:"$(SDL2_HOME)\lib" /LIBPATH:"."

SRC=..\..\..\impl\*.c
LIBS="SDL2.lib" "SDL2main.lib" "SDL2_ttf.lib" "SDL2_image.lib" "SDL2_mixer.lib" "kernel32.lib" "user32.lib" "shell32.lib"

DEBUG_CFLAGS=/JMC /permissive- /ifcOutput "./" /GS /W3 /Zc:wchar_t /ZI /Gm- /Od /sdl /Fd"vc143.pdb" /Zc:inline /fp:precise /D "_DEBUG" /D "CRUMBS_EXPORTS" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /LDd /FC /EHsc /nologo /Fo"./" /Fp"x64\Debug\crumbs.pch" /diagnostics:column 
DEBUG_LFLAGS=/OUT:"crumbs.dll" /MANIFEST /NXCOMPAT /PDB:"crumbs.pdb" /DYNAMICBASE $(LIBS) /IMPLIB:"crumbs.lib" /DEBUG /DLL /MACHINE:X64 /INCREMENTAL /SUBSYSTEM:WINDOWS /MANIFESTUAC:NO /ManifestFile:"crumbs.dll.intermediate.manifest" /LTCGOUT:"crumbs.iobj" /ERRORREPORT:PROMPT /ILK:"crumbs.ilk" /NOLOGO /TLBID:1 

CFLAGS=/permissive- /ifcOutput "./" /GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /sdl /Zc:inline /fp:precise /D "NDEBUG" /D "CRUMBS_EXPORTS" /D "_WINDOWS" /D "_USRDLL" /D "_WINDLL" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /Gd /Oi /LD /FC /EHsc /nologo /Fo"./" /diagnostics:column 
LFLAGS=/OUT:"crumbs.dll" /LTCG:incremental /NXCOMPAT /DYNAMICBASE $(LIBS) /IMPLIB:"crumbs.lib" /DEBUG /DLL /MACHINE:X64 /OPT:REF /SUBSYSTEM:WINDOWS /OPT:ICF /ERRORREPORT:PROMPT /NOLOGO /TLBID:1

release:
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(SRC) /link $(LINK_DIR) $(LFLAGS)
	del *.obj
	del crumbs.iobj
	del crumbs.ipdb
	del *.pdb
	del crumbs.exp

clean:
	del *.obj

debug:
	$(CC) $(DEBUG_CFLAGS) $(INCLUDE_DIR) $(SRC) /link $(LINK_DIR) $(DEBUG_LFLAGS)


all: release
