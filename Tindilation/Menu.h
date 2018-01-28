#pragma once

#include <SFML\Graphics.hpp>

class Menu
{
	sf::RectangleShape boxes[5];
	sf::Font m_font;
	sf::Text m_message[5];
public:
	Menu();
	bool gameStart;
	int optionSelct;
	void input(sf::Event t_event, sf::RenderWindow & t_window);
	int draw(sf::RenderWindow & t_window);
	void changeTextMainMenu();
	void changeTextLevelSelect();
};