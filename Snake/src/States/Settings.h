#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>

#include "Node.h"
#include "../UI/Slider.h"

#include "../Command/SetLengthCommand.h"
#include "../Command/SetGrowthRateCommand.h"
#include "../Command/SetSpeedCommand.h"

class Settings : public Node
{
	public:
		Settings (void);
		~Settings (void);

		Node* process (void);

	private:
		void input (void);

		std::vector<Option*> options_;
		int selected_;
};

#endif
