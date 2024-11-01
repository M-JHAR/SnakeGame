#ifndef APPLE_H
#define APPLE_H
#include <SFML/Graphics.hpp>

class Apple
{
private:
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
public:
	Apple(const sf::Texture& texture);
	sf::FloatRect getPosition() const;
	void updatePosition(int seed);

	const sf::Sprite& getSprite();

	const sf::Vector2f getRandomPosition(int seed);
};


#endif
