#!/bin/sh
echo "Greetings from ex3.txt" > _ex3.txt
chmod 777 _ex3.txt
i=$(ls -li _ex3.txt)
echo "$i"
chmod a-x _ex3.txt
i=$(ls -li _ex3.txt)
echo "$i"
chmod u=rwx,g=rwx _ex3.txt
i=$(ls -li _ex3.txt)
echo "$i"
chmod g=u _ex3.txt
i=$(ls -li _ex3.txt)
echo "$i"
echo "660 means that user and group will be able to read file and write to file, whereas other will not be able to do this; also, all three members will not be able to execute the file"
echo "775 means that user and group will be able to read, write and execute the file, whereas member of others will only be able to read and execute"
echo "777 grants all members access to read, write adn execute the file"
