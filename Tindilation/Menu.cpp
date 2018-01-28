#include "Menu.h"

Menu::Menu()
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		//error
	}

	for (int i = 0;i < 5;i++)
	{
		boxes[i].setFillColor(sf::Color::White);
		boxes[i].setSize(sf::Vector2f(900,135));
		if (i == 0)
		{
			boxes[0].setPosition(1300, boxes[0].getSize().y);
		}
		else
		{
			boxes[i].setPosition(boxes[i - 1].getPosition().x, boxes[i - 1].getPosition().y + boxes[i - 1].getSize().y * 2);
		}
		m_message[i].setFont(m_font);
		m_message[i].setCharacterSize(120);
		m_message[i].setPosition(boxes[i].getPosition());
		m_message[i].setFillColor(sf::Color::Black);
	}
	gameStart = false;
	optionSelct = 10;
}

void Menu::input(sf::Event t_event, sf::RenderWindow & t_window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (sf::Mouse::getPosition().x - t_window.getPosition().x > boxes[0].getPosition().x &&
			sf::Mouse::getPosition().x - t_window.getPosition().x < boxes[0].getPosition().x + boxes[0].getSize().x)
		{ 
			for (int i = 0; i < 5; i++)
			{
				if (sf::Mouse::getPosition().y - t_window.getPosition().y - 55> boxes[i].getPosition().y &&
					sf::Mouse::getPosition().y - t_window.getPosition().y - 55< boxes[i].getPosition().y + boxes[i].getSize().y)
				{
					if (optionSelct != 1)
					{
						optionSelct = i;
					}
					else
					{
						optionSelct = i + 5;
					}
				}
			}
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		optionSelct = 10;
	}
}

int Menu::draw(sf::RenderWindow & t_window)
{
	switch (optionSelct)
	{
	case 0:
		//start from level 1
		gameStart = true;
		return 1;
		break;
	case 1:
		changeTextLevelSelect();
		for (int i = 0; i < 5; i++)
		{
			t_window.draw(boxes[i]);
			t_window.draw(m_message[i]);
		}
		break;
	case 2:
		//help screen
		m_message[0].setString("Help");
		t_window.draw(m_message[0]);
		break;
	case 3:
		//creators
		m_message[0].setString("Creators");
		t_window.draw(m_message[0]);
		break;
	case 4:
		t_window.close();
		break;
	case 5:
		//play level 1
		gameStart = true;
		return 1;
		break;
	case 6:
		//play level 2
		gameStart = true;
		return 2;
		break;
	case 7:
		//play level 3
		gameStart = true;
		return 3;
		break;
	case 8:
		//play level 4
		gameStart = true;
		return 4;
		break;
	case 9:
		//play level 5
		gameStart = true;
		return 5;
		break;
	default:
		changeTextMainMenu();
		for (int i = 0; i < 5; i++)
		{
			t_window.draw(boxes[i]);
			t_window.draw(m_message[i]);
		}
		break;
	}
	return 6;
}

void Menu::changeTextMainMenu()
{
	m_message[0].setString("Start Game");
	m_message[1].setString("Level Select");
	m_message[2].setString("Help");
	m_message[3].setString("Creators");
	m_message[4].setString("Exit");
}

void Menu::changeTextLevelSelect()
{
	m_message[0].setString("Level 1");
	m_message[1].setString("Level 2");
	m_message[2].setString("Level 3");
	m_message[3].setString("Level 4");
	m_message[4].setString("Level 5");
}
