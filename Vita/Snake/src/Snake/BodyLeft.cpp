#include "BodyLeft.h"

BodyLeft::BodyLeft (void) {}
		
BodyLeft::BodyLeft (const Rectangle & rect):
	Rectangle(rect)
{}

BodyLeft::~BodyLeft (void) {}

void BodyLeft::forward (Rectangle & tracker, float speed) 
{
	tracker.moveX(-speed);
	Rectangle::moveX(-speed);
	Rectangle::addWidth(speed);
}

void BodyLeft::backward (Rectangle & tracker, float speed)
{
	tracker.moveX(speed);
	Rectangle::moveX(speed);
	Rectangle::addWidth(-speed);
}

void BodyLeft::draw (void)
{
	Rectangle::draw();
}

void BodyLeft::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}

void BodyLeft::reduce (float speed)
{
	Rectangle::addWidth(-speed);
}

float BodyLeft::getLength (void)
{
	return Rectangle::getWidth();
}

float BodyLeft::getPositionX (void) const
{
	return Rectangle::getPositionX();
}

float BodyLeft::getPositionY (void) const
{
	return Rectangle::getPositionY();
}

int BodyLeft::getWidth (void) const
{
	return Rectangle::getWidth();
}

int BodyLeft::getHeight (void) const
{
	return Rectangle::getHeight();
}
