#include "Ball.h"
#include <iostream> 
/* OPTIONAL: ADD BOUNCY BALL SIMULATION WITH VECTOR POINT IN THE DIRECTION OF VELOCITY AND ACCELERATION */


struct Wall
{
	 
	sf::RectangleShape bound;
	sf::Color color; 
	Wall()
	{}

	Wall(int x ,int y , int width , int height , sf::Color color)
	{
		bound.setSize(sf::Vector2f(width,height));
		bound.setOrigin(bound.getSize().x/2,bound.getSize().y/2); 
		bound.setPosition(x, y);
		bound.setFillColor(color);
		

	}

	void draw(sf::RenderWindow &window)
	{
		window.draw(bound); 
	}

	void update()
	{

	}

};
int main()
{
	int width = 600, height = 600, frameLimit = 60, borderOffset = 40, borderWidth =550, borderHeight = 30, ballSize = 30; 
	sf::RenderWindow window(sf::VideoMode(width, height), "Particle Collisions"); 
	sf::Clock clock;
	sf::Color boundColor = sf::Color::Blue, ballColor = sf::Color::Red;
	sf::Vector2f ballPos(width/2, borderOffset+borderHeight+ballSize+1), ballVel(0,0), ballAcc(0,1); 
	sf::Event event; 
	Wall bounds[4] = {Wall(width/2,borderOffset,borderWidth,borderHeight,boundColor),
					Wall(width / 2,height-borderOffset,borderWidth,borderHeight,boundColor),
					Wall(borderOffset,height / 2,borderHeight,borderWidth,boundColor),
					Wall(width - borderOffset,height / 2,borderHeight,borderWidth,boundColor) };
	Ball ball(ballSize, ballColor, ballPos,ballVel,ballAcc); 
	window.setFramerateLimit(frameLimit); 
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

		std::cout << (int)(1.f/clock.getElapsedTime().asSeconds()) << std::endl; 
		
		//update 
		for (Wall wall : bounds)
		{
			wall.update(); 
		}

		//ball.update(); 
		//update


		clock.restart().asSeconds(); 
		
		window.clear(sf::Color::Black); 
		
		//draw
		for (Wall wall : bounds)
		{
			wall.draw(window);
		}

		ball.draw(window); 

		//draw
		window.display(); 
	}
	return 0; 
}