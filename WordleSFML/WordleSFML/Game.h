#pragma once
#include "WndInterface.h"
#include <random>
#include "WordDatabase.h"
#include "PlayHistory.h"

//Manages instances of the puzzle window

class Game
{
public:
	// Initialises each game lobby
	Game(const sf::IntRect& gameBounds, const sf::Font& font);
	virtual ~Game();

	// Updates the state of the current window
	void update(const float deltaTime);

	// Draws the actual window
	void draw(sf::RenderWindow& renderWindow) const;

	// Handles passing the mouse press event on to the active interface
	void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft);

	// Handles passing the mouse moved event to the active interface
	void handleMouseMove(const sf::Vector2i& mousePosition);

	// Handles passing key pressed event to the active interface
	void handleKeyInput(const sf::Keyboard::Key key);

	// When true, the game closes
	bool getGameCloseRequested();

private:
	// Bounds of the game area
	const sf::IntRect _bounds;

	// Font of the game reference
	const sf::Font& _font;

	// Used for the randomisation of the game
	std::default_random_engine _randomEngine;

	// Reference to the active game window
	WndInterface* _activeInterface;
	
	// Reference to the active game window overlay (stats)
	WndInterface* _activeOverlay;

	// When true, the game should end
	bool _terminateGame;

	// Word collection
	std::unique_ptr<WordDatabase> _wordDatabase;

	// Player history
	std::unique_ptr<PlayHistory> _playHistory;
};
