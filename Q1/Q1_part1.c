/* Name: Harshit Singh
   Roll_Number: 2019424 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

	int var = 10;
	pid_t pid = fork();

	if (pid < 0){
		printf("Unable to create child process.\n");
		return 1;
	}
	else if (pid == 0){
		printf("In Child Process - \n\n");
		
		while (var > -90){
			var--;
			printf("Value -> %d\n", var);
		}

		printf("Value after Child Process completed -> %d\n\n", var);
		exit(0);
	}

	else{
		wait(0);
		printf("In Parent Process - \n\n");
		
		while(var < 100){
			var++;
			printf("Value -> %d\n", var);
		}

		printf("Value after Parent Process completed -> %d\n\n", var);
	}
	return 0;
}
