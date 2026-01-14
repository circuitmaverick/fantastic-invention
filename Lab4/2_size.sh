#!/bin/bash

X=$1
dir_no=1
current_size=0

files=(*)

mkdir x_$dir_no

for file in "${files[@]}"
do
    if [ -f "$file" ]; then
        size=$(du -b "$file" | cut -f1) #changed -k flag to -b to use bytes as the size units

        if [ $((current_size + size)) -gt $X ]; then
            dir_no=$((dir_no + 1))
            mkdir x_$dir_no
            current_size=0
        fi

        mv "$file" x_$dir_no
        current_size=$((current_size + size))
    fi
done
