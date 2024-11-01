#include "Snake.h"

#include <SFML/Graphics.hpp>

Snake::Snake(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(25.f, 25.f));
	m_Shape.setPosition(m_Position);
}

sf::FloatRect Snake::getPosition() const
{
	return m_Shape.getGlobalBounds();
}

sf::RectangleShape Snake::getShape() const
{
	return m_Shape;
}

void Snake::moveLeft()
{
	m_MovingLeft = true;
	m_MovingRight = m_MovingUp = m_MovingDown = false;
}

void Snake::moveRight()
{
	m_MovingRight = true;
	m_MovingLeft = m_MovingUp = m_MovingDown = false;
}

void Snake::moveUp()
{
	m_MovingUp = true;
	m_MovingLeft = m_MovingRight = m_MovingDown = false;
}

void Snake::moveDown()
{
	m_MovingDown = true;
	m_MovingLeft = m_MovingRight = m_MovingUp = false;
}

const bool Snake::isMovingLeft()
{
	return m_MovingLeft;
}

const bool Snake::isMovingDown()
{
	return m_MovingDown;
}

const bool Snake::isMovingUp()
{
	return m_MovingUp;
}

const bool Snake::isMovingRight()
{
	return m_MovingRight;
}




void Snake::update(sf::Time dt)
{
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * dt.asSeconds();
	}
	if (m_MovingDown)
	{
		m_Position.y += m_Speed * dt.asSeconds();
	}
	if (m_MovingLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}
