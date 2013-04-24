#include <iostream>


#define WIN 2
#define IN_PROGRESS 1
#define DRAW 0



using namespace std;



// The grid cells for which X or O will go into will be stored in an
// array is initially numbered for its position on 3x3 grid
char cells[10];

// Sets up a simple UI for the 3x3 grid required for play
void grid();

// Checks the state of the game. 
int result();

// resets the game board
void reset();

// if the move is valid, this updates the state of the cell
bool symbol( int player, int selection );


/********************************
 ****FUNCTION IMPLEMENTATIONS****
 ********************************/
 
bool symbol( int player, int selection ) {
	
	// if the selection is not a number between 1 and 9, return false
	if ( selection < 1 || selection > 9 )
	{
		return false;
	}
	
	char symbol;
	
	// move validity
	bool valid = false;
	
	// determines symbol to be used based on the current player number
	if ( player == 1 )
	{
		symbol = 'X';
	}
	else
	{
		symbol = 'O';
	}
	
	
	// find the selected cell and check if it's a valid place to put
	// a the proper symbol
	
	if ( selection == 1 && cells[1] == '1' )
	{
			cells[1] = symbol;
			valid = true;
	}
	else if ( selection == 2 && cells[2] == '2' )
	{
			cells[2] = symbol;
			valid = true;
	}
	else if ( selection == 3 && cells[3] == '3' )
	{
			cells[3] = symbol;
			valid = true;
	}
	else if ( selection == 4 && cells[4] == '4' )
	{
			cells[4] = symbol;
			valid = true;
	}
	else if ( selection == 5 && cells[5] == '5' )
	{
			cells[5] = symbol;
			valid = true;
	}
	else if ( selection == 6 && cells[6] == '6' )
	{
			cells[6] = symbol;
			valid = true;
	}
	else if ( selection == 7 && cells[7] == '7' )
	{
			cells[7] = symbol;
			valid = true;
	}
	else if ( selection == 8 && cells[8] == '8' )
	{
			cells[8] = symbol;
			valid = true;
	}
	else if ( selection == 9 && cells[9] == '9' )
	{
			cells[9] = symbol;
			valid = true;
	}
	else
	{
		valid = false;
	}
	
	return valid;
	
}
 
int result() {
	
	// These are all the possible winning combinations, if any of these
	// are satisfied, then it's a win
	if ( cells[1] == cells[2] && cells[2] == cells[3] )
	{
		return WIN;
	} 
	else if ( cells[4] == cells[5] && cells[5] == cells[6] ) 
	{
		return WIN;
	}
	else if ( cells[7] == cells[8] && cells[8] == cells[9] )
	{
		return WIN;
	}
	else if ( cells[1] == cells[4] && cells[4] == cells[7] )
	{
		return WIN;
	}
	else if ( cells[2] == cells[5] && cells[5] == cells[8] )
	{
		return WIN;
	}
	else if ( cells[3] == cells[6] && cells[6] == cells[9] )
	{
		return WIN;
	}
	else if ( cells[1] == cells[5] && cells[5] == cells[9] )
	{
		return WIN;
	}
	else if ( cells[3] == cells[5] && cells[5] == cells[7] )
	{
		return WIN;
	}
	// check for a draw in which every cell is occupied yet none of the possible winning combinations exist
	else if ( cells[1] != '1' && cells[2] != '2' && cells[3] != '3' && cells[4] != '4'
     && cells[5] != '5' && cells[6] != '6' && cells[7] != '7' && cells[8] != '8' && cells[9] != '9' )
	{
		return DRAW;
	}
	// if it's neither a win nor a draw, then it's still in progress
	else
	{
		return IN_PROGRESS;
	}
}

void reset() {
	
	cells[0] = '0';
	cells[1] = '1';
	cells[2] = '2';
	cells[3] = '3';
	cells[4] = '4';
	cells[5] = '5';
	cells[6] = '6';
	cells[7] = '7';
	cells[8] = '8';
	cells[9] = '9';
	
}

void grid() {
	
	
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << cells[1] << "  |  " << cells[2] << "  |  " << cells[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << cells[4] << "  |  " << cells[5] << "  |  " << cells[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << cells[7] << "  |  " << cells[8] << "  |  " << cells[9] << endl;

	cout << "     |     |     " << endl << endl;
}

int main() {
	
	int player = 1;
	int selection = -1;
	int outcome;
	
	reset();
	
	
	do
	{	
		grid();
		player = ( player%2 )?1:2;
		
		cout << "Player " << player << ", pick a square: ";
		cin >> selection;
	
		symbol ( player, selection );
		
		outcome = result();
		
		player++;
		
	} while ( outcome == IN_PROGRESS );
	
	grid();
	
	player = player - 1;
	
	if ( outcome == WIN )
	{
		cout << "Player " << player << " wins!!!" << endl;
	}
	
	if ( outcome == DRAW )
	{
		cout << "The game is a draw!" << endl;
	}
	
}