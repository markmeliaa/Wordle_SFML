#pragma once

#include <SFML/Graphics.hpp>

/*
	Defines a simple button consisting of a rectangle region,
	some text to centre in it, a hover state, and an
	actionID that is available to give the button context.
 */

class Button
{
public:
	/*
		Sets up the Button ready to be interacted with

		@param Bounds are the limits of the button
		@param actionID is a number that gives context to the button when it gets pressed
	*/
	Button(const sf::IntRect& bounds, const std::string& text, const int actionID, const sf::Font& font);
	virtual ~Button() = default;

	// Draw the button
	void draw(sf::RenderWindow& renderWindow) const;

	// Gets the actionID that determines what should be done with the button
	int getActionID() const;

	// Updates the hovering efferct to the given value
	void setHovering(const bool isHovering);
	
	// Returns true if the position clicked is inside the Button's bounds
	bool isPositionInside(const sf::Vector2i& mousePosition) const;

	// Changes the background colour of the button
	void setBackgroundColour(const sf::Color& colour);

	// Uses preset colours to change the background of the Button if required
	void applyColourID(const int colourID);

private:
	// The bounds of the rectangle for isPositionInside()
	sf::IntRect _bounds;

	// A number that detects if the button has been clicked
	int _actionID;

	// True when the mouse hovers over the key
	bool _isHovered;

	// Text in the middle of the button
	std::string _text;

	// Button background
	sf::RectangleShape _background;

	// Text render
	sf::Text _textVisual;

	// Current colour ID set via applyColourID
	int _colourID;
};

