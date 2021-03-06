#include "PostGameWnd.h"

PostGameWnd::PostGameWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, const bool wonGame, const int attempts, const std::unique_ptr<PlayHistory>& playHistory, const std::string& whiteShareStr, const std::string& blackShareString)
	: WndInterface(bounds), _whiteShareStr(whiteShareStr), _blackShareStr(blackShareString)
{
	_resultState = WndResultState::NothingState;

	_fullScreenBackground = std::make_unique<sf::RectangleShape>(sf::Vector2f(bounds.width, bounds.height));
	_fullScreenBackground->setFillColor(sf::Color(20, 20, 20, 150));

	_background = std::make_unique<sf::RectangleShape>(sf::Vector2f(bounds.width / 2, bounds.height / 2));
	_background->setFillColor(sf::Color(60, 60, 60, 230));
	_background->setOutlineColor(sf::Color::White);
	_background->setOutlineThickness(1);
	_background->setPosition(bounds.left + bounds.width / 4 + 1, bounds.top + bounds.height / 4 + 1);

	_titleText = std::make_unique<sf::Text>((wonGame ? "Great! You did it!" : "You failed, but nice try!"), font, 40);
	_titleText->setPosition(sf::Vector2f(bounds.left + bounds.width / 2 - _titleText->getGlobalBounds().width / 2, bounds.top + bounds.height / 4 + 10));
	_titleText->setFillColor(wonGame ? sf::Color(93, 141, 74) : sf::Color(230, 93, 74));

	_solutionText = std::make_unique<sf::Text>("The word was: " + solution, font, 30);
	_solutionText->setPosition(sf::Vector2f(bounds.left + bounds.width / 2 - _solutionText->getGlobalBounds().width / 2, bounds.top + bounds.height / 4 + 10 + 50));

	_buttons.emplace_back(Button(sf::IntRect(bounds.left + bounds.width / 2 - 225, bounds.top + bounds.height * 3 / 4 - 70, 200, 60), "Play Again", 0, font));
	_buttons.emplace_back(Button(sf::IntRect(bounds.left + bounds.width / 2 + 25, bounds.top + bounds.height * 3 / 4 - 70, 200, 60), "Exit Game", 1, font));

	_buttons.emplace_back(Button(sf::IntRect(bounds.left + bounds.width * 3 / 4 + 30, bounds.top + bounds.height / 2 - 60, 240, 60), "Share in White", 2, font));
	_buttons.at(_buttons.size() - 1).setBackgroundColour(sf::Color(93, 141, 74));
	_buttons.emplace_back(Button(sf::IntRect(bounds.left + bounds.width * 3 / 4 + 30, bounds.top + bounds.height / 2 + 30, 240, 60), "Share in Black", 3, font));
	_buttons.at(_buttons.size() - 1).setBackgroundColour(sf::Color(93, 141, 74));

	sf::IntRect histogramRect = sf::IntRect(bounds.left + bounds.width / 4 + 30, bounds.top + bounds.height / 4 + 10 + 50 + 40 + 10,
		bounds.width / 2 - 60, bounds.top + bounds.height * 3 / 4 - 70 - (bounds.top + bounds.height / 4 + 10 + 50 + 40));

	_histogram = std::make_unique<HorizontalHistogram>(histogramRect, font, playHistory->getHistory(), wonGame ? attempts - 1 : -1);

	_totalPlayedText = std::make_unique<sf::Text>("Games played: " + std::to_string(playHistory->getTotalPlayed()), font, 30);
	_totalPlayedText->setPosition(sf::Vector2f(30, bounds.top + bounds.height / 2 - 75));
	_winPercentText = std::make_unique<sf::Text>("Win %: " + std::to_string(playHistory->getWinPercent()), font, 30);
	_winPercentText->setPosition(sf::Vector2f(30, bounds.top + bounds.height / 2 - 25));
	_currentStreakText = std::make_unique<sf::Text>("Current Streak: " + std::to_string(playHistory->getCurrentStreak()), font, 30);
	_currentStreakText->setPosition(sf::Vector2f(30, bounds.top + bounds.height / 2 + 25));
	_maxStreakText = std::make_unique<sf::Text>("Best Streak: " + std::to_string(playHistory->getMaxStreak()), font, 30);
	_maxStreakText->setPosition(sf::Vector2f(30, bounds.top + bounds.height / 2 + 75));
}

void PostGameWnd::draw(sf::RenderWindow& renderWindow) const
{
	renderWindow.draw(*_fullScreenBackground);
	renderWindow.draw(*_background);
	renderWindow.draw(*_titleText);
	renderWindow.draw(*_solutionText);
	renderWindow.draw(*_totalPlayedText);
	renderWindow.draw(*_winPercentText);
	renderWindow.draw(*_currentStreakText);
	renderWindow.draw(*_maxStreakText);
	_histogram->draw(renderWindow);
	for (const auto& button : _buttons)
	{
		button.draw(renderWindow);
	}
}

void PostGameWnd::handleMousePress(const sf::Vector2i& mousePosition, bool isLeft)
{
	for (auto& button : _buttons)
	{
		if (button.isPositionInside(mousePosition))
		{
			if (button.getActionID() == 0)
			{
				_resultState = WndResultState::Restart;
			}

			else if (button.getActionID() == 1)
			{
				_resultState = WndResultState::Quit;
			}

			else if (button.getActionID() == 2)
			{
				sf::Clipboard::setString(_whiteShareStr);
			}
			else if (button.getActionID() == 3)
			{
				sf::Clipboard::setString(_blackShareStr);
			}
		}
	}
}

void PostGameWnd::handleMouseMove(const sf::Vector2i& mousePosition)
{
	for (auto& button : _buttons)
	{
		button.setHovering(button.isPositionInside(mousePosition));
	}
}

WndResultState PostGameWnd::getResultState() const
{
	return _resultState;
}