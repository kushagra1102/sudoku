#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printSudoku(int sudoku[9][9])
{
	int size = 9;
	cout << endl;
	cout << "The solved sudoku puzzle is :" << endl;
	for(int row=0 ; row<size ; row++){
		for(int col=0 ;col<size ; col++){
			cout << sudoku[row][col] << " ";
		}
		cout << endl;
	}
}

bool isPossible(int sudoku[9][9], int row, int col, int val)
{
	int size = 9;
	
	for(int i=0 ; i<size ; i++){
		
		// Check for same element in row
		if(sudoku[row][i] == val)
			return false;
			
		// Check for same element in column
		if(sudoku[i][col] == val)
			return false;
		
		// Check for same element in grid
		if(sudoku[3* (row/3) + i/3][3 * (col/3) + i%3] == val)
			return false;
	}
	
	// If same element is not present in the same row, column or grid
	return true;
}

bool solveSudoku(int sudoku[9][9])
{
	int size = 9;
	for(int row=0 ; row<size ; row++){
		for(int col=0 ; col<size ; col++){
			
			// Check for missing element
			if(sudoku[row][col] == 0){
									
				// Try to insert all values from 1-9
				for(int val=1 ; val<=size ; val++){
					
					// Check if val can be placed in the selected cell
					if(isPossible(sudoku,row,col,val)){
						
						sudoku[row][col] = val;
						
						// Recursive call to solve further
						bool next = solveSudoku(sudoku);
						
						// If solution is possible return true else backtrack
						if(next){
							return true;
						}	
						else{
							sudoku[row][col] = 0;
						}	
						
					}
					
				}
				return false;
					
			}
				
		}
	}
}

int main() {
	
	// Declare sudoku puzzle as a 9x9 2D vector
	int size = 9;
	int s[9][9];
    
// 	{
// 		{5,3,0,0,7,0,0,0,0},
// 		{6,0,0,1,9,5,0,0,0},
// 		{0,9,8,0,0,0,0,6,0},
// 		{8,0,0,0,6,0,0,0,3},
// 		{4,0,0,8,0,3,0,0,1},
// 		{7,0,0,0,2,0,0,0,6},
// 		{0,6,0,0,0,0,2,8,0},
// 		{0,0,0,4,1,9,0,0,5},
// 		{0,0,0,0,8,0,0,7,9}
// 	};

	
    // 	Initialise the sudoku puzzle by asking user for input
	cout << "Kindly enter the Sudoku puzzle with all missing elements as 0" << endl;
	
	for(int row=0 ; row<size ; row++){
	    cout << "Kindly input row no. " << row+1 << " : ";
		for(int col=0 ; col<size ; col++){
			cin >> s[row][col];
		}
		cout << endl;
	}
	cout << " The puzzle you inputted is :" << endl;
	for(int row=0 ; row<size ; row++){
		for(int col=0 ; col<size ; col++){
			cout << s[row][col] << " ";
		}
		cout << endl;
	}

	// validatePuzzle(sudoku);
	
	// Solve the sudoku puzzle by traversing the puzzle and for each missing element
	// use recursion and backtracking to fill it correctly
	bool solve = solveSudoku(s);
	if(solve){
		printSudoku(s);
	}
	else{
		cout << "No valid solution is possible" << endl;
	}
	
	return 0;
}