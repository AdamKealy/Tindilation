#include "Menu.h"

Menu::Menu()
{
	for (int i = 0;i < 5;i++)
	{
		boxes[i].setFillColor(sf::Color::Blue);
		boxes[i].setSize(sf::Vector2f(300,200));
		if (i == 0)
		{
			boxes[0].setPosition(1000,500);
		}
		boxes[i].setPosition(boxes[i-1].getPosition().x, boxes[i - 1].getPosition().y + boxes[i - 1].getSize().y * 2);
	}
}

void Menu::input(sf::Event t_event)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		
	}
}

void Menu::draw(sf::RenderWindow & t_window)
{
	for (int i = 0; i < 5; i++)
	{
		t_window.draw(boxes[i]);
	}
}
