#pragma once
#include <SFML\Graphics.hpp>

class Cable
{
	int noOfRectangles; //
	static const int MAX_RECTANGLES = 10;
	sf::RectangleShape cableWalls[MAX_RECTANGLES];
	

public:
	Cable();

};

