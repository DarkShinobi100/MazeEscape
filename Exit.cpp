//Project Includes
#include "Exit.h"
#include "AssetManager.h"

Exit::Exit()
	: SpriteObject() //Always initialise your parent class in your constructor

{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
}