#include <stdio.h>

char board[3][3] = {{32,32,32},{32,32,32},{32,32,32}};	//creates a 3x3 bidimensional array that will store X or O



//my functions
void displayBoard();
void displayRow(int num);


int main() {
	displayBoard();
}

void displayBoard() {
	printf("\t 1   2   3\n\n");
	
	displayRow(1);
	printf("\t———————————\n");
	displayRow(2);
	printf("\t———————————\n");
	displayRow(3);
}

void displayRow(int num) {
	int i = num-1;
	printf("%d\t %c | %c | %c \n", num, board[i][1], board[i][2], board[i][3]);
}
