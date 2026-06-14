#include "Slider.h"

Slider::Slider (void) {}

Slider::Slider (int x, int y, std::string title, int fontSize, int lower, int upper, int current, Node & state, Command & command, int increment):
	text_(title.c_str(), "app0:/assets/joystix.ttf", fontSize, GameRenderer::getRenderer()),
	title_(title),
	x_(x),
	y_(y),
	upper_(upper),
	lower_(lower),
	current_(current),
	hover_(false),
	state_(&state),
	command_(&command),
	increment_(increment)
{
	Slider::update();
}
		
Slider::~Slider (void) 
{
	if (command_ != nullptr)
	{
		delete command_;
	}
}

void Slider::hover (void) 
{
	text_.setColor(255, 0, 0, 255);
	hover_ = true;
}

void Slider::unhover (void) 
{
	text_.setColor(255, 255, 255, 255);
	hover_ = false;
}

Node & Slider::select (void) const 
{
	return *state_;
}

void Slider::right (void) 
{
	if (current_ < upper_)
	{
		current_ += increment_;
		Slider::update();
	}
}

void Slider::left (void) 
{
	if (current_ > lower_)
	{
		current_ -= increment_;
		Slider::update();
	}
}

void Slider::update (void)
{
	std::string content = title_ + " <" + std::to_string(current_) + ">";
	text_.setContent( content.c_str() );
	text_.setPosition( x_ - (text_.getWidth()/2), y_ - (text_.getHeight()/2) );
	command_ -> command(current_);
}

void Slider::draw (void) 
{
	text_.draw();
	
	if (hover_)
	{
		int gap = 13;
		int square = 10;
		int x = text_.getPositionX() - gap - square;
		int y = (text_.getPositionY() + (text_.getHeight()/2)) - (square/2);
		GameRenderer::draw (x, y, square, square, Color::make(255, 255, 0, 255));
	}
	if (hover_)
	{
		int gap = 13;
		int square = 10;
		int x = text_.getPositionX() - gap - square;
		int y = (text_.getPositionY() + (text_.getHeight()/2)) - (square/2);
		GameRenderer::draw (x, y, square, square, Color::make(255, 255, 0, 255));
	}
}
