#!/bin/bash

while [ true ]
do
    echo "----MENU----"
    echo "1 HOME DIRECTORY"
    echo "2 BASH VERSION"
    echo "3 HOST NAME"
    echo "4 CURRENT DIRECTORY"
    echo "5 EXIT"
    echo ""
    echo "SELECT AN OPTION"
    read c
    case $c in
        1) echo $HOME;;
        2) echo $BASH_VERSION;;
        3) echo $HOSTNAME;;
        4) echo `pwd`;;
        *) exit 0;;
    esac
done