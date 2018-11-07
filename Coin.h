#pragma once

//project Includes
#include "PickUp.h"

class Coin : public PickUp
{
public:
	Coin();

private:
	//Overridding Methods
	virtual void OnPickUp(Player& _Player);
};