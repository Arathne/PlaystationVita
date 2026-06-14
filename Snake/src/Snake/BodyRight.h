#ifndef BODY_RIGHT_H
#define BODY_RIGHT_H

#include "Body.h"
#include "../Rectangle.h"

class BodyRight : public Rectangle, public Body
{
	public:
		BodyRight (void);
		BodyRight (const Rectangle & rect);
		~BodyRight (void);

		void forward (Rectangle & tracker, float speed);
		void backward (Rectangle & tracker, float speed);
		void draw (void);
		void setColor (int r, int g, int b);
		void reduce (float speed);
		float getLength (void);
		
		float getPositionX (void) const;
		float getPositionY (void) const;
		int getWidth (void) const;
		int getHeight (void) const;
};

#endif
