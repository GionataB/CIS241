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
mkdir "$target" #The current version on the eos machines makes a directory if it does not already exists.
if test "$0" = "$diskUsage"
  then
    echo "There are $(ls | wc -w) files and directories in the current path, $(pwd)."
    echo "The files and directories in the current path occupy $(du -s -b ".." | cut -f 1) bytes."
elif test "$0" = "$listContent" #the variables should be string, but maybe wrap the two variables in quotiation marks
  then
    ls
elif test "$0" = "$askHelp"
  then
    echo -e "Syntax: ./test.sh [options]\nUsage:\t-c to get the number of files and directories inside the current path, and the total size in bytes.\n\t-l to list all files and directories in the current path.\n\t--help to display this message."
  else
    echo "$0 does not exist!"
fi
