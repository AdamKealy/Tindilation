#pragma once
#include "SFML\Graphics.hpp"

sf::Vector2f static m_tempPos;
int static numberOfLasers;

class Laser
{
public:
	Laser();
	Laser(sf::Vector2f start,  sf::Vector2f end);
	void generateLaser();
	void render();
	sf::VertexArray lines;
private:
	sf::Vector2f m_startPos;
	sf::Vector2f m_endPos;
};