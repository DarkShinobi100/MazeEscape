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


	//-=create test objects=-
	//create a wall
	Wall aWall;
	aWall.SetPosition(100.0f,50.0f);
	//create the player
	Player Player;
	Player.SetPosition(200.0f, 50.0f);

	//create the Baddy
	Baddy Baddy;
	Baddy.SetPosition(300.0f, 50.0f);
	
	//create a key
	Key Key;
	Key.SetPosition(425.0f, 50.0f);

	//create the score item
	Score Score;
	Score.SetPosition(550.0f, 50.0f);

	//create a Coin
	Coin Coin;
	Coin.SetPosition(675.0f, 50.0f);

	//set the address for player in Score
	Score.SetPlayer(&Player);

	//create the exit
	Exit aExit;
	aExit.SetPlayer(&Player);


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

		// TODO: Update all game objects
		// Only draw if the game object is active
		if (Player.IsActive())
		{
			Player.Update(FrameTime);
		}
		if (Baddy.IsActive())
		{
			Baddy.Update(FrameTime);
		}
		if (Coin.IsActive())
		{
			Coin.Update(FrameTime);
		}
		if (Score.IsActive())
		{
			Score.Update(FrameTime);
		}

		if (aExit.IsActive())
		{
			aExit.Update(FrameTime);

		}
		if (aWall.IsActive())
		{
			aWall.Update(FrameTime);

		}
		// -----------------------------------------------
		// Collision Section
		// -----------------------------------------------

		// TODO: Collision detection
		if (Coin.IsActive() && Player.IsActive())
		{
			if (Coin.GetBounds().intersects(Player.GetBounds()))
			{
				Coin.Collide(Player);
			}
		}

		//check key collision
		if (Key.IsActive() && Player.IsActive())
		{
			if (Key.GetBounds().intersects(Player.GetBounds()))
			{
				
				Key.Collide(Player);
			}
		}

		//check Wall collision
		if (aWall.IsActive() && Player.IsActive())
		{
			if (aWall.GetBounds().intersects(Player.GetBounds()))
			{

				Player.Collide(aWall);
			}
		}

		// -----------------------------------------------
		// Draw Section
		// -----------------------------------------------
		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw game world to the window
		gameWindow.setView(camera);
		// TODO: Draw game objects
		aWall.Draw(gameWindow); //create a wall
		Baddy.Draw(gameWindow); //create the Enemy
		
		//only draw when active
		if (Player.IsActive())
		{
			Player.Draw(gameWindow); //create the player
		}
		if (Coin.IsActive())
		{
			Coin.Draw(gameWindow); //create the coin
		}
		if (aExit.IsActive())
		{
			aExit.Draw(gameWindow); //create the exit
		}
		if (Key.IsActive())
		{
			Key.Draw(gameWindow);//draw a key
		}
		if (aWall.IsActive())
		{
			aWall.Draw(gameWindow);//draw a key
		}

		// Draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		
		// TODO: Draw UI objects
		if (Score.IsActive())
		{
			Score.Draw(gameWindow); //create the score
		}

		// Display the window contents on the screen
		gameWindow.display();

	} // End of Game Loop
	return 0;

} // End of main() Function