#ifndef WORDH
#define WORDH

#include "SFML/Graphics.hpp"
#include "Helper/Fonts.h"
#include <string>

class Word : public sf::Text
{
private:
	int _priority = 0;

public:
	Word(const std::string& text = "", int priority = 0, int fontSize = 30, Fonts::fontEnum font = Fonts::OPEN_SANS_REGULAR);
	void init(const std::string& text, int priority, int fontSize, Fonts::fontEnum font);

	friend bool operator<(const Word& word1, const Word& word2);
	friend bool operator<=(const Word& word1, const Word& word2);
	friend bool operator>(const Word& word1, const Word& word2);
	friend bool operator>=(const Word& word1, const Word& word2);
	friend bool operator==(const Word& word1, const Word& word2);
};

#endif