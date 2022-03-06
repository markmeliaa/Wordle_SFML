#pragma once
#include "WndInterface.h"
#include "PuzzleLetter.h"

// Shows a grid of guesses with methods to insert or remove letters for the current guess.

class GuessGrid : public WndInterface
{
public:
	// Initialises the full grid as empty elements that will be filled
	GuessGrid(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, int maxGuesses);
	virtual ~GuessGrid() = default;

	// Does nothing
	virtual void update(const float deltaTime) override {};

	// Draws the grid of guessed letters
	virtual void draw(sf::RenderWindow& renderWindow) const override;

	/*
		Handles the key input from the keyboard

		@param keyCode is the code of the key that was pressed
	*/
	virtual void handleKeyInput(const sf::Keyboard::Key key) override;

	// Inserts the letter if there is room in the current guess
	void tryInsertLetter(const char letter);

	// Removes one letter if possible (does nothing if there is no letter to remove in the current guess)
	void backSpace();
	
	// Tests the given word
	void checkSolution();

	// Check if the solution is correct
	bool isSolved() const;

	// Check if the user has run out of guesses
	bool hasMoreGuesses() const;

	// Get the rules based on guesses
	std::vector<std::string> getAllRules() const;

	// Get and reset the changed keys state
	bool getKeyCheckReset();

	// Get the solution that the user is matching
	std::string getSolution() const;

	// Gets a string representing the final state of the puzzle
	std::string getShareString() const;

private:
	// The collection of letters
	std::vector<std::vector<PuzzleLetter>> _guessLetters;

	// Position for the next insertion
	int _insertPosition;

	// Position for the current word
	int _currentWordIndex;

	// When true it means the solution is found
	bool _solved;

	// Used keys
	bool _usedKeyCheck;

	// Solution to check against
	const std::string _solution;

	// Creates an empy grid based on the size given
	void initialiseAllGuesses(const sf::Font& font, const int wordLenght, const int maxGuesses);
};

