#include<stdio.h>
#include<unistd.h>
#include<signal.h>

#define TRUE 1
#define FALSE !TRUE

static int isRunning = TRUE;

void handler(int sig){
	write(STDOUT_FILENO, "This is signal: %d\n", sig);
	if(sig == SIGTERM)
		isRunning = FALSE;
}

int main(){
	int pid = fork();
	if(pid != 0){
		sleep(10);
		kill(pid, SIGTERM);
	}else{
		signal(SIGTERM, handler);
		while(isRunning){
			sleep(1);
			write(STDOUT_FILENO, "I am alive!\n", 25);
		}
	}
	return 0;
}

