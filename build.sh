#!/bin/bash
$include=`$(pwd)/include`
$subdir=`$(pwd)/$1`
# Compile include
g++ -c $include/node.cpp -o $include/node.o
# Compile subdir
g++ $subdir/main.cpp -o $subdir/main.out -I $include $include/node.o
# Execute
if [ $? -eq 0 ]; then
    echo "Compilation successful"
    ./$subdir/main.out
 else
    echo "Compilation failed"
fi