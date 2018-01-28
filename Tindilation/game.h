// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Laser.h"
#include "Mirror.h"
#include "Cable.h"
#include "Menu.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_backgroundTexture; // texture used for sfml logo
	sf::Sprite m_backgroundSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	Mirrors m_mirrors;
	LevelData m_level;
	Laser m_laser;
	Cable m_cable;
	Menu m_menu;
};

#endif // !GAME

