#!/bin/bash

if [[ ( $# -lt 1 || $# -gt 2 ) ]] 
then
   echo "Usage: start.sh <cpp-14-file> [-c][-co]"
   exit 0
fi

if [[ ($# -eq 1 && $1 == "--help") ]]
then
    echo ""
    echo "Usage: ./start.sh [--help | <cpp-14-file> [-c][-co]]"
    echo ""
    echo "Commands:"
    echo "  --help    Print out help info"
    echo ""
    echo "Flags:"
    echo "  -c     Compile and run the <cpp-14-file>"
    echo "  -co    Compile the <cpp-14-file>"
    echo ""
    echo "No flags: run the already compiled version of the <cpp-14-file>"
    echo ""
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
