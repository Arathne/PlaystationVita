#include "GameSettings.h"
		
GameSettings GameSettings::instance;

GameSettings::GameSettings (void):
	speed_(4),
	startLength_(100),
	growthRate_(50)
{}

GameSettings::~GameSettings (void) {}
		
void GameSettings::setSpeed (int speed)
{
	instance.speed_ = speed;
}

void GameSettings::setStartLength (int length)
{
	instance.startLength_ = length;
}

void GameSettings::setGrowthRate (int rate)
{
	instance.growthRate_ = rate;
}

int GameSettings::getSpeed (void)
{
	return instance.speed_;
}

int GameSettings::getStartLength (void)
{
	return instance.startLength_;
}

int GameSettings::getGrowthRate (void)
{
	return instance.growthRate_;
}
