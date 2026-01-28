#include "BodyFactory.h"

BodyFactory::BodyFactory (void) {}

BodyFactory::~BodyFactory (void) {}

Body* BodyFactory::build (DIRECTION direction, const Rectangle & rect)
{
	if (direction == UP) {
		return new BodyUp(rect);
	}
	else if (direction == DOWN) {
		return new BodyDown(rect);
	}
	else if (direction == LEFT) {
		return new BodyLeft(rect);
	}
	else if (direction == RIGHT) {
		return new BodyRight(rect);
	}
	
	return nullptr;
}
