#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(int size, sf::Color color, sf::Vector2f pos, sf::Vector2f vx, sf::Vector2f acc)
{
	ball = sf::CircleShape(size);
	ball.setFillColor(color); 
	ball.setOrigin(size,size);
	this->pos = pos; 
	this->vel = vel; 
	this->acc = acc; 
	ball.setPosition(pos); 

}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball); 
}

void Ball::update()
{
	vel.x += acc.x; 
	vel.y += acc.y; 
	pos.x += vel.x; 
	pos.y += vel.y; 
	ball.setPosition(pos); 
}
