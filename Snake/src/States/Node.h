#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "../Input.h"

class Node
{
	public:
		virtual ~Node (void) {};
		
		virtual Node* process (void) = 0;
};

#endif
