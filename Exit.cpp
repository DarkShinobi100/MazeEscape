//Project Includes
#include "Exit.h"
#include "AssetManager.h"

#include<iostream>
Exit::Exit()
	: SpriteObject() //Always initialise your parent class in your constructor

{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
}


void Exit::Update(sf::Time _FrameTime)
{
	if (m_Player != nullptr)
	{

		bool Door = m_Player->GetKeyCollected();
		if (Door)
		{
			m_Sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
		}
	}
	else
	{
		std::cout << "no pointer to player";
	}
}

void Exit::SetPlayer(Player* _Player)
{
	m_Player = _Player;
}