#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 16
char *string1 = "text";
char *string2 = "";
int main(){
	int p[2], pid;
	char buf[MSGSIZE];
	if(pipe(p) < 0){
		exit(1);
	}
	pid = fork();
	if(pid != 0){
		//Parent
		write(p[1], string1, MSGSIZE);
		printf("This is parent.\n");
	}else{
		//Child
		read(p[0], buf, MSGSIZE);
		string2 = &buf[0];
		printf("This is child: %s", string2);
	}
	return 0;
}
