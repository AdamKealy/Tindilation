#pragma once

#include <SFML/Graphics.hpp>
#include "LevelLoader.h"

class Mirrors
{
public:
	static const int MAX_NUM = 10;
	static const int MIRROR_THICKNESS = 50;
	static const int MAX_ROTATE = 10;

private:	
	sf::RectangleShape mirror[MAX_NUM];
	int currentMirror;
	int numOfMirrors;
	int rotationValue;

public:

	Mirrors();
	void draw(sf::RenderWindow & t_window);
	void rotate(sf::Event t_event);
	void loadMirrors(LevelData m_data);
	sf::RectangleShape* getMirrorArray();
};