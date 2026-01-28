#include "SetGrowthRateCommand.h"

SetGrowthRateCommand::SetGrowthRateCommand (void) {}

SetGrowthRateCommand::~SetGrowthRateCommand (void) {}

void SetGrowthRateCommand::command (int value) 
{
	GameSettings::setGrowthRate(value);
}
