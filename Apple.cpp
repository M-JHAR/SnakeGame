#include "Apple.h"

#include <SFML/Graphics.hpp>

Apple::Apple(const sf::Texture& texture)
{
	m_Sprite.setPosition(getRandomPosition(1));
	m_Sprite.setTexture(texture);
}

sf::FloatRect Apple::getPosition() const
{
	return m_Sprite.getGlobalBounds();
}

void Apple::updatePosition(int seed)
{
	m_Sprite.setPosition(getRandomPosition(seed));
}

const sf::Sprite& Apple::getSprite()
{
	return m_Sprite;
}

const sf::Vector2f Apple::getRandomPosition(int seed)
{
	srand((unsigned)time(0) * 10 * seed);
	float posX = rand() % 1800 + 20.f;
	srand((unsigned)time(0) * 20 * seed);
	float posY = rand() % 1000 + 40.f;

	return sf::Vector2f(posX, posY);
}
