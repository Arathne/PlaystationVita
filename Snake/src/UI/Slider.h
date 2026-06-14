#ifndef SLIDER_H
#define SLIDER_H

#include <string>

#include "Option.h"
#include "../Command/Command.h"

class Slider : public Option
{
	public:
		Slider (int x, int y, std::string title, int fontSize, int lower, int upper, int current, Node & node, Command & command, int increment);
		~Slider (void);

		void hover (void);
		void unhover (void);
		Node & select (void) const;
		
		void right (void);
		void left (void);

		void draw (void);

	private:
		Slider (void);
		void update (void);

		Text text_;
		
		std::string title_;

		int x_;
		int y_;

		int upper_;
		int lower_;
		int current_;
		int increment_;

		bool hover_;

		Node* state_;
		Command* command_;
};

#endif
