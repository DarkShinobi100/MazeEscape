//project includes
#include "Key.h"
#include "AssetManager.h"

Key::Key()
	: PickUp()
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/Key.png"));
}

void Key::OnPickUp(Player& _Player)
{
	_Player.SetKey(true);
}
