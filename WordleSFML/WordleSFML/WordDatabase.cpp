#include "WordDatabase.h"
#include <fstream>
#include <iostream>
#include <string>

WordDatabase::WordDatabase(std::default_random_engine& randomEngine)
	: _randomEngine(randomEngine)
{
	loadDatabase();
}

std::string WordDatabase::getRandomWord() const
{
	return _words.at(_randomEngine() % _words.size());
}

std::vector<std::string> WordDatabase::getListWords() const
{
	return _words;
}

void WordDatabase::loadDatabase()
{
	std::ifstream file("../words.txt");
	if (!file.is_open()) 
	{
		std::cerr << "Error: Failed to load words" << std::endl;
		return;
	}

	std::string word;
	while (std::getline(file, word))
	{
		std::transform(word.begin(), word.end(), word.begin(), ::toupper);
		_words.emplace_back(word);
	}

	file.close();

	if (_words.empty())
	{
		std::cerr << "Error: Word list loaded empty" << std::endl;
		return;
	}

	std::sort(_words.begin(), _words.end());
}