#ifndef COMMAND_H
#define COMMAND_H

#include "../GameSettings.h"

class Command
{
	public:
		virtual ~Command (void) {};
		
		virtual void command (int value) = 0;
};

#endif
