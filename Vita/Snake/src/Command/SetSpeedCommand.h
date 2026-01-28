#ifndef SET_SPEED_COMMAND_H
#define SET_SPEED_COMMAND_H

#include "Command.h"

class SetSpeedCommand : public Command
{
	public:
		SetSpeedCommand (void);
		~SetSpeedCommand (void);

		void command (int value);
};

#endif
