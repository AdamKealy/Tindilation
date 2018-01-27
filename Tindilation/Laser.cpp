#include "Laser.h"

Laser::Laser()
{
	m_startPos = sf::Vector2f(0.f,0.f);
}

Laser::Laser(sf::Vector2f start, float angle): m_startPos(start), m_angle(angle)
{
	sf::Vertex line[2] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(150, 150))
	};
}