#include "Laser.h"

Laser::Laser()
{
	xPos = 0.f;
	yPos = 0.f;
}

Laser::Laser(float x, float y)
{
	//lines[].position = sf::Vector2f(x, y);
}

void Laser::render(sf::RenderWindow & t_window)
{
	t_window.draw(lines);
}

void Laser::loadData(LevelData t_leveloader)
{
	sf::VertexArray lines(sf::LinesStrip, MAX_LASERS);
	
	for (int i = 0; i < MAX_LASERS; i++)
	{
		lines[i].color = sf::Color::Red;
		lines[i].position = sf::Vector2f(xPos, xPos);
	}
}
