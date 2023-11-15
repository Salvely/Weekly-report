#!/bin/bash
rm -r build
# make a directory called build
mkdir build

# compile the two object files
clang++ -c -std=c++17 -I./include src/subtract.cpp -o build/subtract.o
clang++ -c -std=c++17 -I./include src/sum.cpp -o build/sum.o

# build a library according to the two object files
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# link the library to the main.cpp
clang++ src/main.cpp -std=c++17 -I./include -L ./build -lipb_arithmetic -o main

mv build/*.o results/bin
mv build/*.a results/lib
mv main results/bin