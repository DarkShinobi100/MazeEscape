//Project Includes
#include "Exit.h"
#include "AssetManager.h"

Exit::Exit()
	: SpriteObject() //Always initialise your parent class in your constructor

{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
	m_Sprite.setPosition(150.0f, 0.0f);
}