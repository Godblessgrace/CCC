#include <iostream>
#include <string>
#include <limits>
using namespace std;

void printGrid(int grid[][3 + 1]) {
	for (int row = 0 ; row < 3 ; row++) {
		for (int col = 0; col < 3; col++) {
			cout << grid[row][col] << ' ';
		}
		cout << endl;
	}
}


int main(void) {
	int grid[3 + 1][3 + 1] = {0};
	// the third row under each col: the number of int in that col
	// the third col under each row: the number of int in that row

	int count = 0; // the number of int in the grid
	int rowX = -1, colX = -1;
	for (int row = 0 ; row < 3 ; row++) {
		for (int col = 0; col < 3; col++) {
			string str;
			cin >> str;
			if (str != "X" ) {
				grid[row][col] = stoi(str); // string to int
				grid[row][3]++; // increment the number of int in that row 
				grid[3][col]++; // increment the number of int in that col
				count++; // increment the number of int in the grid
			} 
			else {
				grid[row][col] = INT_MIN;
				if (rowX != -1 && col != -1) {
					rowX = row; colX = col;
				}
			}
		}
	}

	// cout << "-1=>0count=" << count << endl;

	if (count == 9) {
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				cout << '0' << ' ';
			}
			cout << endl;
		}
		return 0;
	}

	// case 0 part 1: a row has two int
	for (int row = 0; row < 3; row++) {
		if (grid[row][3] == 2) {
			// if a row has two int, the third int is fixed.
			if (grid[row][0] == INT_MIN) {
				grid[row][0] = grid[row][1] * 2 - grid[row][2];
			} 
			else if (grid[row][1] == INT_MIN) {
				grid[row][1] = (grid[row][0] + grid[row][2]) / 2;
			}
			else {
				grid[row][2] = grid[row][1] * 2 - grid[row][0];
			}
			grid[row][3]++; 
			count++; 
		}
	}

	// case 0 part 2: a col has two int
	for (int col = 0; col < 3; col++) {
		if (grid[3][col] == 2) {
			// if a col has two int, the third int is fixed.
			if (grid[0][col] == INT_MIN) {
				grid[0][col] = grid[1][col] * 2 - grid[2][col];
			} 
			else if (grid[1][col] == INT_MIN) {
				grid[1][col] = (grid[0][col] + grid[2][col]) / 2;
			}
			else {
				grid[2][col] = grid[1][col] * 2 - grid[0][col];
			}
			grid[3][col]++; 
			count++; 
		}
	}

	// cout << "0=>1count=" << count << endl;

	if (count == 9) {
		printGrid(grid);
		return 0;
	}

	// case 1 part 1: a row is fixed
	for (int r = 0; r < 3; r++) {
		if (grid[r][3] == 3) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++) {
					grid[row][col] = grid[r][col];
					if (r != row) count++;
				}
			}
		}
	}

	if (count == 9) {
		printGrid(grid);
		return 0;
	}

	// case 1 part 2: a col is fixed
    for (int c = 0; c < 3; c++) {
    	if (grid[3][c] == 3) {
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++) {
					grid[row][col] = grid[row][c];
					if (c != col) count++;
				}
 			}
 		}
    }

    // cout << "1=>2count=" << count << endl;

    if (count == 9) {
		printGrid(grid);
		return 0;
	}

	// case 2: sudoku
	int r = -1, c = -1;
	bool flag = false;
	for(int row = 0; row < 3; row++) {
		for(int col = 0; col < 3; col++) {
			if (grid[row][col] == INT_MIN) {
				grid[row][col] = 0;
				grid[row][3]++;
				grid[3][col]++;
				count++;
				r = row; c = col; 
				flag = true; break;
			}
		}
		if (flag) break;
	}

	// cout << "count=" << count << endl;

	while (count < 9) {
	for (int row = 0; row < 3; row++) {
		if (grid[row][3] == 2) {
			// if a row has two int, the third int is fixed.
			if (grid[row][0] == INT_MIN) {
				grid[row][0] = grid[row][1] * 2 - grid[row][2];
				grid[3][0]++;
			} 
			else if (grid[row][1] == INT_MIN) {
				grid[row][1] = (grid[row][0] + grid[row][2]) / 2;
				grid[3][1]++;
			}
			else {
				grid[row][2] = grid[row][1] * 2 - grid[row][0];
				grid[3][2]++;
			}
			grid[row][3]++; 
			count++; 
		}
	}

	// out << "count=" << count << endl;
	// printGrid(grid);

	if (count == 9) {
		printGrid(grid);
		return 0;
	}

    //-----------------------------------------------------------
	// case 0 part 2: a col has two int
	for (int col = 0; col < 3; col++) {
		if (grid[3][col] == 2) {
			// if a col has two int, the third int is fixed.
			if (grid[0][col] == INT_MIN) {
				grid[0][col] = grid[1][col] * 2 - grid[2][col];
				grid[0][3]++;
			} 
			else if (grid[1][col] == INT_MIN) {
				grid[1][col] = (grid[0][col] + grid[2][col]) / 2;
				grid[1][3]++;
			}
			else {
				grid[2][col] = grid[1][col] * 2 - grid[0][col];
				grid[2][3]++;
			}
			grid[3][col]++;
			count++; 
		}
	}

	// cout<<"count="<<count<<endl;
	// printGrid(grid);

	if (count == 9) {
		printGrid(grid);
		return 0;
	}
	}

	return 0;
}