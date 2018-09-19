#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* print_hello_world(void *tid){
	sleep(2);
	int thread_id = (int)tid;
	printf("Greetings from thread %d\n", thread_id);
	pthread_exit(NULL);
}

int main(){
	int i, status, n;
	scanf("%d", &n);
	if(n>0){
		pthread_t threads[n];
		for(i = 0; i<n; i++){
			status = pthread_create(&threads[i], NULL, print_hello_world, (void *) i);
			if(status){
				printf("ERROR. Something went wrong during creation of a thread %d", i);
				exit(-1);
			}else{
				//pthread_join(threads[i], NULL); // this is used to make all threads run sequentially. Commenting it will allow them to run in parallel.
			}
		}
	pthread_join(threads[n-1], NULL);
	}
	exit(NULL);
}
