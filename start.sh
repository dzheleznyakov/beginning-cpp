#!/bin/bash

if [[ ( $# -lt 1 || $# -gt 2 ) ]] 
then
   echo "Usage: start.sh <cpp-14-file> [-c]"
   exit 0
fi

filepath=$1
delim="/"
filename=${filepath##*$delim}
delim="."
filename=${filename%%$delim*}

if [[ ( $# -eq 2 && $2 -eq "-c" ) ]]
then
    eval "g++ $filepath -std=c++14 -o data/$filename"
    echo "File $filepath has been compiled"
    echo ""
fi

eval "./data/$filename"
