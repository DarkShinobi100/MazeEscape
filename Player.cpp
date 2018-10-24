//project includes
#include "Player.h"
#include "AssetManager.h"

Player::Player()
	:MovingObject() //initalise parent class
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown2.png"));
	m_Sprite.setPosition(10.0f, 200.0f);
	m_Velocity.x = 125.0f;
	m_Velocity.y = 120.0f;
}
