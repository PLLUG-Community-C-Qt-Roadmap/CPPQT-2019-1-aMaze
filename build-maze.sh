#!/bin/zsh
rm ./*.o
rm ./maze-game.exe

g++ bone-generation.cpp -c -o bone-generation.o

g++ map-random.cpp -c -o map-random.o

g++ -o game-map-utils.o -c game-map-utils.cpp

g++ -o maze-game.o -c maze-game.cpp

g++ -o maze-game maze-game.o game-map-utils.o map-random.o bone-generation.o\
	-L. -lncurses-maze-draw -lmazify \
	-D_XOPEN_SOURCE=600 -D_POSIX_C_SOURCE=199506L \
	-IS:/MSYS2_Commander/msys64/mingw64/include/ncursesw \
	-LS:/MSYS2_Commander/msys64/mingw64/lib \
	-lncursesw
