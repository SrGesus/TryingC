//function for displaying the menus at the start of each match
#include "../include.h"

struct Options mainmenu() {
		//static variables preserve their value out of scope if in the same file and 
		static struct Options menu = {
			'X',	//the default player will be X
			1,		//will play 1st by default
			1,		//will play against AI by default
			0,		//if 1 exits
		};

	while(1) {
		clearScreen();	//function in utilities.c
	
		printf("\n\n");
		printf("\t┌─────────────────────────┐\n");
		printf("\t│  Welcome to TicTacToe!  │\n");
		printf("\t├─────────────────────────┤\n");	
		printf("\t│ Options:                │\n");
		printf("\t│  [1]- Player            │\n");
		printf("\t│  [2]- Playing Order     │\n");
		printf("\t│  [3]- Opponent          │\n");
		printf("\t│  [4]- Play!             │\n");
		printf("\t│  [5]- Exit.             │\n");
		printf("\t│                         │\n");
		printf("\t└─────────────────────────┘\n");
		
		printf("\33[2A\t│  Enter Option:");

		//gets user input without enter (only works in bash)
		char input;
		system("stty raw");
		input = getchar();
		system("stty sane");
		
		//if the input doesn't match the loop is repeated	
		switch (input) {
			case '1':
				menu.player = promptPlayer(menu.player);
				break;

			case '2':
				menu.order = promptOrder(menu.order);
				break;

			case '3':
				menu.opponent = promptOpponent(menu.opponent);
				break;

			case '4':
				//returns the menu struct with the options
				return menu;
			
			case '5':
				menu.leave = 1;
				return menu;
		}
	}
}

short promptPlayer(short player) {

	while(1) {
		clearScreen();	//function in utilities.c
	
		printf("\n\n");
		printf("\t┌─────────────────────────┐\n");
		printf("\t│  Welcome to TicTacToe!  │\n");
		printf("\t├─────────────────────────┤\n");	
		printf("\t│ You'll be playing as: %c │\n", player);
		printf("\t│ [1]- Change Player      │\n");
		printf("\t│ [2]- Done               │\n");
		printf("\t│                         │\n");
		printf("\t└─────────────────────────┘\n");
		
		printf("\33[2A\t│  Enter Option:");

		//gets user input without enter (only works in bash)
		char input;
		system("stty raw");
		input = getchar();
		system("stty sane");
		
		//if the input doesn't match the loop is repeated	
		switch (input) {
			case '1':
				if (player == 'X') {
					player = 'O';
				} else {
					player ='X';
				}
				break;

			case '2':
				return player;
		}
	}
}

bool promptOrder(bool order) {

	while(1) {
		clearScreen();	//function in utilities.c
	
		printf("\n\n");
		printf("\t┌─────────────────────────┐\n");
		printf("\t│  Welcome to TicTacToe!  │\n");
		printf("\t├─────────────────────────┤\n");	
		
		if (order) {
			printf("\t│  You'll be playing 1st  │\n");
		} else {
			printf("\t│  You'll be playing 2nd  │\n");
		}

		printf("\t│ [1]- Change Order       │\n");
		printf("\t│ [2]- Done               │\n");
		printf("\t│                         │\n");
		printf("\t└─────────────────────────┘\n");
		
		printf("\33[2A\t│  Enter Option:");

		//gets user input without enter (only works in bash)
		char input;
		system("stty raw");
		input = getchar();
		system("stty sane");
		
		//if the input doesn't match the loop is repeated	
		switch (input) {
			case '1':
				order = !order;
				break;

			case '2':
				return order;
		}
	}
}

bool promptOpponent(bool opponent) {

	while(1) {
		clearScreen();	//function in utilities.c
	
		printf("\n\n");
		printf("\t┌─────────────────────────┐\n");
		printf("\t│  Welcome to TicTacToe!  │\n");
		printf("\t├─────────────────────────┤\n");	
		printf("\t│ Your opponent will be:  │\n");
		
		if (opponent) {
			printf("\t│ Artificial Intelligence │\n");
		} else {
			printf("\t│ A Friend (bring them)   │\n");
		}

		printf("\t│ [1]- Change Opponent    │\n");
		printf("\t│ [2]- Done               │\n");
		printf("\t│                         │\n");
		printf("\t└─────────────────────────┘\n");
		
		printf("\33[2A\t│  Enter Option:");

		//gets user input without enter (only works in bash)
		char input;
		system("stty raw");
		input = getchar();
		system("stty sane");
		
		//if the input doesn't match the loop is repeated	
		switch (input) {
			case '1':
				opponent = !opponent;
				break;

			case '2':
				return opponent;
		}
	}
}

