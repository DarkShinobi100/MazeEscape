#pragma once


//Project includes 
#include "GameObject.h"


class SpriteObject 
	//the " : public " means this class inherits from any class names that follow
	: public GameObject 
{
public:

	SpriteObject();

	//overwriding methods
	void Draw(sf::RenderTarget& _Target);
	sf::FloatRect GetBounds(); //function for setting up bounding boxes

protected: //this means derived/child classes can access

	sf::Sprite m_Sprite;

};