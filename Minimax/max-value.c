//function to determine the max minmax value of a state
#include "include.h"

int max-value(short state[9]) {
	//verify if state is terminal and return utility
	short utility = terminal(state);
	//the way i've done it the terminal function returns 2 if it's not a terminal state, but utility if it is.
	//utility will be either, -1, 0, or 1
	if (utility != 2) {
		return utility;
	}

	//Let's create a variable to be returned to store value, this can be -2 because utility is always -1 or greater
	short value = -2;

	//for each blank space 
	for(int i = 0; i < 9; i++) {
		if (state[i] == 32) {
			//These are the spaces that the Max(AI) player can potentially play
			//Now we want to choose the space that leads to the maximum minimax value 
			
			//Let's create a temporary copy of the state array to be able to modify it
			short potentialstate[9];
			strncpy (potentialstate, state, 9); //the syntax of strncpy is (destination, source, number of characters)
			
			//now change the blank space to the AI player, giving us a potential state
			potentialstate[i] = 1;

			//now to get the maximum we will create a temporary value 
			short tempvalue = min-value(potentialstate);

			if (value < tempvalue) {
				value = tempvalue;	
			}			
		}
	}
	return value;
}
