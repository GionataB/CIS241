#! /bin/bash
if test $# -lt 1
  then
    echo "must provide at least one argument"
    exit 1
fi
target=~/backup
diskUsage="-c"
listContent="-l"
askHelp="--help"
if test -e "$target"
  then
    echo "The directory already exists, its content may be overwritten."
  else
    mkdir "$target"
fi
for i
do
  if test -e "$i"
    then
      cp -r "$i" "$target"
  elif test "$i" = "$diskUsage"
    then
      echo "There are $(ls | wc -w) files and directories in the backup folder."
      echo "The backup folder occupies $(du -s -b $target | cut -f 1) bytes."
  elif test "$i" = "$listContent" #the variables should be string, but maybe wrap the two variables in quotiation marks
    then
      ls "$target"
  elif test "$i" = "$askHelp"
    then
      echo -e "Syntax: ./backup targetFileList [options]\rtargetFileList is one or more file to copy\rAvailable options are:\r-c to get the number of files and directories inside the backup directory, and the total size in bytes.\r-l to list all files and directories in the backup directory.\r--help to display this message."
  else
    echo "$i does not exist!"
  fi
done
