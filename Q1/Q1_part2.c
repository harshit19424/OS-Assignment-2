/* Name: Harshit Singh
   Roll_Number: 2019424 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int var = 10;


void parentThread(){

	while (var < 100){
		var++;
		printf("Value -> %d\n", var);
	}
	
	printf("Value of variable after parent thread -> %d\n", var);
}

void *childThread(void *arg){

	while (var > -90){
		var--;
		printf("Value -> %d\n", var);
	}
	
	printf("Value of variable after child thread -> %d\n", var);
}

int main(){
	
	pthread_t childthread;
	printf("In Child Thread -> \n");
	pthread_create(&childthread, NULL, &childThread, NULL);
	pthread_join(childthread, NULL);
	printf("Child Thread Completed.\n\n");
	printf("In Parent Thread -> \n");
	parentThread();
	printf("Parent Thread Completed.\n");


	return 0;
}
