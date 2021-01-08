#!/bin/bash

g++ traits.h main.cc -o main --std=c++17

if [ $? == 0 ]
then
  ./main
fi
