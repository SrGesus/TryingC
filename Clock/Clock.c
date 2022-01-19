#include <stdio.h>
#include <time.h>
#include <unistd.h> 			//needed for the sleep function

int hours, minutes;				//define hours and minutes variables; it is important for these to be integers
time_t seconds;

int main(){
	printf("\nThe Time is:\n");
	for(;;) {							//for loop with empty statements, results in infinite loop
		seconds = time(NULL);			//define seconds (it's a long int) as seconds elapsed since 1st Jan 1970 UTC

		hours = seconds / 3600;						//calculate hours from seconds; since hours is an int it will floor the value of this division
		minutes = (seconds - hours * 3600) / 60;	//calculate minutes by removing the hours in seconds and then dividing; this will as well be floored
		seconds -= hours * 3600 + minutes * 60;		//remove the hours and minutes from the total seconds

		while (hours > 24){							//since this will give us the hours since 1970, we will subtract so hours is always smaller than 24
			hours-=24;
		}
		while (minutes > 60){						//the same but smaller than 60 instead
			minutes-=60;
		}
		
		printf("%02d : %02d : %02ld\n\033[A", hours, minutes, seconds);			//print the time with the format HH: mm : ss 
																				//use %02d format in order to get 2 digits 	
		sleep(1);			//wait a second so the screen doesn't get covered if i fuck up
	}
}

