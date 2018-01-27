#pragma once

#include <SFML/Graphics.hpp>
#include "LevelLoader.h"

class Mirrors
{
	static const int MAX_NUM = 10;
	static const int MIRROR_THICKNESS = 50;
	sf::RectangleShape mirror[MAX_NUM];
	int currentMirror;
	int numOfMirrors;
public:
	Mirrors();
	void draw(sf::RenderWindow & t_window);
	void rotate();
	void loadMirrors(LevelData m_data);
};