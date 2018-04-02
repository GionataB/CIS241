#! /bin/bash
if test $# -ne 1
  then
    echo "must provide an argument"
    exit 1
fi
target=~/backup
diskUsage="-c"
listContent="-l"
askHelp="--help"
if test -ne "$target"
  then
    mkdir "$target"
fi
if test "$1" = "$diskUsage"
  then
    echo "There are $(ls | wc -w) files and directories in the current path, $(pwd)."
    echo "The files and directories in the current path occupy $(du -s -b ".." | cut -f 1) bytes."
elif test "$1" = "$listContent" #the variables should be string, but maybe wrap the two variables in quotiation marks
  then
    ls
elif test "$1" = "$askHelp"
  then
    echo -e "Syntax: ./test.sh [options]\nUsage:\t-c to get the number of files and directories inside the current path, and the total size in bytes.\n\t-l to list all files and directories in the current path.\n\t--help to display this message."
  else
    echo "$1 does not exist!"
fi
