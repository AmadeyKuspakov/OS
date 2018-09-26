#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<wait.h>

int main(){
	int pid1 = fork();
	int pid2, p[2], buf;
	int stat2;
	if(pipe(p) < 0){
		exit(1);
	}
	if(pid1 != 0){
		write(p[1], pid2, 16);
		waitpid(pid2, &stat2, 0);
	}else{
		pid2 = fork();
		if(pid2 != 0){
			printf("Creation of 1st child");
			read(p[0], buf, 16);
			// char to int and put it into buf	
			sleep(2);
			kill(buf, SIGSTOP);	
		}else{
			printf("Creation of 2nd child");
		}
	}
}
