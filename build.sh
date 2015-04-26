#!/bin/bash

rm -rf build
mkdir build
cd build

if [ "$(uname)" == "Darwin" ]; then
	cmake .. -DCMAKE_CXX_COMPILER=/usr/local/bin/g++ -DCMAKE_CC_COMPILER=/usr/local/bin/gcc
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
	cmake .. -DCMAKE_CXX_COMPILER=g++-4.9 -DCMAKE_CC_COMPILER=gcc-4.9
fi

make
cp src/GameOfLife ../bin/
cp test/GameOfLifeTest ../bin/
