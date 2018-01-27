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
	sf::Vector2f startPos= sf::Vector2f(0.f,0.f);
	sf::Vector2f meep;
private:
	sf::VertexArray lines;
	std::vector<sf::RectangleShape> m_lasers;
	bool collides;
};