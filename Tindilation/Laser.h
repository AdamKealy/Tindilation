#pragma once
#include "SFML\Graphics.hpp"
#include "LevelLoader.h"

int const MAX_LASERS = 17;
class Laser
{
public:
	Laser();
	void render(sf::RenderWindow &t_window);
	void loadData(LevelData t_data);
private:
	sf::VertexArray lines;
	sf::Vector2f startPos;
};