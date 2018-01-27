#include "Mirror.h"

Mirrors::Mirrors()
{
	currentMirror = 0;
	numOfMirrors = 0;
	for (int index = 0; index < MAX_NUM; index++)
	{
		mirror[index].setFillColor(sf::Color::White);
	}
}

void Mirrors::draw(sf::RenderWindow & t_window)
{
	for (int index = 0; index <= numOfMirrors; index++)
	{
		t_window.draw(mirror[index]);
	}
}

void Mirrors::rotate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mirror[currentMirror].rotate(4);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mirror[currentMirror].rotate(-4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		currentMirror--;
		if (currentMirror < 0)
		{
			currentMirror = numOfMirrors;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		currentMirror++;
		if (currentMirror > numOfMirrors)
		{
			currentMirror = 0;
		}
	}
}

void Mirrors::loadMirrors(LevelData m_data)
{
	currentMirror = 0;
	numOfMirrors = -1;

	while(numOfMirrors + 1 < m_data.m_mrrors.size())
	{ 
		numOfMirrors++;
		mirror[numOfMirrors].setSize(sf::Vector2f(20, m_data.m_mrrors.at(numOfMirrors).length));
		mirror[numOfMirrors].setOrigin(sf::Vector2f(20/2, (m_data.m_mrrors.at(numOfMirrors).length)/2));
		mirror[numOfMirrors].setPosition(m_data.m_mrrors.at(numOfMirrors).position.x, m_data.m_mrrors.at(numOfMirrors).position.y);
	}
}
