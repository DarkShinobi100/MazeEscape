//project Includes
#include "GameObject.h"

GameObject::GameObject()
	: m_active(true)
{

}

void GameObject::Draw(sf::RenderTarget& _Target)
{

}
void GameObject::Update(sf::Time _FrameTime)
{

}

sf::FloatRect GameObject::GetBounds() //function for setting up bounding boxes
{
	return sf::FloatRect();//use default float rect value
}

void GameObject::Collide(GameObject& _Collider)
{


}

bool GameObject::IsActive()
{
	return m_active;
}