#!/bin/bash

rm -rf build
mkdir build
cd build
cmake .. -DCMAKE_CXX_COMPILER=/usr/local/bin/g++ -DCMAKE_CC_COMPILER=/usr/local/bin/gcc
make
cp src/GameOfLife ../bin/
cp test/GameOfLifeTest ../bin/
