#!/bin/bash

FILES="array vector deque forward_list list stack queue set map unordered_set unordered_map"

for name in $FILES
do
    touch $name"Test.h" $name"Test.cpp"
done

