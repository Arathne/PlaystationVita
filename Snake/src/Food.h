#ifndef FOOD_H
#define FOOD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

#include "Rectangle.h"

class Food
{
	public:
		Food (void);
		~Food (void);

		void respawn (void);
		void draw (void);	
		
		const Rectangle & getRectangle (void) const;

	private:
		Rectangle square_;
};

#endif
