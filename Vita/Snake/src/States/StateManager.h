#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "Node.h"
#include "Menu.h"

class StateManager
{
	public:
		~StateManager (void);
		
		static void process (void);

	private:
		StateManager (void);
		
		static StateManager instance;
		Node* state_;
};

#endif
