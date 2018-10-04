#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<memory.h>
void *my_realloc(void *pntr, int size){
	void *my_pointer = malloc(size*sizeof(pntr));
	if(!my_pointer){
		exit(1);
	}
	memcpy(my_pointer, pntr, size);
	free(pntr);
	return my_pointer;
}

int main(){
	int* pntr = malloc(3*sizeof(int));
	pntr[0] = 1;
	pntr[1] = 2;
	pntr[2] = 3;
	pntr = my_realloc(pntr, 5*sizeof(int));
	int i;
	for(i = 0; i<5; i++){
		printf("This is number: %d\n", pntr[i]);
	}
	return 0;
}
