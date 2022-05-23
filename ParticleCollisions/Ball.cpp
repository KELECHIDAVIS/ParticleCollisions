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
	this->vel = vx; 
	this->acc = acc; 
	ball.setPosition(pos); 
	
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(ball); 
}

void Ball::update(double deltaTime , Wall upper , Wall lower , Wall left , Wall right , int borderOffset)
{
	if (ball.getPosition().y >= (lower.bound.getPosition().y - lower.bound.getSize().y / 2)-ball.getRadius())
	{
		ball.setPosition(ball.getPosition().x, (lower.bound.getPosition().y - lower.bound.getSize().y / 2) - ball.getRadius() - rebound); 
		vel.y *= -1; 
	}

	if (ball.getPosition().y <= ball.getRadius()+upper.bound.getSize().y+borderOffset)
	{
		ball.setPosition(ball.getPosition().x, ball.getRadius()+upper.bound.getSize().y + borderOffset+rebound);
		vel.y *= -1;
	}


	if (ball.getPosition().x <= ball.getRadius() + left.bound.getSize().x + borderOffset)
	{
		ball.setPosition(ball.getRadius() + left.bound.getSize().x + borderOffset+rebound, ball.getPosition().y);
		vel.x *= -1;
	}


	if (ball.getPosition().x >= right.bound.getPosition().x- right.bound.getSize().x/2 -ball.getRadius())
	{
		ball.setPosition(ball.getRadius() + left.bound.getSize().x + borderOffset + rebound, ball.getPosition().y);
		vel.x *= -1;
	}
	vel.x += acc.x*deltaTime; 
	vel.y += acc.y * deltaTime;
	pos.x += vel.x * deltaTime;
	pos.y += vel.y * deltaTime;
	ball.setPosition(pos); 
}
