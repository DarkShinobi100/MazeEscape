#pragma once

//Project Includes
#include "TextObject.h"
#include "Player.h"

class Score : public TextObject
{
public:

	Score();

	//Overridding methods
	virtual void Update(sf::Time _FrameTime);


	// Public Score Methods
	void SetPlayer(Player* _Player);

private:

	Player* m_Player;

};