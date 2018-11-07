//Project Includes
#include "Score.h"
#include "AssetManager.h"

Score::Score()
	: TextObject() //Always initialise your parent class in your constructor
	, m_Player(nullptr)

{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Score: 0");
	m_Text.setPosition(50.0f, 50.0f);
}

void Score::Update(sf::Time _FrameTime)
{
	if (m_Player != nullptr)
	{
	
		int Score = m_Player->GetScore();
		m_Text.setString("Score: " + std::to_string(Score));
	}
	
}

void Score::SetPlayer(Player* _Player)
{
	m_Player = _Player;
}