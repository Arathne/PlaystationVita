#include "Snake.h"

#include <iostream>

#define SQUARE 32
#define GAP 3

Snake::Snake (void):
	facing_(NONE),
	next_(facing_),
	head_(nullptr),
	tracker_(Rectangle((960/2)-(SQUARE/2), (544/2)-(SQUARE/2), SQUARE, SQUARE)),
	speed_(GameSettings::getSpeed()),
	counter_(0),
	tail_(false),
	max_length_(GameSettings::getStartLength()),
	grow_(GameSettings::getGrowthRate())
{
	tracker_.setColor(255, 0, 0);
}

Snake::Snake (float x, float y):
	facing_(NONE),
	next_(facing_),
	head_(nullptr),
	tracker_(Rectangle(x, y, SQUARE, SQUARE)),
	speed_(GameSettings::getSpeed()),
	counter_(0),
	tail_(false),
	max_length_(GameSettings::getStartLength()),
	grow_(GameSettings::getGrowthRate())
{
	tracker_.setColor(255, 0, 0);
}

Snake::~Snake (void) 
{
	if (head_ != nullptr)
		delete head_;

	for (auto it = body_.begin(); it != body_.end(); it++ )
	{
		delete *it;
	}
}

void Snake::update (void)
{
	if (counter_ * speed_ >= SQUARE + GAP)
	{
		if (facing_ != NONE)
		{
			float offset = (counter_ * speed_) - (SQUARE + GAP);
		
			if (offset > 0 && head_ != nullptr)
				head_ -> backward(tracker_, offset);
		}
		
		Snake::changeHead();
		counter_ = 0;
	}
	
	Snake::moveTail();
	
	if (head_ != nullptr)
		head_ -> forward(tracker_, speed_);
	
	counter_++;
}

void Snake::changeHead (void)
{
	if (facing_ != next_)
	{
		if (head_ != nullptr)
			body_.push_back(head_);
		
		head_ = factory_.build(next_, tracker_);
		head_ -> setColor(0, 255, 0);
		
		facing_ = next_;
		tail_ = true;
	}
}

void Snake::direction (DIRECTION input) 
{
	if (facing_ != input && next_ != input && opposite(facing_) != input)
	{
		next_ = input;
	}
}

void Snake::moveTail (void)
{
	if (Snake::getLength() > max_length_)
	{
		int remove = speed_;
		
		for (auto it = body_.begin(); it != body_.end(); it++)
		{
			(*it) -> reduce(remove);
			int length = (*it) -> getLength();
			
			if (length <= 0) {
				remove += length;
				body_.erase(it--);
			}
			else {
				length = (*it) -> getLength();
				if (length <= SQUARE) {
					body_.erase(it--);
				}			
				
				remove = 0;
				break;
			}
		}
		
		if (remove > 0) {
			int length = head_ -> getLength();
			
			if (length - remove < max_length_)
				head_ -> reduce(length - max_length_);
			else
				head_ -> reduce(remove);
		}
	}
}

int Snake::getLength (void)
{
	if (head_ == nullptr)
		return 0;

	int length = head_ -> getLength();

	for (auto it = body_.begin(); it != body_.end(); it++)
	{
		length += (*it) -> getLength();
	}
	
	return length;
}

void Snake::draw (void) 
{
	for (auto it = body_.begin(); it != body_.end(); it++)
	{
		(*it) -> draw();
	}
	
	if (head_ != nullptr)
		head_ -> draw();

	tracker_.draw();
}

bool Snake::collided (void) const
{
	if (head_ == nullptr || facing_ == NONE)
		return false;

	for (auto it = body_.begin(); it != body_.end() && it != body_.end()-1; it++)
	{
		if (Snake::collided( (**it), tracker_ ))
		{
			return true;
		}
	}

	return false;
}

bool Snake::collided (const Rectangle & rectangle) const
{
	if (head_ == nullptr)
		return false;
	
	if (Snake::collided(*head_, rectangle))
	{
		return true;
	}
	else
	{
		for (auto it = body_.begin(); it != body_.end(); it++)
		{
			if (Snake::collided( (**it), rectangle ))
			{
				return true;
			}
		}
	}

	return false;
}

bool Snake::collided (const Body & body, const Rectangle & rect) const
{
	float centerX = (rect.getPositionX() + (rect.getPositionX()+rect.getWidth())) / 2;
	float centerY = (rect.getPositionY() + (rect.getPositionY()+rect.getHeight())) / 2;

	if (centerX < body.getPositionX() || centerX > body.getPositionX() + body.getWidth() ) {
		return false;
	}
	if (centerY < body.getPositionY() || centerY > body.getPositionY() + body.getHeight() ) {
		return false;
	}

	return true;
}

bool Snake::screenCollision (void) const
{
	if (facing_ == NONE)
		return false;

	float centerX = (tracker_.getPositionX() + (tracker_.getPositionX()+tracker_.getWidth())) / 2;
	float centerY = (tracker_.getPositionY() + (tracker_.getPositionY()+tracker_.getHeight())) / 2;
	
	if ((centerX >= 0 && centerX <= 960) && (centerY >= 0 && centerY <= 544))
		return false;

	return true;
}

void Snake::grow (void)
{
	max_length_ += grow_;
}

float Snake::getPositionX (void) const
{
	return tracker_.getPositionX();
}

float Snake::getPositionY (void) const
{
	return tracker_.getPositionY();
}

DIRECTION Snake::getDirection (void) const
{
	return facing_;
}
