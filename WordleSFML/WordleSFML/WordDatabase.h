#pragma once

#include <vector>
#include <random>

//Manages a collection of words.

class WordDatabase
{
public:
	// Initialises the word database with its file
	WordDatabase(std::default_random_engine& randomEngine);
	virtual ~WordDatabase() = default;

	// Returns true if the word typed is in the database
	bool isValidWord(const std::string& word) const;

	// Returns a random word from the database
	std::string getRandomWord() const;

private:
	// The database
	std::vector<std::string> _words;

	// Used for the randomisation of the game
	std::default_random_engine& _randomEngine;

	// Loads the word list and sorts it in alphabetical order
	void loadDatabase();
};

