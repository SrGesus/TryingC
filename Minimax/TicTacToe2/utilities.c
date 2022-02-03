//file with some useful functions for tictactoe
#include "../include.h"

//clears the screen and sets the cursor to origin
void clearScreen() {
	printf("\33[2J\33[0;0H");
}

//converts the X or O board array into a -1 and 1 board array for the algorithm and returns it
short *boardConvert(short board[9], short player) {
	//in order to return an array, we will have to make it a static
	static short state[9];
	
	for (int i = 0; i < 9; i++) {
		if (board[i] == player) {
			state[i] = -1;
		} else if (board[i] != 32) {	//else if not blank (will be the AI)
			state[i] = 1;
		} else {	
			state[i] = 32;
		}
	}
	return state;
}
