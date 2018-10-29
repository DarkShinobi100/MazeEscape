//project includes
#include "Player.h"
#include "AssetManager.h"

//constants
#define SPEED 150.0f

Player::Player()
	:MovingObject() //initalise parent class
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown2.png"));
	m_Sprite.setPosition(10.0f, 200.0f);

}

void Player::Update(sf::Time _FrameTime)
{
	//first assume no keys being pressed
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;

	//use the keyboard function to check which keys are currently held down
	
	//UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Velocity.y = -SPEED;
	}

	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Velocity.y = SPEED;
	}

	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_Velocity.x = -SPEED;
	}

	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_Velocity.x = SPEED;
	}

	//call the update function manually
	//on the parent class,this will now
	//move the character

	MovingObject::Update(_FrameTime);
}