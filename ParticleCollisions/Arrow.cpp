#include "Arrow.h"

Arrow::Arrow(sf::CircleShape circle, sf::Vector2f vector)
{
	 
	ball = circle;
	if (!texture.loadFromFile("whiteArrow.png"))
	{
		std::cout << "Failed To load Arrow" << std::endl; 
	}
	pointer.setTexture(texture); 
	pointer.setScale(scale);
	pointer.setOrigin(ball.getPosition());
	pointer.setPosition(ball.getPosition()); 
}

void Arrow::update(sf::CircleShape, sf::Vector2f vel)
{
	
}

//sf::Sprite Arrow::loadFromFile()
//{
//	sf::Texture texture;
//	texture.loadFromFile("whiteArrow.png");
//
//	return sf::Sprite(texture);
//}
