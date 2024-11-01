#ifndef SNAKE_TAIL_H
#define SNAKE_TAIL_H
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SnakeTail
{
private:
	Snake* m_SnakeToFoloow = NULL;
	sf::RectangleShape m_Shape;

public:
	SnakeTail(){}
	SnakeTail(Snake* snake);

	const sf::RectangleShape getShape()const;
	//void followSnake();
	void update(int i, sf::Time dt);
};

#endif

