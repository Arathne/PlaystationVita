#ifndef GAME_H
#define GAME_H

#include "Node.h"
#include "../Snake/Snake.h"
#include "../Collision.h"
#include "../Food.h"

class Game : public Node
{
	public:
		Game (void);
		~Game (void);

		Node* process (void);

	private:
		void input (void);
		
		Snake snake_;
		Food food_;
		Collision collision_;
};

#endif
