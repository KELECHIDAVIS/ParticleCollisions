#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Arrow
{
public : 
	sf::Sprite pointer;
	sf::CircleShape ball;
	sf::Texture texture;
	double angle =0 ; // in radians
	sf::Vector2f origin ; // what the arrow rotates around
	sf::Vector2f scale= sf::Vector2f(.2,.2); 
	// it is going to have a circle center where it can rotate around 
	Arrow(sf::CircleShape circle , sf::Vector2f vector); 

	//sf::Sprite loadFromFile(); 
	void update(sf::CircleShape, sf::Vector2f vel);
	void draw(sf::RenderWindow &window); 

	
};

