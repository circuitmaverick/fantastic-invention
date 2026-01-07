#!/bin/bash

counts=0
for file in `ls`
do
    if [ "`echo $file | cut -d'.' -f2`" = "sh" ]
    then
        counts=$((counts+1))
    fi
done
echo $counts