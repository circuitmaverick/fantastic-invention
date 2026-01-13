#!/bin/bash

echo "Enter a string"
read string
reversed=$(echo "$string" | rev)
if [ "$reversed" = "$string" ]
then
    echo "Palindrome String"
else
    echo "Not palindrom string"
fi