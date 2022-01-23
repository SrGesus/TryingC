#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//creates a 3x3 bidimensional char array that will store the X's and O's of the game, 32 represents a space character
char board[3][3] = {{32,32,32},{32,32,32},{32,32,32}};	
int x, y; 
char player;
bool leave = 0;

//My functions
void displayBoard();
void displayRow(int num);
void clearLine(int num);
int MainMenu();
int game();
void updateCursor();
void positionCursor(char r, char c);
int checkVictory();


int main() {
	//We will run the entire game in a loop, so once a match is done it will come back to the start menu
	while (1) {

		if (MainMenu()) {	//If MainMenu returns 0, which is when n or N is prompted, close the game
			clearLine(0);	//clear screen
			return 0;
		}

 		game();
	}
}


int game() {
	
	bool inProgress = 1;
	bool firstTurn = 1;
	
	//let's use a boolean "turn" to determine whose turn is it
	//the boolean is then switched every update
	//as long as inProgress = 1 it will run, inProgress will be 1 until victory or all spaces filled
	for(bool turn = 0;; turn = !turn) {
		//0 shall be O and 1 shall be X (makes sense)
		if (turn) {
			player = 'X';
		} else {
			player = 'O';
		}
	
		clearLine(0);	//clears screen
		displayBoard();	
		updateCursor();
		
		//if c is entered go back to main menu
		if(leave) {
			return 0;
		}
		
		//remember arrays start at 0, so we will subract one to the row and column values
		x--;
	   	y--;
		board[x][y] = player;
		
		if (firstTurn) {
			board[0][0] = 32;	//the enter from the mainMenu is caught by the getchar in the first turn even if flushed, so this is the simplest workaround
			firstTurn = 0;
		}
	}

}

//We will run this until Enter is pressed
//This will take the user input and change x or y based on it
void updateCursor () {

	int ch;	//the user input
	char r = 1, c = 1;	//rows and columns

	//run on a loop until function is returned aka when Enter is entered
	while (1) {
	
		//rows and columns must be between 1 and 3
		if (r > 3) { r = 1; }
		if (r < 1) { r = 3; }
		if (c > 3) { c = 1; }
		if (c < 1) { c = 3; }

		clearLine(0);
		displayBoard();

		positionCursor(r, c);
		
		//print the Player (X or O) and move back cursor
		printf("%c\33[D", player);

		//receive user input
		system("stty raw");	//unfortunately i can't find a better solution for inputs without pressing enter without using an API, there's no simple cross-platform option but on windows one can use getch() instead
		ch = getchar();
		system("stty sane");

		switch (ch) {
			//When the arrow keys are pressed, up down right left, 65, 66, 67, 68 respectively (Also means ABCD)
			case 65:
				r--;
				break;
			
			case 66:
				r++;
				break;

			case 67:
				c++;
				break;
			
			case 68:
				c--;
				break;
			
			//For some reason Enter seems to input as both 13 and 10
			case 13:
			case 10:
				x = r;
				y = c;
				return;
				break;

			case 99:
				leave = 1;
				return;
				break;
		}
	}
}

//This function will position the cursor on the right row and column
void positionCursor(char r, char c) {

	//places the cursor at 0;0 origin on the terminal
	printf("\33[0;0H");

	//position the cursor on the right row
	switch (r) {
		case 1:
			//go down 3 lines
			printf("\33[3B");
			break;
		case 2:
			//go down 5 lines
			printf("\33[5B");
			break;
		case 3:
			//go down 7 lines
			printf("\33[7B");
			break;
	}
	
	//position the cursor on the right column
	switch (c) {
		case 1:
			printf("\t%d\t ", r);
			break;
		case 2:
			printf("\t%d\t \33[4C", r);
			break;
		case 3:
			printf("\t%d\t \33[8C", r);
			break;
	}
}


// displays the Tic-Tac-Toe Board as per the board array
void displayBoard() {
	printf("\t\tTic-Tac-Toe\n");
	printf("\t\t 1   2   3\n\n");
	
	displayRow(1);
	printf("\t\t———————————\n");
	displayRow(2);
	printf("\t\t———————————\n");
	displayRow(3);
}

// displays row number "num"
void displayRow(int num) {
	int i = num-1;
	printf("\t%d\t %c | %c | %c \n", num, board[i][0], board[i][1], board[i][2]);
}

//clears "num" lines above the cursor
//if num == 0 clears entire screen	and returns cursor to 0,0
void clearLine(int num) {
	if(num == 0) {
		printf("\33[2J\33[0;0H");
	}

	for(int i = num-1; i < num; i++) {
		printf("\33[A\r\33[K");
	}
}


int MainMenu() {
	
	// We will run the mainMenu in a loop and only exit when either y or n is inputted
	char input;
	
	while (1) {
		
		clearLine(0);	//clears the screen
		
		printf("\n\n\t############################\n");
		printf("\t#                          #\n");
		printf("\t#   Welcome to TicTacToe   #\n");
		printf("\t#                          #\n");
		printf("\t#  Would you like to play? #\n");
		printf("\t#                          #\n");
		printf("\t#                          #\n");
		printf("\t############################");
		
		printf("\33[2A\r\t\t(Y/n):");
		scanf(" %c", &input);		//scan for user input
	
		//return 0 for yes, 1 for no
		if (input == 'y' || input == 'Y') {
			return 0;
		} else if (input == 'n' || input == 'N') {
			return 1;
		} 
	}
}
