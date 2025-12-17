#!/bin/bash

echo "Enter a character:"
read c
case $c in
    a) echo "Vowel!";;
    A) echo "Vowel!";;
    e) echo "Vowel!";;
    E) echo "Vowel!";;
    i) echo "Vowel!";;
    I) echo "Vowel!";;
    o) echo "Vowel!";;
    O) echo "Vowel!";;
    u) echo "Vowel!";;
    U) echo "Vowel!";;
    *) echo "Consonant";;
esac