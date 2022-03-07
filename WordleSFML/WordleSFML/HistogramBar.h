#pragma once

#include <SFML/Graphics.hpp>

// Represents a single bar on a histogram.

class HistogramBar
{
public:
	// Initialises the histogram bar with its text and size
	HistogramBar(const sf::IntRect& bounds, const sf::Font& font, const int title, const int value, const int max);
	virtual ~HistogramBar() = default;

	// Draws the bar
	void draw(sf::RenderWindow& renderWindow) const;

	// Changes the bar colour to the specified colour
	void setBarColour(const sf::Color& colour);

private:
	// The title text on the left
	std::unique_ptr<sf::Text> _titleText;

	// The visual bar
	std::unique_ptr<sf::RectangleShape> _bar;

	// The value of the element
	std::unique_ptr<sf::Text> _valueText;
};