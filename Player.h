#pragma once

//project includes
#include "MovingObject.h"

class Player : public MovingObject
{

public:
	Player();

	//Overriding methods
	void Update(sf::Time _FrameTime);
	virtual void Collide(GameObject& _Collider);

	//public player methods
	int GetScore();
	void ChangeScore(int _ChangeBy);

	bool GetKeyCollected();
	void SetKey(bool _Value);

private:

	int m_Score;
	bool m_KeyCollected;
};