#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	int n = fork();
	int pid = getpid();
	if(n!=0){
		printf("Hello from parent[%d - %d]\n", pid, n);
	}else{
		printf("Hello from child[%d - %d]\n", pid, n);
	}
	return 0;
}
