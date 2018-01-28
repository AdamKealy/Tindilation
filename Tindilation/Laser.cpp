#include "Laser.h"

Laser::Laser():lasers(sf::LinesStrip, 0)
{
	endPoint.setSize(sf::Vector2f(1, 1));
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
	//t_window.draw(lines);
	t_window.draw(lasers);
}

void Laser::loadData(LevelData t_leveloader)
{
	m_lasers[0].setPosition(t_leveloader.m_laser.position);
	m_lasers[0].setRotation(t_leveloader.m_laser.rotation);
	lasers.append(sf::Vertex(t_leveloader.m_laser.position, sf::Color::Red));
	m_rotation = t_leveloader.m_laser.rotation;
}

void Laser::collision(sf::RectangleShape mirror[], sf::RectangleShape pipe[], int const MAX_MIRROR, int const MAX_PIPE)
{
	/*if (mirror->getGlobalBounds().intersects(lines.getBounds())
	{
		collides = true;
	}*/
	m_collides = false;
	sf::Vector2f temp;
	
	for (int i = 0; i < MAX_LASERS;i++)
	{
		temp = rotate(sf::Vector2f(1, 1), m_rotation);
		while (!m_collides)
		{
			if (lineUp.x <0 || lineUp.x > 3500 || lineUp.y < 0 || lineUp.y > 1500)
			{
				lasers.append(sf::Vertex(lineUp, sf::Color::Red));
				break;
			}

			lineUp += temp;
			endPoint.setPosition(lineUp);
			for (int mirrI = 0; mirrI < MAX_MIRROR;mirrI++)
			{
				if (endPoint.getGlobalBounds().intersects(mirror[mirrI].getGlobalBounds()))
				{
					m_collides = true;
					m_rotation = 180 - (m_lasers[i].getRotation() - mirror[mirrI].getRotation());
					mirrI = MAX_MIRROR;
				}
			}
			for (int pipeI = 0; pipeI < MAX_PIPE; pipeI++)
			{
				if (endPoint.getGlobalBounds().intersects(pipe[pipeI].getGlobalBounds()))
				{
					m_collides = true;
					m_rotation = 180 - (m_lasers[i].getRotation() - pipe[pipeI].getRotation());
					pipeI = MAX_PIPE;
				}
			}

		}
		lasers.append(sf::Vertex(lineUp, sf::Color::Red));
	}
}

sf::Vector2f Laser::rotate(sf::Vector2f vector, int angle)
{
	double radians = (acos(-1.0f) / 180.0f) * angle;
	return sf::Vector2f(vector.x * cos(radians) + vector.y * -sin(radians), vector.x * sin(radians) + vector.y * cos(radians));
}
