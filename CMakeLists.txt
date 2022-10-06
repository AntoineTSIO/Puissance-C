cmake_minimum_required(VERSION 3.23)
project(Puissance_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Puissance_C main.c intialisation/config.c regles.c methods.c methodes/methodes.c structures.c)
