//project Includes
#include "PickUp.h"
#include "Player.h"

PickUp::PickUp()
	: SpriteObject()
{

}

void PickUp::Collide(GameObject& _Collider)
{
	// Only do something if the thing we touched was the player

	// We take the generic reference to a game object passed in
	// We get the address for that game object
	// We attempt to treat that address as if it is for a player
	// If successful, it is a player and address is stored in "CastPlayer"
	// If not successful, it is NOT a player and nul ptr is stored in cast player
	Player* CastPlayer = dynamic_cast<Player*>(&_Collider);

	// Only do the thing if player is not NULL
	if (CastPlayer != nullptr)
	{

	// Do something based on type of pickup
		OnPickUp(*CastPlayer);
	
	// Dissapear
		m_active = false;
	}
}

void PickUp::OnPickUp(Player& _Player)
{
	//Do nothing yet
}