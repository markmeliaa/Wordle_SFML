#pragma once
#include <vector>
#include <string>

//Manages a history of played games storing the results to a file.

class PlayHistory
{
public:
	// Loads the save data from the specified file or creates a new one
	PlayHistory(const std::string& saveFileName);
	virtual ~PlayHistory() = default;

	// Inserts the data into the history
	void insertHistory(const int countToIncrement);

	// Inserts a loss
	void insertHistoryLoss();

	// Reference to the history
	const std::vector<std::pair<int, int>>& getHistory() const;

	// Gets total played games
	int getTotalPlayed() const;

	// Gets current streak of wins
	int getCurrentStreak() const;

	// Gets maximum win streak
	int getMaxStreak() const;

	// Gets win %
	int getWinPercent() const;

private:
	// The history of all saved games
	std::vector<std::pair<int, int>> _playHistory;

	// Total games played
	int _totalPlayed;

	// Total games won
	int _totalWon;

	// Current win streak
	int _currentStreak;

	// Max streak
	int _maxStreak;

	// Reference to the file with the save history
	std::string _saveFileName;

	// Loads the file
	void loadFile();

	// Saves the history into the file
	void saveFile();

	// Initialises a default dataset with all 0s
	void initialiseDefault();
};

