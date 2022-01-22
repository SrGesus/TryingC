#include <stdio.h>
#include <unistd.h>

int seconds;
int hh,mm,ss;

void displayTime() {
	hh = seconds / 3600;
	mm = seconds / 60;
	ss = seconds;

	while (mm>59) {
		mm-=60;
	}

	while (ss>59) {
		ss-=60;
	}
	
	printf("\t%02d : %02d : %02d\n", hh, mm, ss);
}



int main(){
	printf("\nTimer\n\n");
	printf("How many seconds shall we wait?\n");
	scanf("%d", &seconds);								//Ask user for input, int
	printf("\r\033[A\33[K\r\033[A\33[K\r\033[A\33[K\n");//Cleans 3 lines counting with the current
	
	if (seconds <= 0) {			//When a letter is entered it usually turns into a 0 apparently, so also a way to avoid this
		printf("Error: Please choose a number from 1 to 4 294 967 296\n");
		return 1;
	}
	
	for (;seconds >= 0; --seconds) {		//Increment -1 second every second
		displayTime();				
		sleep(1);					//Wait one second
		printf("\033[A\33[K");		//Cleans the line above

		if (seconds == 0) {			//When Time runs out
			printf("\tTime's up!\n");
		}
	}

}





