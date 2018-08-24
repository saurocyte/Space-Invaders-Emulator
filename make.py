from os import system

system('g++ -c -g *.cpp')
system('g++ *.o -o emu.exe -lsfml-graphics -lsfml-system -lsfml-window')
