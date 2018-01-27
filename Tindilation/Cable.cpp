#include "Cable.h"



Cable::Cable()
{	
	noOfRectangles = 0;
}

void Cable::load(LevelData m_data)
{
	for (int index = 0; index < m_data.m_cable.size(); index++)
	{
		cableWalls[index].setPosition(m_data.m_cable.at(index).position);
		cableWalls[index].setSize(sf::Vector2f(RECTANGLE_THICKNESS, m_data.m_cable.at(index).length));
		cableWalls[index].setRotation(m_data.m_cable.at(index).rotation);
	}
	noOfRectangles = m_data.m_cable.size();
}

void Cable::draw(sf::RenderWindow & t_window)
{
	for (int index = 0; index <= noOfRectangles; index++)
	{
		t_window.draw(cableWalls[index]);
	}
}
