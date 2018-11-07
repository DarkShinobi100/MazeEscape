//project includes
#include "Coin.h"
#include "AssetManager.h"

Coin::Coin()
	: PickUp()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Coin.png"));
}

void Coin::OnPickUp(Player& _Player)
{
	_Player.ChangeScore(1);
}
