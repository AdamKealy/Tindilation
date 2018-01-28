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
	void collision(sf::RectangleShape mirror[], sf::RectangleShape pipe[], int const MAX_MIRROR, int const MAX_PIPE);
	sf::Vector2f rotate(sf::Vector2f vector, int angle);

private:
	sf::RectangleShape m_lasers[MAX_LASERS];
	bool m_collides;
	int const LASER_GIRTH = 35;
	int m_rotation;
	sf::VertexArray lasers;
	sf::Vector2f lineUp;
	sf::RectangleShape endPoint;
};