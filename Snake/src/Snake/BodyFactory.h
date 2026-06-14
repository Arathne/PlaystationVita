#ifndef BODY_FACTORY_H
#define BODY_FACTORY_H

#include "DirectionEnum.h"

#include "BodyUp.h"
#include "BodyDown.h"
#include "BodyRight.h"
#include "BodyLeft.h"

class BodyFactory
{
	public:
		BodyFactory (void);
		~BodyFactory (void);

		Body* build (DIRECTION direction, const Rectangle & rect);
};

#endif
