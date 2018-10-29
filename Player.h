#pragma once

//project includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:
	Player();

	//Overriding methods
	void Update(sf::Time _FrameTime);

};