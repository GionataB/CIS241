#! /bin/bash
if test $# -lt 2
  then
    echo “must provide at least one argument”
    exit 1
fi
target="~/backup"
diskUsage="-c"
listContent="-l"
askHelp="--help"
if test -e "$target"
  then
  else
    mkdir "$target"
fi
for i in $#
  if test -e "$i"
    then
      cp -r "$i" "$target"
  elif test "$i" = "$diskUsage"
    then
      echo "There are $(ls | wc -w) files and directories in the backup folder."
      echo "The backup folder occupies $(du -b $target) bytes." #might want to put quotes around $target
  elif test "$i" = "$listContent"
    then
      ls "$target"
  elif test "$i" = "$askHelp"
    then
      echo "Syntax: ./backup targetFileList [options]\ntargetFileList is one or more file to copy\nAvailable options are:\n-c to get the number of files and directories inside the backup directory, and the total size in bytes.\n-l to list all files and directories in the backup directory.\n--help to display this message."
  else
    echo "$i does not exist!"
  fi
