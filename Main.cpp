// Library Includes
#include <SFML/Window.hpp>	
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>

// Project Includes
#include "AssetManager.h"
#include "Wall.h"
#include "Exit.h"
#include "Player.h"
#include "Baddy.h"
#include "Score.h"
#include "Coin.h"
#include "Key.h"

// The main() Function - entry point for our program
int main()
{
	// -----------------------------------------------
	// Game Setup
	// -----------------------------------------------

	// Window - to draw to the screen
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Maze Escape", sf::Style::Titlebar | sf::Style::Close);

	// Seed our random number generator 
	srand(time(NULL));

	// Create AssetManager
	AssetManager assets;

	// Game Clock - to keep track of time passed each frame
	sf::Clock gameClock;

	// Game state
	bool playing = false;

	// Game camera
	sf::View camera = gameWindow.getDefaultView();


	// game object lists
	std::vector<GameObject*> UpdateList;
	std::vector<GameObject*> DrawListWorld;
	std::vector<GameObject*> DrawListUI;

	std::vector<std::pair<GameObject*,GameObject*>>CollisionList;

	//-=create test objects=-
	//create the player
	Player Player;
	Player.SetPosition(200.0f, 50.0f);
	UpdateList.push_back(&Player);
	DrawListWorld.push_back(&Player);

	//create a Coin
	Coin Coin;
	Coin.SetPosition(675.0f, 50.0f);
	UpdateList.push_back(&Coin);
	DrawListWorld.push_back(&Coin);
	CollisionList.push_back(std::make_pair(&Coin, &Player));

	//create a wall
	Wall aWall;
	aWall.SetPosition(100.0f,50.0f);
	UpdateList.push_back(&aWall);
	DrawListWorld.push_back(&aWall);
	CollisionList.push_back(std::make_pair(&Player, &aWall));
	   
	//create the Baddy
	Baddy Baddy;
	Baddy.SetPosition(300.0f, 250.0f);
	UpdateList.push_back(&Baddy);
	DrawListWorld.push_back(&Baddy);
	
	//create a key
	Key Key;
	Key.SetPosition(425.0f, 50.0f);
	UpdateList.push_back(&Key);
	DrawListWorld.push_back(&Key);
	CollisionList.push_back(std::make_pair(&Key, &Player));

	//create the score item
	Score Score;
	Score.SetPosition(550.0f, 50.0f);
	UpdateList.push_back(&Score);
	DrawListUI.push_back(&Score);

	//set the address for player in Score
	Score.SetPlayer(&Player);



	//create the exit
	Exit aExit;
	aExit.SetPosition(400.0f, 100.0f);
	aExit.SetPlayer(&Player);
	UpdateList.push_back(&aExit);
	DrawListWorld.push_back(&aExit);


	// -----------------------------------------------
	// Game Loop
	// -----------------------------------------------
	while (gameWindow.isOpen())
	{
		// -----------------------------------------------
		// Input Section
		// -----------------------------------------------

		// Check all events since the last frame and process 
		// each one until there are no more
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// TODO: Pass event to input objects


			// Did the player try to close the window?
			if (gameEvent.type == sf::Event::Closed)
			{
				// If so, call the close function on the window.
				gameWindow.close();
			}

		} // End event polling loop

		// -----------------------------------------------
		// Update Section
		// -----------------------------------------------
		// Get the time passed since the last frame and restart our game clock
		sf::Time FrameTime = gameClock.restart();

		// Update all game objects
		// Only draw if the game object is active
		for (int i = 0; i < UpdateList.size(); ++i)
		{
			if(UpdateList[i]->IsActive())
			UpdateList[i]->Update(FrameTime);
		}

		// -----------------------------------------------
		// Collision Section
		// -----------------------------------------------

		// Collision detection

		for (int i = 0; i < CollisionList.size(); ++i)
		{
			GameObject* Handler = CollisionList[i].first;
			GameObject* Collider = CollisionList[i].second;

			if (Handler->IsActive() && Collider->IsActive())
			{
				if (Handler->GetBounds().intersects(Collider->GetBounds()))
				{
					Handler->Collide(*Collider);
				}
			}
		}

		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------
		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw game world to the window
		gameWindow.setView(camera);
		
		// Draw game objects
		//only draw when active
		for (int i = 0; i < DrawListWorld.size(); ++i)
		{
			if (DrawListWorld[i]->IsActive())
				DrawListWorld[i]->Draw(gameWindow);
		}
		
		// Draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		
		//Draw UI objects
		for (int i = 0; i < DrawListUI.size(); ++i)
		{
			if (DrawListUI[i]->IsActive())
				DrawListUI[i]->Draw(gameWindow);
		}

		// Display the window contents on the screen
		gameWindow.display();

	} // End of Game Loop
	return 0;

} // End of main() Function