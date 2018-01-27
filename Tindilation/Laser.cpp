#include "Laser.h"

Laser::Laser()
{
}

void Laser::render(sf::RenderWindow & t_window)
{
	sf::Vector2f meep(10, 10);
	sf::VertexArray lines(sf::LinesStrip, MAX_LASERS);
	for (int i = 0; i < MAX_LASERS; i++)
	{
		lines[i].color = sf::Color::Red;
		lines[i].position = meep;

		meep.x+=100;
		meep.y+=100;
		t_window.draw(lines);
	}
}

void Laser::loadData(LevelData t_leveloader)
{

}
