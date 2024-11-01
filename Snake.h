#ifndef SNAKE_H
#define SNAKE_H
#include <SFML/Graphics.hpp>


class Snake
{
private:
	sf::Vector2f m_Position;
	sf::RectangleShape m_Shape;

	float m_Speed = 400.f;
	bool m_MovingLeft = false;
	bool m_MovingRight = false;
	bool m_MovingUp = false;
	bool m_MovingDown = true;

public:
	Snake(float startX, float startY);

	sf::FloatRect getPosition() const;
	sf::RectangleShape getShape() const;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	const bool isMovingLeft();
	const bool isMovingDown();
	const bool isMovingUp();
	const bool isMovingRight();

	void update(sf::Time dt);
	
};


#endif