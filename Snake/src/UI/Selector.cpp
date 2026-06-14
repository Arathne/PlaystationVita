#include "Selector.h"

Selector::Selector (void) {}

Selector::Selector (int x, int y, const char* content, int fontSize):
	state_(nullptr),
	text_(Text(x, y, content, "app0:/assets/joystix.ttf", fontSize, GameRenderer::getRenderer())),
	hover_(false)
{
	text_.move(-(text_.getWidth()/2), -(text_.getHeight()/2));
}

Selector::Selector (int x, int y, const char* content, int fontSize, Node & clickState):
	state_(&clickState),
	text_(Text(x, y, content, "app0:/assets/joystix.ttf", fontSize, GameRenderer::getRenderer())),
	hover_(false)
{
	text_.move(-(text_.getWidth()/2), -(text_.getHeight()/2));
}

Selector::~Selector (void) {}

void Selector::hover (void)
{
	text_.setColor(255, 0, 0, 255);
	hover_ = true;
}

void Selector::unhover (void)
{
	text_.setColor(255, 255, 255, 255);
	hover_ = false;
}

void Selector::right (void) {}

void Selector::left (void) {}

Node & Selector::select (void) const
{
	return *state_;
}

void Selector::draw (void)
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
}
