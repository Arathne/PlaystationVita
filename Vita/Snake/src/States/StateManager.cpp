#include "StateManager.h"

/* STATIC */
StateManager StateManager::instance;

void StateManager::process (void)
{
	if (instance.state_ == nullptr)
		instance.state_ = new Menu();

	Node* current = instance.state_;
	instance.state_ = current -> process();

	if (current != instance.state_)
		delete current;
}

/* INSTANCE */

StateManager::StateManager (void) {}

StateManager::~StateManager (void)
{
	if (instance.state_ != nullptr)
		delete instance.state_;
}
