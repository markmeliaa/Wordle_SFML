#pragma once
#include "WndInterface.h"
#include "KeyboardWnd.h"
#include "GuessGrid.h"
#include "WordDatabase.h"

//Manages the keyboard and inputs from the user.

class PuzzleWnd : public WndInterface
{
public:
	// Initialises the game with a new word to be guessed
	PuzzleWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, const std::vector<std::string>& words);
	virtual ~PuzzleWnd();

	// Update the window state
	virtual void update(const float deltaTime) override;

	// Draw the components of the window
	virtual void draw(sf::RenderWindow& renderWindow) const override;

	/*
		Handles the mouse pressing at each letter position

		@param mousePosition is the position of the mouse during the press
		@param isLeft tells if the mouse button pressed is the left or the right one
	*/
	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	/*
		Handles the mouse being moved

		@param mousePosition is the mouse cursor position during the movement
	*/
	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	/*
		Handles each keyboard input

		@param keyCode is the key that gets pressed each time
	*/
	virtual void handleKeyInput(const sf::Keyboard::Key key) override;

	const GuessGrid& getGuessGrid() const;

	// Checks if the game continues or has ended
	WndResultState getResultState() const override;

	// Used to check if a word is correctly written
	std::unique_ptr<WordDatabase> _wordDatabase;

private:
	// Reference to the font that we are using
	const sf::Font& _font;

	// The game title
	sf::Text _gameTitle;

	// The text that displays the author
	sf::Text _author;

	// The keybord drawn to press the letters
	KeyboardWnd _keyboard;

	// The grid of guesses
	GuessGrid _guessGrid;

	// The current window state, changes to finished when ready to close
	WndResultState _currentState;

	// Used for the randomisation of the game
	std::default_random_engine _randomEngine;
};

