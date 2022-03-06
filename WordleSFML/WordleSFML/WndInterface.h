#pragma once

#include <SFML/Graphics.hpp>

// States available for returning from WndInterface::getResultState().
enum WndResultState { NothingState, Finished, Restart, Menu, Quit };

// Defines a pure virtual class to use for multiple interfaces.

class WndInterface
{
public:
	/*
		Initialise the interface with bounds and enables it

		@param bounds are the bounds of the interface
	*/
	WndInterface(sf::IntRect bounds) : _bounds(bounds), _isEnabled(true) {};
	virtual ~WndInterface() = default;

	/*
		Update the elements of the interface

		@param deltaTime Time spent since last update
	*/
	virtual void update(const float deltaTime) = 0;

	/*
		Draw elements of the interface

		@param renderWindow Reference to the target window to be rendered
	*/
	virtual void draw(sf::RenderWindow& renderWindow) const = 0;

	/*
		Handles the mouse pressing at each letter position

		@param mousePosition is the position of the mouse during the press
		@param isLeft tells if the mouse button pressed is the left or the right one
	*/
	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) {};

	/*
		Handles the mouse being moved

		@param mousePosition is the mouse cursor position during the movement
	*/
	virtual void handleMouseMove(const sf::Vector2i& mousePosition) {};

	/*
		Handles each keyboard input

		@param keyCode is the key that gets pressed each time
	*/
	virtual void handleKeyInput(const sf::Keyboard::Key key) {};

	/*
		Change the Enabled state of this object

		@param enabled New state to set the enabled/disabled state of this object
	*/
	void setEnabled(bool enabled) { _isEnabled = enabled; };

	/*
		Get the current Enabled state of the object

		@return True if the object is Enabled
	*/
	bool isEnabled() const { return _isEnabled; };

	// By default this method returns WndResultState::Nothing unless it gets overriden
	virtual WndResultState getResultState() const { return WndResultState::NothingState; };

protected:
	// Bounds of the interface
	sf::IntRect _bounds;

	// If the object is Enabled it can be used for managing updates
	bool _isEnabled;
};

