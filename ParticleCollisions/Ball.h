#pragma once

#include "Arrow.h"
struct Wall
{

	sf::RectangleShape bound;
	sf::Color color;
	
	Wall()
	{}

	Wall(int x, int y, int width, int height, sf::Color color)
	{
		bound.setSize(sf::Vector2f(width, height));
		bound.setOrigin(bound.getSize().x / 2, bound.getSize().y / 2);
		bound.setPosition(x, y);
		bound.setFillColor(color);


	}

	void draw(sf::RenderWindow& window)
	{
		window.draw(bound);
	}

	void update()
	{

	}

};

class Ball
{
public: 
	sf::Vector2f pos  , vel , acc;
	int size, rebound = 5;;
	sf::Color color; 
	sf::CircleShape ball; 
	Ball(); 
	Ball(int size, sf::Color color, sf::Vector2f pos, sf::Vector2f vx, sf::Vector2f acc); 
	
	void draw(sf::RenderWindow& window); 
	void update(double deltaTime, Wall upper, Wall lower, Wall left, Wall right, int borderOffset);
};

