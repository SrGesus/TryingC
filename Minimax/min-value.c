//function to determine the min minmax value of a state
#include "include.h"

int minvalue(short state[9]) {
    //verify if state is terminal and return utility
    short utility = terminal(state);
    //the way i've done it the terminal function returns 2 if it's not a terminal state, but utility if it is.
	//utility will be either, -1, 0, or 1
    if (utility != 2) {
        return utility;
    }
	//the greatest utility is 1 so this temporary variable can be 2
    short min = 2;

    for(int i = 0; i < 9; i++) {
        if (state[i] == 32) {
            //These are the spaces that the Min(Opponent) player can potentially play
            //Now we assume the player will play for the minimum minmax value (where the AI'd likely lose)

            short potentialstate[9];
            memcpy (potentialstate, state, 18); //size will always be 18 bytes since it's a 9 variable short array

            //now change the blank space to the opponent player, giving us a potential state
            potentialstate[i] = -1;

            //now we find the minimum minmax value 
            short value = maxvalue(potentialstate);

            if (min > value) {
                min = value;
            }
        }
    }
    return min;
}


