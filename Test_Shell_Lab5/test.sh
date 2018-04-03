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
#First Task
if test "$1" = "$diskUsage"
  then
    echo "The number of files"
    echo "How many bytes"
elif test "$1" = "$listContent" #the variables should be string, but maybe wrap the two variables in quotiation marks
  then
    echo "List all the files."
elif test "$1" = "$askHelp"
  then
    echo -e "How to run this script."
  else
    echo "$1 does not exist!"
fi
#Second Task
if test -ne "$target"
  then
    mkdir "$target"
fi
#Third Task
echo "There are $(ls | wc -w) files and directories in the current path, $(pwd)."
echo "The files and directories in the current path occupy $(du -s -b ".." | cut -f 1) bytes."
