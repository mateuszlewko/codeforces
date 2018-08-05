#!/bin/bash

if [ "$1" == "" ]; then
    echo "Provide contest id."
    exit 1
fi

mkdir $1
cd $1
cf con $1
cp ../../../contest-reference/template.cpp a.cpp
code .

