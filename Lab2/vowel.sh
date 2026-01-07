#!/bin/bash

echo "Enter a character:"
read c
case $c in
    a|A|e|E|i|I|o|O|u|U) echo "Vowel!";;
    *) echo "Consonant";;
esac