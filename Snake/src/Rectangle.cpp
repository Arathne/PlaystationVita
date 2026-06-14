#include "Rectangle.h"

Rectangle::Rectangle (void):
	x_(0.0),
	y_(0.0),
	width_(0),
	height_(0),
	color_(Color::make(0, 255, 0, 255))
{}

Rectangle::Rectangle (float x, float y, int w, int h):
	x_(x),
	y_(y),
	width_(w),
	height_(h),
	color_(Color::make(0, 255, 0, 255))
{}

Rectangle::Rectangle (const Rectangle & rhs)
{
	x_ = rhs.x_;
	y_ = rhs.y_;
	width_ = rhs.width_;
	height_ = rhs.height_;
	color_ = rhs.color_;
}

Rectangle::~Rectangle (void) {}
		
void Rectangle::setPosition (float x, float y)
{
	x_ = x;
	y_ = y;
}

void Rectangle::setPositionX (float x)
{
	x_ = x;
}

void Rectangle::setPositionY (float y)
{
	y_ = y;
}

float Rectangle::getPositionX (void) const
{
	return x_;
}

float Rectangle::getPositionY (void) const
{
	return y_;
}

void Rectangle::setSize (int w, int h)
{
	Rectangle::setWidth(w);
	Rectangle::setHeight(h);
}
		
void Rectangle::setWidth (int w)
{
	width_ = w;
}

void Rectangle::setHeight (int h)
{
	height_ = h;
}

int Rectangle::getWidth (void) const
{
	return width_;
}

int Rectangle::getHeight (void) const
{
	return height_;
}

void Rectangle::addWidth (int w)
{
	width_ += w;
}

void Rectangle::addHeight (int h)
{
	height_ += h;
}

void Rectangle::setColor (Color color)
{
	color_ = color;
}

void Rectangle::setColor (int red, int green, int blue)
{
	color_ = Color::make(red, green, blue, 255);
}

Color Rectangle::getColor (void) const
{
	return color_;
}

void Rectangle::move (float x, float y)
{
	Rectangle::moveX(x);
	Rectangle::moveY(y);
}

void Rectangle::moveX (float x)
{
	x_ += x;
}

void Rectangle::moveY (float y)
{
	y_ += y;
}

void Rectangle::draw (void)
{
	GameRenderer::draw(x_, y_, width_, height_, color_);	
}

const Rectangle & Rectangle::operator = (const Rectangle & rhs)
{
	if (&rhs != &(*this))
	{
		x_ = rhs.x_;
		y_ = rhs.y_;
		width_ = rhs.width_;
		height_ = rhs.height_;
		color_ = rhs.color_;
	}

	return *this;
}
