#include "Mirror.h"

Mirrors::Mirrors()
{
	currentMirror = 0;
	numOfMirrors = 0;
	mirror[0].setFillColor(sf::Color::Yellow);
	for (int index = 1; index < MAX_NUM; index++)
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

void Mirrors::rotate(sf::Event t_event)
{
	if (t_event.key.code == sf::Keyboard::Right)
	{
		mirror[currentMirror].rotate(rotationValue);
		if (rotationValue < MAX_ROTATE)
		{
			rotationValue++;
		}
	}
	else if (t_event.key.code == sf::Keyboard::Left)
	{
		mirror[currentMirror].rotate(-rotationValue);
		if (rotationValue < MAX_ROTATE)
		{
			rotationValue++;
		}
	}
	else
	{
		rotationValue = 0;
	}
	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::Up)
		{
			mirror[currentMirror].setFillColor(sf::Color::White);
			currentMirror--;
			if (currentMirror < 0)
			{
				currentMirror = numOfMirrors;
			}
			mirror[currentMirror].setFillColor(sf::Color::Yellow);
		}
		else if (t_event.key.code == sf::Keyboard::Down)
		{
			mirror[currentMirror].setFillColor(sf::Color::White);
			currentMirror++;
			if (currentMirror > numOfMirrors)
			{
				currentMirror = 0;
			}
			mirror[currentMirror].setFillColor(sf::Color::Yellow);
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

sf::RectangleShape* Mirrors::getMirrorArray()
{
	return mirror;
}
