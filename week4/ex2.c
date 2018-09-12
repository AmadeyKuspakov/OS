#include<stdio.h>
#include<unistd.h>
int main(){
	int n = 3;
	int i = 0;
	while(i<n){
		fork();
		fork();
		fork();
		fork();
		fork();
		sleep(5);
		i++;
	}
	return 0;
}
