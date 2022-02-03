//simple include file
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Options struct for mainmenu
struct Options {
	short player;    //Will be X or O
	bool order;     //Will be 1 or 0, meaning the player will play 1st or 2nd
	bool opponent;  //Will be 1 or 0, 1 meaning against AI, 0 meaning against human
	bool leave; 	//If 1 will cause main.c to exit
};

short board[9];

//function declarations

int maxvalue(short state[9]);	//defined in max-value.c

int minvalue(short state[9]);	//defined in min-value.c

int terminal(short state[9]);	//defined in terminal.c

int minimax(short state[9]);	//defined in minimax.c

struct Options mainmenu();		//defined in menus.c
short promptPlayer(short player);
bool promptOrder(bool order);
bool promptOpponent(bool opponent);

void displayBoard(short board[9]);	//defined in main.c
void positionCursor(int position);
int updateCursor(short board[9], short player);
void declareWinner(int winner);

void clearScreen();	//defined in utilities.c
short *boardConvert(short board[9], short player);
