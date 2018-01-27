#pragma once
#include "SFML\Graphics.hpp"
int static numberOfLasers;

class Laser
{
public:
	Laser();
	Laser(float x,  float y);
	void render(sf::RenderWindow &t_window);
	sf::VertexArray lines;

private:
	float xPos;
	float yPos;
};