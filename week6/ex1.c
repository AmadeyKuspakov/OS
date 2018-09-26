#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#define MSGSIZE 16
char *string1 = "text";
char *string2 = "";
int main(){
	char buf[MSGSIZE];
	int p[2];
	if(pipe(p)<0){
		exit(1);
	}
	write(p[1], string1, MSGSIZE);
	read(p[0], buf, MSGSIZE);
	string2 = &buf[0];
	printf("%s \n", string2);
	return 0;
}
