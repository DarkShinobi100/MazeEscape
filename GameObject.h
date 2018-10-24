#pragma once

//library includes
#include <SFML/Graphics.hpp>

class GameObject
{
public:

	//these will be very simple/empty functions
	//that can be overwritten in derived classes
	void Draw(sf::RenderTarget& _Target);

};