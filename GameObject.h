#pragma once

//library includes
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();

	//these will be very simple/empty functions
	//that can be overwritten in derived classes
	virtual void Draw(sf::RenderTarget& _Target);
	virtual void Update(sf::Time _FrameTime);
	virtual sf::FloatRect GetBounds(); //function for setting up bounding boxes
	virtual void Collide(GameObject& _Collider);
	virtual void SetPosition(sf::Vector2f _Position);
	virtual void SetPosition(float _X, float _Y);
	bool IsActive();

protected:
	bool m_active;


};
