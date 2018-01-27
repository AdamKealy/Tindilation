#include "Laser.h"

Laser::Laser()
{
	xPos = 0.f;
	yPos = 0.f;
}

Laser::Laser(float x, float y)
{
	lines[numberOfLasers].position = sf::Vector2f(x, y);
	
	numberOfLasers++;
}

void Laser::render(sf::RenderWindow & t_window)
{
	sf::VertexArray lines(sf::LinesStrip, 1);

	lines[numberOfLasers].color = sf::Color::Red;
	lines[numberOfLasers +1].color = sf::Color::Red;
	lines[numberOfLasers].position = sf::Vector2f(xPos, xPos);
	lines[numberOfLasers + 1].position = sf::Vector2f(xPos, yPos);

	t_window.draw(lines);
}
