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

script="./data/$filename"
if [[ ( $# -eq 2 && $2 -eq "-c" ) ]]
then
    script="g++ $filepath -std=c++14 -o data/$filename && $script"
fi

eval $script
