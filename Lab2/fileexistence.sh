#!/bin/bash

echo "Enter filename:"
read file
if [ -f $file ] # -f flag checks the existence of the file itself
then
    echo "File exists!"
else
    echo "File doesn't exist!"
fi