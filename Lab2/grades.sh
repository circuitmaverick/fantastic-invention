#!/bin/bash
echo "Enter the marks:"
read marks
# echo  
case $((marks/10)) in
    10) echo O ;;
    9) echo O ;;
    8) echo E ;;
    7) echo A ;;
    6) echo B ;;
    5) echo C ;;
    *) echo F ;;
esac