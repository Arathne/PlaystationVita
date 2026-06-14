#include "SetSpeedCommand.h"

SetSpeedCommand::SetSpeedCommand (void) {}

SetSpeedCommand::~SetSpeedCommand (void) {}

void SetSpeedCommand::command (int value) 
{
	GameSettings::setSpeed(value);
}
