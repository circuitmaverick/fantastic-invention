#!/bin/bash
for ((x=1; x<=100; x++))
do
    flag=0
    for ((i=2; i<=x/2; i++))
    do
        if [ $((x%i)) -eq 0 ]
        then
            flag=1
            break
        fi
    done
    if [ $((flag)) -eq 0 ]
    then
        echo $x
    fi
done