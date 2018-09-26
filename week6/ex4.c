#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#define TRUE 1
void handler(int sig){
	switch(sig){
		case SIGUSR1:
			write(STDOUT_FILENO, "This is user defined signal 1\n", 70);
			break;
		case SIGKILL:
			write(STDOUT_FILENO, "This is signal to kill which will not work\n", 70);
			break;
		case SIGSTOP:
			write(STDOUT_FILENO, "This is signal to stop which also will not work\n", 70);
			break;
	}
}

int main(){
	signal(SIGUSR1, handler);
	signal(SIGSTOP, handler);
	signal(SIGKILL, handler);
	while(TRUE);
	return 0;
}
