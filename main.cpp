#include "Snake.h"
#include "Apple.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

int main()
{


	sf::VideoMode vm(1920, 1080);

	sf::RenderWindow window(vm, "SnakeGame", sf::Style::Fullscreen);

	sf::Texture textureApple;
	textureApple.loadFromFile("graphics/apple.png");

	Apple apple(textureApple);

	Snake snake(1920.f / 2, 10);

	int score{ 0 };
	sf::Font font;
	sf::Text textScore;
	std::cerr << font.loadFromFile("fonts/DS-DIGIT.ttf");
	textScore.setPosition(20.f, 20.f);
	textScore.setFont(font);
	textScore.setCharacterSize(75);
	textScore.setFillColor(sf::Color::White);
	textScore.setString("Score : 0");

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

		if (apple.getPosition().intersects(snake.getPosition()))
		{
			score++;
			apple.updatePosition(score); // this score is used to seed the random pos

		}

		//UPDATE GAMEOBJECTS
		sf::Time dt = clock.restart();
		snake.update(dt);

		std::stringstream ss;
		ss << "Score : " << score;
		textScore.setString(ss.str());


		//DRAW GAMEOBJECTS
		window.clear();
		window.draw(snake.getShape());
		window.draw(apple.getSprite());
		window.draw(textScore);
		window.display();
	}

	return 0;
}