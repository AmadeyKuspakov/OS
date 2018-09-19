#!/bin/bash
file=$(<filewithnumber.txt)
while ! ln $file $file.lock 2>dev>null
do
	sleep 1
done
echo "Sleeping is done"
valueToConcat="1"
file="$file$valueToConcat"
echo $file >'filewithnumber.txt'
rm -f $file.lock
