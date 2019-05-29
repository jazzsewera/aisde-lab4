#!/bin/bash

tests="0 1 6 8"

for N in $(echo $tests)
do
  sed -i -e "s/^#define VARIANT [0-9]*/#define VARIANT $N/g" src/sources/main.cpp
  make clean; make -j 4
  ./kolejka
done
