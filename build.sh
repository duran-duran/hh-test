#!/bin/bash

TASK=$1
SRC=src/${TASK}.cpp
SHARED=src/shared.cpp
EXE=build/${TASK}

if [ -f $SRC ]
then
    g++ --std=c++11 $SRC $SHARED -o $EXE
else
    echo "$SRC: no such file"
fi
