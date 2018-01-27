#pragma once
#include "SFML\Graphics.hpp"
#include "LevelLoader.h"

int const MAX_LASERS = 17;
class Laser
{
public:
	Laser();
	Laser(float x,  float y);
	void render(sf::RenderWindow &t_window);
	sf::VertexArray lines;
	void loadData(LevelData t_leveloader);
private:
	float xPos;
	float yPos;
};