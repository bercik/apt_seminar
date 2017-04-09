#!/bin/bash

if [ "$#" -lt 1 ]; then
   echo "Usage: $0 test_file.cpp [arguments_to_gtest]"
   exit -1
fi

test_file_path=$1

# for gtest only use -lgtest instead of -lgmock
# usage of both would lead to double free or corruption error when using 
# flags in gmock
g++ -std=c++1y -Wall $test_file_path -lgmock -pthread \
    && ./a.out "${@:2}"
