#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

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
void game();
void updateCursor();
void positionCursor(char r, char c);
int checkVictor();
void clearBoard();

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


void game() {
	
	bool firstTurn = 1;
	leave = 0;
	//char board[3][3] = {{32,32,32},{32,32,32},{32,32,32}};	
	
	//let's use a boolean "turn" to determine whose turn is it
	//the boolean is then switched every update
	for(bool turn = 0 ;; turn = !turn) {
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
			return;
		}
		
		//remember arrays start at 0, so we will subract one to the row and column values
		x--;
	   	y--;

		//if the space is blank, set space to player (X or O)
		if (board[x][y] == 32) {
			board[x][y] = player;
		} else {	//else redo this turn
			turn = !turn;
		}

		if (firstTurn) {
			clearBoard();	//clear the board on the firstTurn	
			firstTurn = 0;
		}
		
		switch (checkVictor()) {
			case 0:
				break;
			char temp;
			
			//if there's a tie
			case 1:
				printf("\33[D%c", player);
				printf("\33[0;0H\33[9B\tThere has been a Tie!");
				printf("\n\n\n\tPress any key to continue...");
				system("stty raw");
				temp = getchar();
				system("stty sane");
				fflush(stdout);
				return;
				break;

			case 79:
				printf("\33[D%c", player);
				printf("\33[0;0H\33[9B\tThe Noughts (O) have won!");
				printf("\n\n\n\tPress any key to continue...");
				system("stty raw");
				temp = getchar();
				system("stty sane");
				fflush(stdout);
				return;
				break;

			case 88:
				printf("\33[D%c", player);
				printf("\33[0;0H\33[9B\tThe Crosses (X) have won!");
				printf("\n\n\n\tPress any key to continue...");
				system("stty raw");
				temp = getchar();
				system("stty sane");
				fflush(stdout);
				return;
				break;
		}
	}
}

//Victory is achieved when either every row or column is the same player or diagonals but not blank ( != 32)
//Return the victor: 0 the game continues; 79 is player O; 88 player X; 1 is tie
int checkVictor() {

	bool foundSpace = 0;
	//for every row if all the columns equal but not blank return true
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 32) {
			return board[i][0];
		}
	}

	//for every column if all the rows are equal but not blank return true
	for(int i = 0; i < 3; i++) {
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 32) {
			return board[0][i];
		}
	}

	//if the diagonals are equal but not blank 
	if(board[0][0] == board[1][1] && board[1][1] == board [2][2] && board[1][1] != 32) {
		return board[1][1];	
	}
	
	if(board[0][2] == board[1][1] && board[1][1] == board [2][0] && board[1][1] != 32) {
		return board[1][1];	
	}

	//check for every slot on the board for a space (32), if one is found, foundSpace set to 1
	//if not space is found, declare a tie
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 32) {
				foundSpace = 1;
			}
		}
	}
	if (!foundSpace) {
		return 1;
	}
	return 0;
}

//We will run this until Enter or space bar is pressed
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

		positionCursor(r, c);	//positions cursor on the promted position
		
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
			case 32:
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

void clearBoard() {
	for (int i=0 ; i < 3 ; i++) {
		for (int j=0; j < 3; j++) {
			board[i][j] = 32;
		}
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
