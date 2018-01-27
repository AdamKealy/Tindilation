#include "Laser.h"

Laser::Laser()
{
	m_startPos = sf::Vector2f(0.f,0.f);
	m_endPos = sf::Vector2f(0.f, 0.f);
}

Laser::Laser(sf::Vector2f start, sf::Vector2f end)
{
	//m_startPos = m_tempPos;
	m_endPos = end;
	m_tempPos = end;

	numberOfLasers++;
}

void Laser::generateLaser()
{
	sf::VertexArray lines(sf::LinesStrip, 2);

	lines[0].position = sf::Vector2f(10, 10);
	lines[1].position = sf::Vector2f(150, 150);

	
	lines[0].color = sf::Color::Red;
	lines[1].color = sf::Color::Red;

}

void Laser::render()
{

}
