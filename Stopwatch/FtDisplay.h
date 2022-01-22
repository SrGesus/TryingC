#include <stdio.h>

int mm, ss;

//this will be a mm : ss display
void displayTime (int secs) {	//function takes seconds as a parameter and will display it simply mm : ss
	mm = secs / 60;
	ss = secs;
	
	while (ss>59) {			//so seconds is always lower than 60
		ss -= 60;
	}	
	printf("%02d  : %02d\n", mm, ss);	//newline is necessary or else this will only print AFTER sleep()
}



