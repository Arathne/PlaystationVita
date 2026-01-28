#ifndef SET_LENGTH_COMMAND_H
#define SET_LENGTH_COMMAND_H

#include "Command.h"

class SetLengthCommand : public Command
{
	public:
		SetLengthCommand (void);
		~SetLengthCommand (void);
		
		void command (int value);
};

#endif
