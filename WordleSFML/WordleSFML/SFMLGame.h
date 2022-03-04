#pragma once

#include "Game.h"

//Manages the sf::RenderWindow and game loop by 
//passing information to the Game class.

class SFMLGame
{
public:
	// Initialises de game
	SFMLGame();
	virtual ~SFMLGame() = default;

	// Continues running the game
	void gameLoop();

private:
	// The window that the game uses
	sf::RenderWindow _window;

	// The font used throughout the whole game
	sf::Font _font;

	// Load the used font
	static sf::Font loadFont();

	// Reference to the Game object that manages all interfaces
	Game _game;
};


