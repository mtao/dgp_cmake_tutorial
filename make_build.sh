#!/bin/bash


OPTS="-GNinja"

echo "Making a release-mode build"
mkdir build-release
pushd build-release
cmake .. $OPTS -DCMAKE_BUILD_TYPE=Release
popd

echo "Making a debug-mode build"
mkdir build-debug
pushd build-debug
cmake .. $OPTS -DCMAKE_BUILD_TYPE=Debug
popd
