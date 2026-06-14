#ifndef OPTION_H
#define OPTION_H

#include "../States/Node.h"
#include "../GameRenderer.h"
#include "../Text.h"

class Option
{
	public:
		virtual ~Option (void) {};
		
		virtual void hover (void) = 0;
		virtual void unhover (void) = 0;
		virtual Node & select (void) const = 0;
		
		virtual void right (void) = 0;
		virtual void left (void) = 0;

		virtual void draw (void) = 0;
};

#endif
