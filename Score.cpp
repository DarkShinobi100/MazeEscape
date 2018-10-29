//Project Includes
#include "Score.h"
#include "AssetManager.h"

Score::Score()
	: TextObject() //Always initialise your parent class in your constructor

{
	m_Text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_Text.setString("Score: 0");
	m_Text.setPosition(50.0f, 50.0f);
}