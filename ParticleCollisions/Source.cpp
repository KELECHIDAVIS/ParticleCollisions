#include "Ball.h"
#include <iostream> 
/* OPTIONAL: ADD BOUNCY BALL SIMULATION WITH VECTOR POINT IN THE DIRECTION OF VELOCITY AND ACCELERATION */

int main()
{
	int width = 600, height = 600, frameLimit = 60, borderOffset = 40, borderWidth =525, borderHeight = 8, ballSize = 30; 
	sf::RenderWindow window(sf::VideoMode(width, height), "Particle Collisions"); 
	sf::Clock clock;
	sf::Color boundColor = sf::Color::Blue, ballColor = sf::Color::Red;
	sf::Vector2f ballPos(width/2, borderOffset+borderHeight+ballSize+borderWidth/2), ballVel(100,-300), ballAcc(0,350); // Heres where you affect the ball initial accel
	sf::Event event; 
	Wall bounds[4] = {Wall(width/2,borderOffset,borderWidth,borderHeight,boundColor),
					Wall(width / 2,height-borderOffset,borderWidth,borderHeight,boundColor),
					Wall(borderOffset,height / 2,borderHeight,borderWidth,boundColor),
					Wall(width - borderOffset,height / 2,borderHeight,borderWidth,boundColor) };
	Ball ball(ballSize, ballColor, ballPos,ballVel,ballAcc); 
	window.setFramerateLimit(frameLimit); 
	Arrow arrow(ball.ball,ballVel);
	
	 
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); 
			switch (event.key.code)
			{
			case sf::Keyboard::Escape: 
				std::cout << "App Closed" << std::endl; 
				window.close(); 
				break; 
			}
		}
		//std::cout << ball.vel.x << std::endl; 
	//	std::cout << (int)(1.f/clock.getElapsedTime().asSeconds()) << std::endl; 
		
		//update 
		for (Wall wall : bounds)
		{
			wall.update(); 
		}

		ball.update(clock.getElapsedTime().asSeconds(),bounds[0],bounds[1],bounds[2],bounds[3], borderOffset);
		//update


		clock.restart().asSeconds(); 
		
		window.clear(sf::Color::Black); 
		
		//draw
		for (Wall wall : bounds)
		{
			wall.draw(window);
		}

		ball.draw(window); 
		window.draw(arrow.pointer); 
		//draw
		window.display(); 
	}
	return 0; 
}