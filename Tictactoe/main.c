#include <stdio.h>
#include <stdbool.h>

//creates a 3x3 bidimensional char array that will store the X's and O's of the game, 32 represents a space character
char board[3][3] = {{32,32,32},{32,32,32},{32,32,32}};	

//My functions
void displayBoard();
void displayRow(int num);
void clearLine(int num);
int MainMenu();
int game();

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
	int x,y;
	
	//0 shall be O and 1 shall be X (makes sense)
	char player;
	
	//let's use a boolean "turn" to determine whose turn is it
	//as long as inProgress = 1, the boolean is then switched every update
	for(bool turn = 0; inProgress; turn = !turn) {
		if (turn) {
			player = 'X';
		} else {
			player = 'O';
		}
	
		clearLine(0);	//clears screen
		
		printf("\t\tTic-Tac-Toe\n");
		displayBoard();	
		printf("\nTurn for: %c\n", player);
		printf("\nEnter the coordinates of the space to be marked:");
		printf("\n Row\n \( ");
		scanf("%d", &x);
		printf("\33[A\33[A      Column");
		printf("\n \( %d , ", x);
		scanf("%d", &y);
		
		//remember arrays start at 0, so we will subract one to the row and column values
		x--; y--;

		board[x][y] = player;
	}

}




// displays the Tic-Tac-Toe Board as per the board array
void displayBoard() {
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
		scanf(" %c", &input);
	
		//return 0 for yes, 1 for no
		if (input == 'y' || input == 'Y') {
			return 0;
		} else if (input == 'n' || input == 'N') {
			return 1;
		} 
	}
}
