#pragma once
#include "WndInterface.h"
#include "Button.h"

//Defines a keyboard that positions itself at the middle bottom of the bounds

class KeyboardWnd : public WndInterface
{
public:
	// Initialises the keyboard to be in the bottom center of the bounds
	KeyboardWnd(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~KeyboardWnd() = default;

	// Does nothing
	virtual void update(const float deltaTime) override {};

	// Draws all the buttons
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

	// Gets the value of actionID and resets it to default -1
	int getActionIDReset();

	// Applies colors to the pressed keyboard keys
	void applyRules(std::vector<std::string> rules);

private:
	// List of buttons of the keyboard
	std::vector<Button> _buttons;

	// Current actionID
	int _actionID;

	// Initialises the buttons of the keyboard
	void initialiseButtons(const sf::Font& font);
};

