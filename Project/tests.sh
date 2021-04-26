#!/bin/bash

echo "Checking file abc.txt."
expec="$(sha512sum abc.txt)"
myout="$(./sha512 abc.txt)  abc.txt"
echo "Expected: " $expec
echo "Output:   " $myout
if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi

echo "Checking file input.txt."
expec="$(sha512sum input.txt)"
myout="$(./sha512 input.txt)  input.txt"
echo "Expected: " $expec
echo "Output:   " $myout
if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi