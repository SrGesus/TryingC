//function to determine whether inputed state is terminal
//having a separate utility and terminal function would be redundant as it would check the same criteria, thus:
//the function returns the winner: 1 (the AI), -1 (the opponent), 0 (a tie) or 2 (not a terminal state)
//
#include "include.h"

/*

 0 | 1 | 2
-----------
 3 | 4 | 5
-----------
 6 | 7 | 8

*/
int terminal(short state[9]) {
 	//i is the column or row number (from 0 to 2)
	for (int i = 0; i < 3; i++) {
		//check if all spaces in the column are the same but not blank
		if (state[i] == state[i+3] && state[i+3] == state[i+6] && state[i] != 32) {
			return state[i];
		}

		//check if all space in the same row are the same but not blank
		if (state[3*i] == state[3*i+1] && state[3*i+1] == state[3*i+2] && state[3*i] != 32) {
			return state[3*i];
		}
	}

	//check if all the spaces in the diagonals are equal but not blank
	if (state[0] == state[4] && state[4] == state[8] && state[4] != 32) {
		return state[4];
	}
	if (state[2] == state[4] && state[4] == state[6] && state[4] != 32) {
		return state[4];
	}
	
	//check if any of the spaces are blank
	bool foundSpace = 0;
	for (int i = 0; i < 9; i++) {
		if (state[i] == 32) {
			foundSpace = 1;
		}
	}
	//if no space is found, declare tie
	if(!foundSpace) {
		return 0;
	}

	//if none of these conditions are met, not a terminal state
	return 2;
}
