#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

char *dirName = "tmp";
char *outputFileName = "tmp/outputForLinuxCommand.txt";
FILE *fp;

DIR* customDirectoryOpenning(char *name){
	DIR *dir = opendir(name);
	if(dir == NULL){
		printf("An error occured during openning of file");
		exit(1);
	}
	return dir;
}

void customDirectoryClosing(DIR *dir){
	if(dir == NULL){
		printf("An error occured during closing of file");
		exit(1);
	}
	closedir(dir);
}

void printOutputOfSystemCommand(){
	char var[40];
	print(outputFileName);
}

void printOnTwoOrMoreLinks(char *fileName, struct stat buffer){
	if(buffer.st_nlink > 1){
		char linux_command[70];
		printf("%s has following files hard linked to itself: ", fileName);
		sprintf(&linux_command, "find -inum %d >> %s", buffer.st_ino, outputFileName);
		system(linux_command);
		printOutputOfSystemCommand();
		printf("\n");
	}
}

void traceAllFilesInDirectory(DIR *dir){
	struct stat buffer;
	struct dirent *dirent;
	while((dirent = readdir(dir))!=NULL){
		//stat() function reads file by name that is provided and writes contents of it in buffer variable
		char fileLocation[70];
		sprintf(&fileLocation, "%s/%s", dirName, dirent->d_name);
		stat(fileLocation, &buffer);
		printOnTwoOrMoreLinks(dirent->d_name, buffer);
	}
}

int main(){
	DIR *dir = customDirectoryOpenning(dirName);
	traceAllFilesInDirectory(dir);
	customDirectoryClosing(dir);
	return 0;
}
