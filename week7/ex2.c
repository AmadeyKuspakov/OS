#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int n, i;
	scanf("%d", &n);
	printf("\n");
	int *array = (int *)calloc(n, sizeof(int));
	for(i = 0; i<n; i++){
		array[i]=i;
		printf("%d \n", array[i]);
	}
	free(array);
	return 0;
}
