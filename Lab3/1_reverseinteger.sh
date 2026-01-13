#!/bin/bash

echo "Enter number"
read n
rev=0
while [ $n -gt 0 ]
do
    rev=`expr rev + n % 10 | bc`
    n=`expr n / 10 | bc`
done
echo $rev