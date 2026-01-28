#ifndef SET_GROWTH_RATE_COMMAND_H
#define SET_GROWTH_RATE_COMMAND_H

#include "Command.h"

class SetGrowthRateCommand : public Command
{
	public:
		SetGrowthRateCommand (void);
		~SetGrowthRateCommand (void);

		void command (int value);
};

#endif
