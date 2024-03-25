#!/usr/bin/env bash

gcc -c -g -o hotreload.o -I./include/ hotreload.c -fPIC
gcc --shared -o ./lib/libhotreload.so hotreload.o
