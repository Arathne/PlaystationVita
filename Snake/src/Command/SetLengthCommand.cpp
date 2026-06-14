#include "SetLengthCommand.h"

SetLengthCommand::SetLengthCommand (void) {}

SetLengthCommand::~SetLengthCommand (void) {}
		
void SetLengthCommand::command (int value)
{
	GameSettings::setStartLength(value);
}
