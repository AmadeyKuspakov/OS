#!/bin/sh
mkdir -m777 tmp
echo "file1.txt" > tmp/file1.txt
echo "file2.txt" > tmp/file2.txt
ln tmp/file1.txt tmp/link1.txt
ln tmp/file1.txt tmp/link2.txt
