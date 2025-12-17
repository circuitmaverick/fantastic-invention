#!/bin/bash
echo "enter value for x:"
read x
echo "enter value for y:"
read y
echo "enter value for z:"
read z
if [ $x -gt $y -a $x -gt $z ]
then
    echo "$x is greatest"
elif [ $y -gt $z ]
then
    echo "$y is greatest"
else
    echo "$z is greatest"
fi