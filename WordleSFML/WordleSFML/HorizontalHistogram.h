#pragma once

#include "HistogramBar.h"
#include <vector>

// Represents the collection of histogram bars

class HorizontalHistogram
{
public:
	// Initialises the data into the bounds and highlights one bar (optional)
	HorizontalHistogram(const sf::IntRect& bounds, const sf::Font& font, std::vector<std::pair<int, int>> data, const int highlightIndex);
	virtual ~HorizontalHistogram() = default;

	// Draws the bars
	void draw(sf::RenderWindow& renderWindow) const;

private:
	// The collection of bars to be drawn
	std::vector<std::unique_ptr<HistogramBar>> _bars;
};

