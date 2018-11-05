#pragma once

//project includes
#include "SpriteObject.h"
#include "Player.h"

class PickUp : public SpriteObject
{
public:

	PickUp();

	//Overriding methods
	void Collide(GameObject& _Collider);

private:
	virtual void OnPickUp(Player& _Player);

};