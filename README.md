# Trying C
This is the C source code I've done, starting in January 2022, to learn how to code and get used to the tools, which so far have been just Vim and tmux on a bash terminal in a linux mint VM.
Vim rules!
Sluntations.

## Clock
This was the first, a simple clock using time() from the time.h header to get used with simple functions like printf, loops, and variables, converting UNIX into hours minutes and seconds, etc.

## Timer
Looks close to the clock but counting down and accepting user input through scanf(), also trying to makemy own functions ( displayTime() in this case)

## Timer2
Pretty similar to the other timer but with a more intuitive display, hours, minutes, and seconds are entered and it counts down just like the last one

## Tic-Tac-Toe 
Did a simple game of tic-tac-toe, users are able to move between the cells with arrows and hit enter to place the X or O depending on whose turn it is and then a winner or tie is declared, and then the user may play another game. This allowed be to learn a bit about arrays, as i thought a bidimensional array would be the best option to represent the board, among other things.

## Minmax algorithm
I'll attempt to devise an algorithm to play tic tac toe against (and hopefully lose every time) an ai if you will, this will require various steps and will allow me to learn about algorithms such as this.
It should take in the state of the game and who is the AI playing as (X or O) as parameters and then return the position that it will play as.

We'll start with the base (and more easy) steps
To do list:
- [ ] Function that determines if the game state you pass on as an argument means the end of the game, I've done this in tic tac toe already but with a dimensional array, let's call it terminal function
- [ ] Function that assigns utility to such a terminal state
- [ ] Function that converts the array[3][3] that is in the game to a array[9] that will be easier to deal with in the loops that the algorithm will require
