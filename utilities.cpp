///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementation
///////////////////////////////////////////////////////////////////////////

#include "globals.h"

int decodeDirection(char dir)
{
	switch (dir)
	{
	case 'u':  return UP;
	case 'd':  return DOWN;
	case 'l':  return LEFT;
	case 'r':  return RIGHT;
	}
	return -1;  // bad argument passed in!
}

bool directionToDeltas(int dir, int& rowDelta, int& colDelta)
{
	switch (dir)
	{
	case UP:     rowDelta = -1; colDelta = 0; break;
	case DOWN:   rowDelta = 1; colDelta = 0; break;
	case LEFT:   rowDelta = 0; colDelta = -1; break;
	case RIGHT:  rowDelta = 0; colDelta = 1; break;
	default:     return false;
	}
	return true;
}