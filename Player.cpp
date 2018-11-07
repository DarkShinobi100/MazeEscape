//project includes
#include "Player.h"
#include "AssetManager.h"
#include"Wall.h"

//constants
#define SPEED 250.0f

Player::Player()
	:MovingObject() //initalise parent class
	, m_Score(0) //initialise score
	, m_KeyCollected(false)
{
	m_Sprite.setTexture(AssetManager::GetTexture("graphics/PlayerWalkDown2.png"));

}

void Player::Update(sf::Time _FrameTime)
{
	//first assume no keys being pressed
	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;

	//use the keyboard function to check which keys are currently held down
	
	//UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_Velocity.y = -SPEED;
	}

	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_Velocity.y = SPEED;
	}

	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Velocity.x = -SPEED;
	}

	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Velocity.x = SPEED;
	}

	//call the update function manually
	//on the parent class,this will now
	//move the character

	MovingObject::Update(_FrameTime);
}

void Player::Collide(GameObject& _Collider)
{
	// Only do something if the thing we touched was the wall

	//dynamic cast the hame object reference
	//into a wall pointer
	//if it was successfull, it was a wall
	Wall* WallCollider = dynamic_cast<Wall*>(&_Collider);

	//if it was a wall we git, we need to move ourselves
	//outside the walls bounds, aka back to our previous position
	if (WallCollider != nullptr)
	{
		//if we actually DID hit a wall!

		//set position to previous position that we just moved from this frame
		m_Sprite.setPosition(m_PreviousPosition);

		//clumsy - results in "sticky" walls
		// but is good enough for basic games
	}
}

int Player::GetScore() 
{
	return m_Score;
}

void Player::ChangeScore(int _ChangeBy)
{
	m_Score += _ChangeBy;
}

bool Player::GetKeyCollected()
{
	return m_KeyCollected;
}

void Player::SetKey(bool _Value)
{
	m_KeyCollected = _Value;
}