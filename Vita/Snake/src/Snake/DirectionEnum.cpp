#include "DirectionEnum.h"

DIRECTION opposite (DIRECTION direction)
{
	DIRECTION opp = NONE;

	if (direction == UP)
		opp = DOWN;
	else if (direction == DOWN)
		opp = UP;
	else if (direction == LEFT)
		opp = RIGHT;
	else if (direction == RIGHT)
		opp = LEFT;

	return opp;
}
