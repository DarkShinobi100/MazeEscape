//project includes
#include "Key.h"
#include "AssetManager.h"

Key::Key()
	: PickUp()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Key.png"));
	//TEMP: position key
	m_Sprite.setPosition(250.0f, 300.0f);
}

void Key::OnPickUp(Player& _Player)
{
	_Player.SetKey(true);
}
