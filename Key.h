#pragma once

//project Includes
#include "PickUp.h"

class Key : public PickUp
{
public:
	Key();

private:
	//Overridding Methods
	virtual void OnPickUp(Player& _Player);
};
