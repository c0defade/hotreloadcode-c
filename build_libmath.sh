#!/usr/bin/env bash

mkdir lib
gcc -c -g -o math.o math.c -fPIC
gcc --shared -o ./lib/libmath.so math.o
