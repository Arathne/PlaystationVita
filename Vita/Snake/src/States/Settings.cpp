#include "Settings.h"

Settings::Settings (void):
	selected_(0)
{
	Command* addLength = new SetLengthCommand();
	Command* addGrowthRate = new SetGrowthRateCommand();
	Command* addSpeed = new SetSpeedCommand();

	options_.push_back(new Slider(960/2, 82, "SPEED", 40, 1, 10, GameSettings::getSpeed(), *((Node*) this), *addSpeed, 1));
	options_.push_back(new Slider(960/2, 82+60, "START LENGTH", 40, 100, 1000, GameSettings::getStartLength(), *((Node*) this), *addLength, 50));
	options_.push_back(new Slider(960/2, 82+60+60, "GROWTH RATE", 40, 50, 500, GameSettings::getGrowthRate(), *((Node*) this), *addGrowthRate, 25));
	options_.at(selected_) -> hover();
}

Settings::~Settings (void) 
{
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		delete *it;
	}
}

Node* Settings::process (void) 
{
	Settings::input();
	
	GameRenderer::clear();
	
	for (auto it = options_.begin(); it != options_.end(); it++)
	{
		(*it) -> draw();
	}

	GameRenderer::present();
	
	if (Input::began(SCE_CTRL_CIRCLE))
		return nullptr;

	return this;
}

void Settings::input (void) 
{
	if (Input::began(SCE_CTRL_RIGHT))
	{
		options_.at(selected_) -> right();
	}
	else if (Input::began(SCE_CTRL_LEFT))
	{
		options_.at(selected_) -> left();
	}
	
	if (Input::began(SCE_CTRL_DOWN) && selected_ < options_.size()-1)
	{
		options_.at(selected_) -> unhover();
		selected_++;
		options_.at(selected_) -> hover();
	}
	else if (Input::began(SCE_CTRL_UP) && selected_ > 0)
	{
		options_.at(selected_) -> unhover();
		selected_--;
		options_.at(selected_) -> hover();
	}
}
