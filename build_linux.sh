#!/bin/sh
mkdir -p build

cmake -Bbuild -H.

cd build/

make

strip -s ffaudioconverter
