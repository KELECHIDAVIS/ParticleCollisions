#pragma once
#include <SFML/Graphics.hpp>
class Ball
{
public: 
	sf::Vector2f pos  , vel , acc;
	int size; 
	sf::Color color; 
	sf::CircleShape ball; 
	Ball(); 
	Ball(int size, sf::Color color, sf::Vector2f pos, sf::Vector2f vx, sf::Vector2f acc); 
	
	void draw(sf::RenderWindow& window); 
	void update();
};

