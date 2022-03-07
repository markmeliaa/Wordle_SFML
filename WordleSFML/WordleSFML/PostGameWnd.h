#pragma once
#include "WndInterface.h"
#include "Button.h"
#include "HorizontalHistogram.h"
#include "PlayHistory.h"

// A class to represent the interface for when the player is viewing the results of their game.

class PostGameWnd : public WndInterface
{
public:
	// Initialises the window with details of the game, a choice to start a new game and a button to quit
	PostGameWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, const bool wonGame,
		const int attempts, const std::unique_ptr<PlayHistory>& playHistory, const std::string& shareStr);
	virtual ~PostGameWnd() = default;

	// Does nothing
	virtual void update(const float deltaTime) override {};

	// Draws the elements
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

	// Gets the WndResultState that changes from NothingState when the window is done
	WndResultState getResultState() const override;

private:
	// Changes when the post-game is finished
	WndResultState _resultState;

	// Buttons to choose what to do next
	std::vector<Button> _buttons;

	// Background for the interface
	std::unique_ptr<sf::RectangleShape> _background;

	// Background to cover all elements
	std::unique_ptr<sf::RectangleShape> _fullScreenBackground;

	// Title text
	std::unique_ptr<sf::Text> _titleText;

	// Text that shows the solution
	std::unique_ptr<sf::Text> _solutionText;

	// Histogram of the results of other games
	std::unique_ptr<HorizontalHistogram> _histogram;

	// Text showing the total number of played games
	std::unique_ptr<sf::Text> _totalPlayedText;

	// Text showing the win %
	std::unique_ptr<sf::Text> _winPercentText;

	// Text showing the current win streak
	std::unique_ptr<sf::Text> _currentStreakText;

	// Text showing the best win streak
	std::unique_ptr<sf::Text> _maxStreakText;

	// Text that shares the result
	std::string _shareStr;
};

