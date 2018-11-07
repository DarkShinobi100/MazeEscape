//Project Includes
#include "Wall.h"
#include "AssetManager.h"

Wall::Wall()
	: SpriteObject() //Always initialise your parent class in your constructor

{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/BrickWall2.png"));
	m_Sprite.setPosition(50.0f, 50.0f);//temp position for testing purposes
}