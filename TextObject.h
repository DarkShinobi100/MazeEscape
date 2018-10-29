#pragma once


//Project includes 
#include "GameObject.h"


class TextObject
	//the " : public " means this class inherits from any class names that follow
	: public GameObject
{
public:

	TextObject();

	//overwriding methods
	void Draw(sf::RenderTarget& _Target);

protected: //this means derived/child classes can access

	sf::Text m_Text;

};
