#pragma once

//project includes
#include "SpriteObject.h"

class MovingObject
	: public SpriteObject
{
public:

	MovingObject();

	//Overriding methods
	void Update(sf::Time _FrameTime);

protected:
	sf::Vector2f m_Velocity;
};