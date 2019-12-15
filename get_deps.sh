#!/bin/bash
mkdir -p extern

pushd extern
    git clone https://github.com/DGtal-team/DGtal
        pushd DGtal
            cmake -B build -GNinja
            pushd build
                ninja
            popd
    popd
popd
