//main stopwatch c source code file
#include <stdio.h>
#include <unistd.h>		//required for sleep()
#include <sys/types.h>	//required for fork()
#include <signal.h>

//my headers
#include "FtDisplay.h"

int dig;

int main() {
	printf("Stopwatch:\n\n\n");
	
	for (int i=1; fork() == 0; i++) {		//for loop that will create a child process and the child process will run it
		printf("\033[A\33[K\r\t");	//cleans line above 
		displayTime(i);				//defined in FtDisplay.h
		sleep(1);
	}

	scanf("%d", &dig);
	printf("%d", dig);
	return 0;
}
