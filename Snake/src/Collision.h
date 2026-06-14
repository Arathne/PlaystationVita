#ifndef COLLISION_H
#define COLLISION_H

#include "Food.h"
#include "Snake/Snake.h"

class Collision
{
	public:
		Collision (Food & food, Snake & snake);
		~Collision (void);
		
		void food (void);
		bool gameOver (void);

	private:
		Collision (void);
		
		Food* food_;
		Snake* snake_;
};

#endif
