#!/usr/bin/env bash

if [ -z $1 ]
then
    echo "This script expects an input file as first argument"
fi
out=$2
# Strip out all punctuation then get the words into tokensthen piped to sort and then count unique words
cat $1 | sed -e 's/\([[:punct:]]\)//g' | sed 's/\.//g;s/\(.*\)/\L\1/;s/\ /\n/g' | sort | uniq -c | tr -d $'\r' > "$out"
