//function to determine the max minmax value of a state
#include "include.h"

int maxvalue(short state[9]) {
	//verify if state is terminal and return utility
	short  utility = terminal(state);
	//the way i've done it the terminal function returns 2 if it's not a terminal state, but utility if it is.
	//utility will be either, -1, 0, or 1
	if (utility != 2) {
		return utility;
	}

	//the lowest utility is -1 so we can set this variable to -2
	short max = -2;

	for(int i = 0; i < 9; i++) {
		if (state[i] == 32) {
			//These are the spaces that the Max(AI) player can potentially play
			//Now we want to choose the space that leads to the maximum minimax value 
			
			short potentialstate[9];
			memcpy (potentialstate, state, 18); //the syntax of memcpy is (destination, source, number of bytes) and in this caz the array is 18 bytes long, shorts are 2 bytes, times 9 18
			
			//now change the blank space to the AI player, giving us a potential state
			potentialstate[i] = 1;
			//now to get the maximum we will create a temporary value 
			short value = minvalue(potentialstate);

			if (max < value) {
				max = value;
			}			
		}
	}
	return max;
}
