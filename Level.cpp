//project includes
#include "Level.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"
#include "Hazard.h"

Level::Level()
	:m_CurrentLevel(0)
	, m_Player(nullptr)
	, m_UpdateList()
	, m_DrawListWorld()
	, m_DrawListUI()
	, m_CollisionList()

{
	LoadLevel(1);
}

void Level::Draw(sf::RenderTarget& _Target)
{
	//create and update camera
	sf::View Camera = _Target.getDefaultView();
	//ToDo: Follow player with camera
	
	// Draw game world to the window
	_Target.setView(Camera);

	// Draw game objects
	//only draw when active
	for (int i = 0; i < m_DrawListWorld.size(); ++i)
	{
		if (m_DrawListWorld[i]->IsActive())
			m_DrawListWorld[i]->Draw(_Target);
	}

	// Draw UI to the window
	_Target.setView(_Target.getDefaultView());

	//Draw UI objects
	for (int i = 0; i < m_DrawListUI.size(); ++i)
	{
		if (m_DrawListUI[i]->IsActive())
			m_DrawListUI[i]->Draw(_Target);
	}
}

void Level::Update(sf::Time _FrameTime)
{
	// Update all game objects
		// Only draw if the game object is active
	for (int i = 0; i < m_UpdateList.size(); ++i)
	{
		if (m_UpdateList[i]->IsActive())
			m_UpdateList[i]->Update(_FrameTime);
	}



	// Collision detection

	for (int i = 0; i < m_CollisionList.size(); ++i)
	{
		GameObject* Handler = m_CollisionList[i].first;
		GameObject* Collider = m_CollisionList[i].second;

		if (Handler->IsActive() && Collider->IsActive())
		{
			if (Handler->GetBounds().intersects(Collider->GetBounds()))
			{
				Handler->Collide(*Collider);
			}
		}
	}

}

void Level::LoadLevel(int _LevelToLoad)
{
	//Clean up the old level

	//Delete any data already in the level
	for (int i = 0; i < m_UpdateList.size(); ++i)
	{
		delete m_UpdateList[i];
	}

	//clear out our lists
	m_UpdateList.clear();
	m_DrawListWorld.clear();
	m_DrawListUI.clear();
	m_CollisionList.clear();
	   	  
	//set the current level
	m_CurrentLevel = _LevelToLoad;

	//-=Set up the new level=-
	//create the player
	Player* OurPlayer =  new Player();
	OurPlayer->SetPosition(200.0f, 50.0f);
	OurPlayer->SetLevel(this);
	m_UpdateList.push_back(OurPlayer);
	m_DrawListWorld.push_back(OurPlayer);
	m_Player = OurPlayer;

	//create a Coin
	Coin* aCoin = new Coin();
	aCoin->SetPosition(675.0f, 50.0f);
	m_UpdateList.push_back(aCoin);
	m_DrawListWorld.push_back(aCoin);
	m_CollisionList.push_back(std::make_pair(aCoin, OurPlayer));

	//create a wall
	Wall* aWall = new Wall();
	aWall->SetPosition(100.0f, 50.0f);
	m_UpdateList.push_back(aWall);
	m_DrawListWorld.push_back(aWall);
	m_CollisionList.push_back(std::make_pair(OurPlayer, aWall));

	//create the Baddy
	Baddy* aBaddy = new Baddy();
	aBaddy->SetPosition(300.0f, 250.0f);
	m_UpdateList.push_back(aBaddy);
	m_DrawListWorld.push_back(aBaddy);

	//create a key
	Key* aKey = new Key();
	aKey->SetPosition(425.0f, 50.0f);
	m_UpdateList.push_back(aKey);
	m_DrawListWorld.push_back(aKey);
	m_CollisionList.push_back(std::make_pair(aKey, OurPlayer));

	//create the score item
	Score* aScore = new Score();
	aScore->SetPosition(550.0f, 50.0f);
	m_UpdateList.push_back(aScore);
	m_DrawListUI.push_back(aScore);

	//set the address for player in Score
	aScore->SetPlayer(OurPlayer);

	//create the exit
	Exit* aExit = new Exit;
	aExit->SetPosition(400.0f, 100.0f);
	aExit->SetPlayer(OurPlayer);
	m_UpdateList.push_back(aExit);
	m_DrawListWorld.push_back(aExit);

	//create a hazard
	Hazard* aHazard = new Hazard;
	aHazard->SetPosition(650.0f, 300.0f);
	m_UpdateList.push_back(aHazard);
	m_DrawListWorld.push_back(aHazard);
	m_CollisionList.push_back(std::make_pair(aHazard, OurPlayer));

}

void Level::ReloadLevel()
{
	LoadLevel(m_CurrentLevel);
}