#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "../Rectangle.h"
#include "../GameSettings.h"
#include "DirectionEnum.h"
#include "BodyFactory.h"

class Snake
{
	public:
		Snake (void);
		Snake (float x, float y);
		~Snake (void);
		
		void update (void);
		void direction (DIRECTION input);
		void draw (void);
		
		bool collided (void) const;
		bool collided (const Rectangle & rectangle) const;
		bool screenCollision (void) const;

		void grow (void);
		
		float getPositionX (void) const;
		float getPositionY (void) const;
		DIRECTION getDirection (void) const;

	private:
		void changeHead (void);
		void moveTail (void);
		int getLength (void);
		bool collided (const Body & body, const Rectangle & rect) const;

		DIRECTION facing_;
		DIRECTION next_;
		
		BodyFactory factory_;

		Body* head_;
		Rectangle tracker_;
		std::vector<Body*> body_;
		float speed_;
		int counter_;
		bool tail_;
		int max_length_;
		int grow_;
};

#endif
