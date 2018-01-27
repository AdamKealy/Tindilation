// author Peter Lowe
// no, Adam did it. ;)
#ifndef GAME
#define GAME

#include "Laser.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	//int static const MAX_LASERS = 0;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_backgroundTexture; // texture used for sfml logo
	sf::Sprite m_backgroundSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	Laser m_laser;
};

#endif // !GAME

