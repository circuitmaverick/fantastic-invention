#!/bin/bash

echo "Enter a number"
read x
if [ $x -le 100 -a $x -ge 1 ]
then
    echo "Number exists between 1 and 100"
else
    echo "Number doesn't exist between 1 and 100"
fi