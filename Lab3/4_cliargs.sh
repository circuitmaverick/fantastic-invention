#!/bin/bash

if [ $# -lt 2 ] || [ $# -gt 8 ]; then
    echo "Usage: $0 num1 num2 [num3 ... num8]"
    exit 1
fi

result=$1
shift

for b in "$@"
do
    a=$result

    if [ $((a % b)) -eq 0 ]; then
        result=$((a / b))

    elif [ $((a % b)) -ne 0 ] && [ $((b % 5)) -eq 0 ]; then
        result=$((a * b))

    elif [ $a -gt $b ]; then
        result=$((a - b))

    else
        result=$((a + b))
    fi
done

echo "Final Result: $result"
