#ifndef SELECTOR_H
#define SELECTOR_H

#include "Option.h"

class Selector : public Option
{
	public:
		Selector (int x, int y, const char* content, int fontSize);
		Selector (int x, int y, const char* content, int fontSize, Node & clickState_);
		~Selector (void);

		void hover (void);
		void unhover (void);
		Node & select (void) const;
		
		void right (void);
		void left (void);

		void draw (void);
	
	private:
		Selector (void);
		
		Node* state_;
		Text text_;
		bool hover_;
};

#endif
