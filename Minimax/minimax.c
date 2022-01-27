#include "include.h"
//the minimax function will take in the board as a parameter and return the position that is to be played, from 0 to 8
int minimax(short state[9]) {
	//the lowest utility is -1 so max can be -2
	short max = -2;
	int position;
	
	//check each blank space as a potential play
	for(int i = 0; i < 9; i++) {
		if (state[i] == 32) {
			short potentialstate[9];
			memcpy(potentialstate, state, 18);	//size will always be 18 bytes since it's a 9 variable short array

			//now change the blank space to the AI player, giving us a potential state
			potentialstate[i] = 1;

			//this will start the recursive algorithm
			int value = maxvalue(potentialstate);
			
			//find the first play that leads to the greatest utility
			if (max < value) {
				max = value;
				position = i;
			}
		}
	}
	return position;
}
