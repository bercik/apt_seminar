#!/bin/bash

if [ "$#" -lt 1 ]; then
   echo "Usage: $0 folder_with_test.cpp [arguments_to_gtest]"
   exit -1
fi

folder_with_test=$1

# for gtest only use -lgtest instead of -lgmock
# usage of both would lead to double free or corruption error when using 
# flags in gmock
g++ -std=c++1y -Wall $folder_with_test/test.cpp -lgmock -pthread \
    && ./a.out "${@:2}"
