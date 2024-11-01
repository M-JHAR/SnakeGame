#include "Snake.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::VideoMode vm(1920, 1080);

	sf::RenderWindow window(vm, "SnakeGame", sf::Style::Fullscreen);

	Snake snake(1920.f / 2, 10);


	sf::Clock clock;

	while (window.isOpen())
	{
		//HANDLE PLAYER INPUT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			if (!snake.isMovingRight())
				snake.moveLeft();

		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			if (!snake.isMovingLeft())
				snake.moveRight();

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			if (!snake.isMovingDown())
				snake.moveUp();

		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			if (!snake.isMovingUp())
				snake.moveDown();

		}



		//UPDATE GAMEOBJECTS
		sf::Time dt = clock.restart();
		snake.update(dt);


		//DRAW GAMEOBJECTS
		window.clear();
		window.draw(snake.getShape());

		window.display();
	}

	return 0;
}