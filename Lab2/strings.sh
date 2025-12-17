#!/bin/bash

echo "Enter a string"
read s1
echo "Enter another string"
read s2
if [ "$s1" = "$s2" ]
then
    echo "Same"
else
    echo "Different"
fi
