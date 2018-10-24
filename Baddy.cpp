//project includes
#include "Baddy.h"
#include "AssetManager.h"

Baddy::Baddy()
	:MovingObject() //initalise parent class
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Enemy1.png"));
	m_Sprite.setPosition(50.0f, 800.0f);
	m_Velocity.x = 50.0f;
	m_Velocity.y = -170.0f;
}
