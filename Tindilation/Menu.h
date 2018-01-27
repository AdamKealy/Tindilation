#pragma once

#include <SFML\Graphics.hpp>

class Menu
{
	sf::RectangleShape boxes[5];

public:
	Menu();
	bool gameStart;
	void input(sf::Event t_event);
	void draw(sf::RenderWindow & t_window);
};