#include "SnakeTail.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
SnakeTail::SnakeTail(Snake* snake)
{
	m_SnakeToFoloow = snake;
	m_Shape.setSize(sf::Vector2f(25.f, 25.f));
	m_Shape.setPosition(snake->getShape().getPosition());
}

const sf::RectangleShape SnakeTail::getShape() const
{
	return m_Shape;
}


void SnakeTail::update(int i, sf::Time)
{
	i = (i + 1) * 25;
	sf::Vector2f vec = m_SnakeToFoloow->getShape().getPosition();

	if (m_SnakeToFoloow->isMovingRight())
		vec.x = (vec.x - i);
	if (m_SnakeToFoloow->isMovingLeft())
		vec.x = (vec.x + i);
	if (m_SnakeToFoloow->isMovingDown())
		vec.y = (vec.y - i);
	if (m_SnakeToFoloow->isMovingUp())
		vec.y = (vec.y + i);

	m_Shape.setPosition(vec.x, vec.y);
}

