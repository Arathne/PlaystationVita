#include "Food.h"

#define SQUARE 32
#define GAP 3

#define CENTER_X (960/2)-(SQUARE/2)
#define CENTER_Y (544/2)-(SQUARE/2)

#define MAX_X 13
#define MAX_Y 7

Food::Food (void):
	square_(Rectangle(CENTER_X, CENTER_Y, SQUARE, SQUARE))
{
	srand(time(NULL));
	square_.setColor(0, 255, 227);
	Food::respawn();
}

Food::~Food (void) {}
		
void Food::respawn (void)
{
	int randX = rand() % (MAX_X-(-MAX_X)+1) + (-MAX_X);
	int randY = rand() % (MAX_Y-(-MAX_Y)+1) + (-MAX_Y);
	
	float x = CENTER_X + (SQUARE * randX) + (GAP * randX);
	float y = CENTER_Y + (SQUARE * randY) + (GAP * randY);
	
	square_.setPosition(x, y);
}

void Food::draw (void)
{
	square_.draw();
}

const Rectangle & Food::getRectangle (void) const
{
	return square_;
}
