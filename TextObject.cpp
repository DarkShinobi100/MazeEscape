
//Project includes 
#include "TextObject.h"

TextObject::TextObject()
	: GameObject() //Always initialise your parent class in your constructor
	, m_Text()
{

}

void TextObject::Draw(sf::RenderTarget& _Target)
{
	_Target.draw(m_Text);
}