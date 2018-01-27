#pragma once
#include "SFML\Graphics.hpp"

class Laser
{
public:
	Laser();
	Laser(sf::Vector2f start, float angle);
private:
	sf::Vector2f m_startPos;
	float m_angle;
	sf::Vertex line[2];
};