
//Project Includes
#include "MovingObject.h"

MovingObject::MovingObject() //always initalise constructors like so
	:SpriteObject	() //always intialise base class
	, m_Velocity	(0.0f,0.0f)
{

}

void MovingObject::Update(sf::Time _FrameTime)
{
	//get the current position
	sf::Vector2f CurrentPosition = m_Sprite.getPosition(); 

	//calculate the amount moved
	sf::Vector2f AmountMoved = m_Velocity * _FrameTime.asSeconds(); //pixels per second

	//Calculate new position
	sf::Vector2f NewPosition = CurrentPosition + AmountMoved;

	//Set our sprite to this new position
	m_Sprite.setPosition(NewPosition);
}