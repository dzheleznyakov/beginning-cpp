#!/bin/bash

if [[ ( $# -lt 1 || $# -gt 2 ) ]] 
then
   echo "Usage: start.sh <cpp-14-file> [-c][-co]"
   exit 0
fi

filepath=$1
delim="/"
filename=${filepath##*$delim}
delim="."
filename=${filename%%$delim*}

if [[ ( $# -eq 2 && ( $2 -eq "-c" || $2 == "-co" ) ) ]]
then
    eval "g++ $filepath -std=c++14 -o data/$filename"
    echo "File $filepath has been compiled"
    echo ""
fi

if [[ ($# -lt 2 || $2 != "-co") ]]
then
    eval "./data/$filename"
fi
