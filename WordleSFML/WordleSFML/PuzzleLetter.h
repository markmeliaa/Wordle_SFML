#include <SFML/Graphics.hpp>

// Defines a letter that is drawn in a box.

class PuzzleLetter
{
public:
	// Defines the state for the solution
	enum SolutionState { NO_STATE, CORRECT, WRONG_POS };

	// Defaults to an empty letter at the position
	PuzzleLetter(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~PuzzleLetter() = default;

	// Draws the button
	void draw(sf::RenderWindow& renderWindow) const;

	// Gets the letter associated
	char getLetter() const;

	// Sets the letter to the selected letter
	void setLetter(const char letter);

	// Changes the background colour and stores the solution state
	void setSolutionState(const SolutionState& solutionState);

	// Get solution state of this element
	SolutionState getSolutionState() const;

private:
	// The bounds of the rectangle for isPositionInside()
	sf::IntRect _bounds;

	// The character shown on the puzzle letter
	char _letter;

	// Letter background
	sf::RectangleShape _background;

	// Text Render
	sf::Text _textVisual;

	// The current solution state of the letter
	SolutionState _currentState;

	// Changes the background to the selected colour
	void setBackgroundColour(const sf::Color& colour);
};