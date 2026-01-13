#!/bin/bash

echo "Enter filename:"
read file

if [ -f $file ]
then
    echo `rev file.csv | cut -d',' -f1 | rev`
else
    echo "File doesn't exist!"
fi