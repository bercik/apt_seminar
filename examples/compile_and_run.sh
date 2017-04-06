#!/bin/bash

if [ "$#" -lt 1 ]; then
   echo "Usage: $0 test_file.cpp [arguments_to_gtest]"
   exit -1
fi

test_file_path=$1

g++ -std=c++1y -Wall $test_file_path -lgtest -pthread && ./a.out "${@:2}"
