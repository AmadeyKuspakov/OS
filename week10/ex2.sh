#!/bin/sh
mkdir -m777 week01
mkdir -m777 week10
echo "Greetings from file.txt" > week01/file.txt
ln week01/file.txt week10/_ex2.txt
i=$(stat -c %i week10/_ex2.txt)
find . -inum "$i" -exec rm {} \;
