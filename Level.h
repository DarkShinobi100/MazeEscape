#pragma once

//project includes
#include "GameObject.h"
#include "Player.h"


class Level
{

public:
	Level();

	void Draw(sf::RenderTarget& _Target);
	void Update(sf::Time _FrameTime);

	void LoadLevel(int _LevelToLoad);
private:

	Player* m_Player;
	// game object lists
	std::vector<GameObject*> m_UpdateList;
	std::vector<GameObject*> m_DrawListWorld;
	std::vector<GameObject*> m_DrawListUI;
	std::vector<std::pair<GameObject*, GameObject*>>m_CollisionList;
};