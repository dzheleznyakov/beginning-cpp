#!/bin/bash

if [[ ( $# -lt 1 ) ]] 
then
   echo "Usage: start.sh <cpp-14-file> [-c][-co]"
   exit 0
fi

if [[ ($# -eq 1 && $1 == "--help") ]]
then
    echo ""
    echo "Usage: ./start.sh [--help | [<cpp-14-file-1> <cpp-14-file-2> ...] [-c][-co][-all][--args arg1 arg2 ...]]"
    echo ""
    echo "Commands:"
    echo "  --help                  Print out help info"
    echo "  --args [arg1 arg2 ...]  Declares arguments that shall be passed into the compiled program. Should always be the last."
    echo ""
    echo "Flags:"
    echo "  -c     Compile and run the <cpp-14-file>"
    echo "  -co    Compile the <cpp-14-file>"
    echo "  -all   Compile/run/etc all the files in the same directory as <cpp-14-file>, which is the main file"
    echo ""
    echo "No flags: run the already compiled version of the <cpp-14-file>"
    echo ""
    exit 0
fi

args_remain=false
filepaths=""
filename=""
first_filepath=""
for var in "$@"
do
    if [ $args_remain == true ]
    then
        break
    fi
    if [ $var == "--args" ]
    then
        args_remain=true
    elif [[ "$var" == -* ]]
    then
        continue
    else
        filepath=$var
        filepaths="${filepaths} $filepath"
        if [ "$first_filepath" == "" ]
        then
            first_filepath=$filepath
        fi
        if [ "$filename" == "" ]
        then
            delim="/"
            filename=${filepath##*$delim}
            delim="."
            filename=${filename%%$delim*}
        fi
    fi
done

should_compile=false
should_run=true
compile_all_in_directory=false
args_remain=false
args=""

for var in "$@"
do
    if [ $args_remain == true ]
    then
        args="$args \"$var\""
        continue
    fi
    if [ $var == "-c" ]
    then
        should_compile=true
    fi
    if [ $var == "-co" ]
    then
        should_compile=true
        should_run=false
    fi
    if [ $var == "-all" ]
    then
        compile_all_in_directory=true
    fi
    if [ $var == "--args" ]
    then
        args_remain=true
    fi
done

prepare_to_compile_all_in_directory() {
    dir="$(dirname "$first_filepath")"
    filepaths=$first_filepath

    for entry in "$dir"/*.cpp
    do
        if [ $entry != $first_filepath ]
        then
            filepaths="${filepaths} $entry"
        fi
    done
}

compile() {
    eval "g++ $filepaths -std=c++14 -o data/$filename"
    echo "File $first_filepath has been compiled"
    echo "" 
}

run() {
    eval "./data/$filename$args"
}

if [ $compile_all_in_directory == true ] 
then
    prepare_to_compile_all_in_directory
fi

if [ $should_compile == true ]
then
    compile
fi

if [ $should_run == true ]
then
    run
fi
