#include "Apple.h"

#include <SFML/Graphics.hpp>

Apple::Apple(const sf::Texture& texture)
{
	m_Sprite.setPosition(getRandomPosition());
	m_Sprite.setTexture(texture);
}

void Apple::updatePosition()
{
	m_Sprite.setPosition(getRandomPosition());
}

const sf::Sprite& Apple::getSprite()
{
	return m_Sprite;
}

const sf::Vector2f Apple::getRandomPosition()
{
	srand((unsigned)time(0));
	float posX = rand() % 1900 + 20.f;
	srand((unsigned)time(0) * 20);
	float posY = rand() % 1000 + 20.f;

	return sf::Vector2f(posX, posY);
}
