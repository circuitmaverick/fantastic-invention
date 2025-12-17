#!/bin/bash

echo "Enter the day number: "
read day
case $((day%7)) in
    0) echo Sunday;;
    1) echo Monday;;
    2) echo Tuesday;;
    3) echo Wednesday;;
    4) echo Thursday;;
    5) echo Friday;;
    6) echo Saturday;;
esac