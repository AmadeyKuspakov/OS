#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#define TRUE 1
int main(){
	int status;
	printf("Beginning\n");
	while(TRUE){
		char command[256];
		printf("Before scanf\n");
		scanf("%s", &command[0]);
		printf("After scanf and before fork and the command is %s\n", command);
		int n = fork();
		printf("Somewhere in the middle\n");
		if(n!=0){
			waitpid(-1, &status, 0);
		}else{
			system(command);
		}
	}
	printf("end\n");
	return 0;
}
