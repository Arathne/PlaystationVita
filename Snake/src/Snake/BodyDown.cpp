#include "BodyDown.h"

BodyDown::BodyDown (void) {}

BodyDown::BodyDown (const Rectangle & rect):
	Rectangle(rect)
{}

BodyDown::~BodyDown (void) {}

void BodyDown::forward (Rectangle & tracker, float speed) 
{
	tracker.moveY(speed);
	Rectangle::addHeight(speed);
}

void BodyDown::backward (Rectangle & tracker, float speed)
{
	tracker.moveY(-speed);
	Rectangle::addHeight(-speed);
}

void BodyDown::draw (void)
{
	Rectangle::draw();
}

void BodyDown::setColor (int r, int g, int b)
{
	Rectangle::setColor(r, g, b);
}

void BodyDown::reduce (float speed)
{
	Rectangle::moveY(speed);
	Rectangle::addHeight(-speed);
}

float BodyDown::getLength (void)
{
	return Rectangle::getHeight();
}

float BodyDown::getPositionX (void) const
{
	return Rectangle::getPositionX();
}

float BodyDown::getPositionY (void) const
{
	return Rectangle::getPositionY();
}

int BodyDown::getWidth (void) const
{
	return Rectangle::getWidth();
}

int BodyDown::getHeight (void) const
{
	return Rectangle::getHeight();
}
