//project includes
#include "Hazard.h"
#include "AssetManager.h"
#include "Player.h"

Hazard::Hazard()
	: SpriteObject()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Obstacle.png"));
}

void Hazard::Collide(GameObject& _Collider)
{
	// Only do something if the thing we touched was the player

	Player* CastPlayer = dynamic_cast<Player*>(&_Collider);

	// Only do the thing if player is not NULL
	if (CastPlayer != nullptr)
	{
		// we were touched by the player

		//KILL THEM ALL
		CastPlayer->Kill();

	}
}