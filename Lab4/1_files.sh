#!/bin/bash

# Check whether exactly 3 arguments are provided
if [ $# -ne 3 ]
then
    echo "Usage: $0 file1 file2 output_file"
    exit 1
fi

# Assign command line arguments to variables
file1=$1
file2=$2
outfile=$3

# Check if input files exist
if [ ! -f "$file1" ] || [ ! -f "$file2" ]
then
    echo "One or both input files do not exist"
    exit 1
fi

# Clear the output file if it already exists
> "$outfile"

# Open file descriptors for both files
exec 3< "$file1"
exec 4< "$file2"

# Read both files line by line using a loop
while true
do
    read -r line1 <&3
    status1=$?

    read -r line2 <&4
    status2=$?

    # If both files have reached EOF, break the loop
    if [ $status1 -ne 0 ] && [ $status2 -ne 0 ]
    then
        break
    fi

    # Handle missing lines in shorter file
    if [ $status1 -ne 0 ]
    then
        line1=""
    fi

    if [ $status2 -ne 0 ]
    then
        line2=""
    fi

    # Concatenate lines and write to output file
    echo "$line1$line2" >> "$outfile"
done

# Close file descriptors
exec 3<&-
exec 4<&-

echo "Line-by-line concatenation completed successfully."
