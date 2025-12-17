#!/bin/bash
echo "Enter the marks:"
read marks
# grade=""
case $((marks/10)) in
    10) grade="O";;
    9) grade="O";;
    8) grade="E";;
    7) grade="A";;
    6) grade="B";;
    5) grade="C";;
    *) grade="F";;
esac
echo $grade