#include "../include.h"

int main() {
	//We'll run the entire program in a loop so it goes back to the main menu after each game
	while(1) {
		struct Options menu = mainmenu();
		short board[9] = {32,32,32,32,32,32,32,32,32};	//fills the board with spaces
	
		if(menu.leave) {
			return 1;
		}
		
		short player = menu.player;
		bool turn = menu.order;
		short opponent;
		int position;
		bool redoTurn;

		if (player == 'X') {
		opponent = 'O';
		} else {
		opponent = 'X';
		}

		for(bool inProgress = 1; inProgress; turn = !turn) {
			redoTurn = 0;
			clearScreen();
			displayBoard(board);
			int winner = terminal(board);	//this function returns 2 when there isn't a terminal state, otherwise returns who won, or if there was a tie
			if(winner != 2) {
				declareWinner(winner);
				break;
			}	
			if(turn) {
				position = updateCursor(board, player);
				if (board[position] == 32) {
					board[position] = player;
				} else {
					redoTurn = 1; //if player plays on a non blank slot, ignore the play and redo the turn
				}
			}
			if(!turn) {
				if(menu.opponent) {	//if the opponent is AI 
					//get a pointer to a short int array
					short *state;
					state = boardConvert(board, player);
					board[minimax(state)] = opponent;	//make the AI play their move 
				} else {
					position = updateCursor(board, opponent);
					if (board[position] == 32) {
						board[position] = opponent;
					} else {
						redoTurn = 1; //if player plays on a non blank slot, ignore the play and redo the turn
					}
				}
			}
			if(redoTurn) {
				turn = !turn;
			}
		}
	}
}

void declareWinner(int winner) {
	switch (winner) {
		case 0:
			printf("\33[0;0H\33[7BThere Has Been a tie!\n\n");
			printf("Press any key to continue...");
			
			system("stty raw");
			getchar();
			system("stty sane");
			return;

		default:
			printf("\33[0;0H\33[7BPlayer %c has won!\n\n", winner);
			printf("Press any key to continue...");
			
			system("stty raw");
			getchar();
			system("stty sane");
			return;

	}
}


int updateCursor(short board[9], short player) {
	char input;
	char position = 0;

	//run on a loop until enter or space is inputed
	while(1) {
		//to make sure position is between 0 and 8
		if (position > 8) {
			position -= 9;
		}
		if (position < 0) {
			position += 9;
		}

		clearScreen();
		displayBoard(board);

		positionCursor(position);

		printf("%c\33[D", player);

		system("stty raw");
		input = getchar();
		system("stty sane");

		switch (input) {
		//When the arrow keys are pressed, up down right left, 65, 66, 67, 68 respectively (Also means ABCD)
				case 65:
					position -= 3;
					break;

				case 66:
					position += 3;
					break;

				case 67:
					position++;
					break;

				case 68:
					position--;
					break;

				//for enter or space, for some reason enter seems to input as both 13 and 10
				case 13:
				case 10:
				case 32:
					return position;
		}
	}
}

void displayBoard(short board[9]) {
	printf("\t\tTic-Tac-Toe\n\n");
	printf("\t\t %c │ %c │ %c \n", board[0], board[1], board[2]);
	printf("\t\t───┼───┼───\n");
	printf("\t\t %c │ %c │ %c \n", board[3], board[4], board[5]);
	printf("\t\t───┼───┼───\n");
	printf("\t\t %c │ %c │ %c \n", board[6], board[7], board[8]);
}

void positionCursor(int position) {
	//reset cursor to origin
	printf("\33[0;0H");
	int row = position / 3;
	int column = position - row * 3;
	//for each row
	for(; row >= 0; row--) {
		//go down 2 lines
		printf("\33[2B");
	}

	switch (column) {
		case 0:
			printf("\t\t ");
			break;
		case 1:
			printf("\t\t \33[4C");
			break;
		case 2:
			printf("\t\t \33[8C");
			break;
	}
}
