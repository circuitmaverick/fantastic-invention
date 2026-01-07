#!/bin/bash
for x in {1..100}
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
    if [ $flag -eq 0 ]
    then
        echo $x
    fi
done