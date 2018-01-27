#include "Laser.h"

Laser::Laser()
{
}

void Laser::render(sf::RenderWindow & t_window)
{
	/*meep=sf::Vector2f(50, 130);
	sf::VertexArray lines(sf::LinesStrip, MAX_LASERS);
	for (int i = 0; i < MAX_LASERS; i++)
	{
		lines[i].color = sf::Color::Red;
		lines[i].position = meep;

		if (i%2 == 0)
		{
		meep.x+=100;
		meep.y+=100;
		}
		else
		{
		meep.x += 100;
		meep.y -= 100;
		}
		
	}*/
	t_window.draw(lines);
}

void Laser::loadData(LevelData t_leveloader)
{

}

void Laser::collision(sf::RectangleShape mirror[], sf::RectangleShape pipe[], int const MAX_MIRROR, int const MAX_PIPE)
{
	/*if (mirror->getGlobalBounds().intersects(lines.getBounds())
	{
		collides = true;
	}*/
}
