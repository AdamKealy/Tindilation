#pragma once
#include <SFML\Graphics.hpp>
#include "LevelLoader.h"

class Cable
{
public:
	static const int MAX_RECTANGLES = 10;
	static const int RECTANGLE_THICKNESS = 80;

private:
	int noOfRectangles; 
	sf::RectangleShape cableWalls[MAX_RECTANGLES];
	
public:

	Cable();
	void load(LevelData m_data);
	void draw(sf::RenderWindow & t_window);
	sf::RectangleShape * getCableArray();
};

