#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#define TRUE 1
#define SIGINT 2
void sigint_handler(int sig){
	printf("This is signal for Ctrl-C press");
}
int main(){
	signal(SIGINT, handle_sigint);
	while(TRUE){
		printf("Hello world");
		sleep(1);
	}
	return 0;
}
