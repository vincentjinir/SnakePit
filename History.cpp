#include "History.h"
#include "globals.h"
#include <iostream>

History::History(int nRows, int nCols){
	m_rows = nRows; m_cols = nCols;
	for (int i = 0; i < nRows; i++){
		for (int j = 0; j < nCols; j++){
			h[i][j] = '.';
		}
	}
}

bool History::record(int r, int c){
	if (r < 1 || c < 1 || r > m_rows || c > m_cols) return false;
	if (h[r-1][c-1] == '.') h[r-1][c-1] = 'A';
	else if (h[r-1][c-1] != 'Z') h[r-1][c-1]++;
	return true;
}

void History::display() const{ //not done yet
	clearScreen();
	for (int r = 0; r < m_rows; r++)
	{
		for (int c = 0; c < m_cols; c++)
			std::cout << h[r][c];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
