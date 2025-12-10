#!/bin/bash
echo "Enter distance in metres: "
read m
km=$(echo "scale=2; $m / 1000" | bc)
cm=$((m*100))
echo "$km km"
echo "$cm cm"
