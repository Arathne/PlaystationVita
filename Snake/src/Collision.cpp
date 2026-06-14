#include "Collision.h"

Collision::Collision (Food & food, Snake & snake):
	food_(&food),
	snake_(&snake)
{}

Collision::Collision (void) {}

Collision::~Collision (void) {}

void Collision::food (void)
{
	bool foodEaten = false;

	while ( snake_->collided( food_->getRectangle() )) 
	{
		food_-> respawn();
		foodEaten = true;
	}

	if (foodEaten)
	{
		snake_ -> grow();
	}		
}

bool Collision::gameOver (void)
{
	if (snake_ -> collided() || snake_ -> screenCollision())
		return true;
	
	return false;
}
