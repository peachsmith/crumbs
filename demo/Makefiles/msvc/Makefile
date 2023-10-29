#=============================================================================
# Makefile for MSVC
#=============================================================================

CC=cl

INCLUDE_DIR=/I$(SDL2_HOME)\include /I..\.. /I..\..\..
LINK_DIR=/LIBPATH:"$(SDL2_HOME)\lib" /LIBPATH:"..\..\..\impl\Makefiles\msvc"

CFLAGS=/W3 /WX
LIBS="SDL2.lib" "SDL2main.lib" "SDL2_ttf.lib" "SDL2_image.lib" "SDL2_mixer.lib" "kernel32.lib" "user32.lib" "shell32.lib"

# This is needed to get access to SDL's main function without having to
# include the SDL header file.
MAIN_DEF=/D"main=SDL_main"

D=..\..
SRC=$(D)\*.c $(D)\common\*.c $(D)\entities\*.c $(D)\input\*.c $(D)\scenes\*.c $(D)\util\*.c

all:
	$(CC) $(CFLAGS) $(MAIN_DEF) $(INCLUDE_DIR) $(SRC) /link $(LIBS) "crumbs.lib" $(LINK_DIR) /SUBSYSTEM:WINDOWS -out:demo.exe
	del *.obj

debug:
	$(CC) /JMC $(CFLAGS) /D"_DEBUG" $(MAIN_DEF) $(INCLUDE_DIR) $(SRC) /link $(LIBS) "crumbs.lib" $(LINK_DIR) /SUBSYSTEM:CONSOLE -out:demo.exe
