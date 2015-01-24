#ifndef HISTORY_INCLUDE
#define HISTORY_INCLUDE

#include "globals.h"

class History
{
public:
	History(int nRows, int nCols);
	bool record(int r, int c);
	void display() const;

private:
	int m_rows; int m_cols;
	char h[MAXROWS][MAXCOLS];
};

#endif