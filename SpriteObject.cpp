
//Project includes 
#include "SpriteObject.h"

SpriteObject::SpriteObject()
	: GameObject() //Always initialise your parent class in your constructor
	, m_Sprite()
{
	
}

void SpriteObject::Draw(sf::RenderTarget& _Target)
{
	_Target.draw(m_Sprite);
}