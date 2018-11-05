//project includes
#include "Coin.h"
#include "AssetManager.h"

Coin::Coin()
	: PickUp()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Coin.png"));
	//TEMP: position coin
	m_Sprite.setPosition(100.0f, 300.0f);
}
