#!/bin/bash

while true
do
    echo "-----MENU-----"
    echo "1) Display current directory"
    echo "2) List directories"
    echo "3) Create directory"
    echo "4) Copy a file"
    echo "5) Exit"
    echo ""
    echo "Enter your choice"
    read c
    case $c in
        1)  echo "$(pwd)";;
        2)  echo "$(ls)";;
        3)  echo "Enter the directory name"
            read dir
            `mkdir $dir`
            ;;
        4)  echo "Enter filename"
            read file
            `cp $file $file-copied`
            ;;
        5)  exit 0;;
    esac
done