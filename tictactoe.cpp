/*
    tictactoe.cpp
    
    
	Author(s): Parth Mishra
	
	Group Name: Team Forever Alone :(
	
	This is a implementation of the popular game "Tic Tac Toe"
	in which players attempt to line up 3 X's or O's on a 3x3
	grid.
	
*/	
	


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
	
		
	// determines symbol to be used based on the current player number
	if ( player == 1 )
	{
		symbol = 'X';
	}
	else
	{
		symbol = 'O';
	}
	
	
	// find the selected cell and see if it's already occupied, if not
	// mark the cell
	
	if ( cells[selection] != 'X' && cells[selection] != 'O')
    {
        cells[selection] = symbol;

        return true;
    }
    else
    {
        return false;
    }

	//return false;
	
}
 
int result() {
	
	// size of our array that holds all winning combos
    const size_t SIZE = 24;
    
    
    // An array that holds all winning varaibles,
    // Each line is a winning combination in the grid
    int winningCombos[24] ={1, 2, 3,
                            4, 5, 6,
                            7, 8, 9,
                            1, 4, 7,
                            2, 5, 8,
                            3, 6, 9,
                            1, 5, 9,
                            3, 5, 7};
    
    // This will loop through the willing combo's array and check if
    // if there is a winning combination in the grid
    
    // For example if there is a X on 1 2 and 3 it would find the combination
    // on the first go around. If it doesn't find a winning combo on the first loop
    // it will increase the index by 3 (i.e move to the next winning combination)
    for ( size_t i = 0; i != SIZE; i += 3 )
    {
        if (cells[winningCombos[i]] == cells[winningCombos[i+1]] && cells[winningCombos[i+1]] == cells[winningCombos[i+2]])
        {
           
            return WIN;
            
        }
        
    }
    
    // check for draw
    if ( cells[1] != '1' && cells[2] != '2' && cells[3] != '3' && cells[4] != '4'
     && cells[5] != '5' && cells[6] != '6' && cells[7] != '7' && cells[8] != '8' && cells[9] != '9' )
	{
		return DRAW;
	}
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
