#pragma once

//project includes
#include "SpriteObject.h"

class Hazard
	: public SpriteObject
{

public:

	Hazard();

	//overriding methods
	void Collide(GameObject& _Collider);


};