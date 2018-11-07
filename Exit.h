#pragma once

//Project Includes
#include "SpriteObject.h"
#include "Player.h"

class Exit : public SpriteObject
{
public:
	Exit();
	
	//Overridding methods
	virtual void Update(sf::Time _FrameTime);

	// Public Score Methods
	void SetPlayer(Player* _Player);

private:

	Player* m_Player;

};