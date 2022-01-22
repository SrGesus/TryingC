#include <stdio.h>
#include <unistd.h>

long int seconds;
int hh,mm,ss;

void displayTime() {		//self explanatory, displays time in hh mm ss
	hh = seconds / 3600;
	mm = seconds / 60;
	ss = seconds;

	while (mm>59) {
		mm-=60;
	}

	while (ss>59) {
		ss-=60;
	}
	
	printf("\t%d : %02d : %02d\n       ", hh, mm, ss);
}

void promptTime() {			//will ask user for hours minutes and seconds
	printf("\t   :    :    \r\t");
	scanf("%d", &hh);
	printf("\033[A\t%d : ", hh);
	scanf("%d", &mm);
	printf("\033[A\t%d : %02d : ", hh, mm);
	scanf("%d", &ss);
	printf("\033[A");

	seconds = 3600 * hh + 60 * mm + ss;
}


int main(){
	printf("\nTimer\n\n");
	promptTime();
	
	if (seconds <= 0) {
		printf("Error: Only enter numbers that result in between 1 and 9 223 372 036 854 775 807 seconds\n");
		return 1;
	}
	
	for (;seconds >= 0; --seconds) {		//Increment -1 second every second
		displayTime();				
		sleep(1);					//Wait one second
		printf("\033[A\33[K");		//Cleans the line above

		if (seconds == 0) {
			printf("\tTime's up!\n");
	return 0;
		}
	}

}

