#include "Word.h"

Word::Word(const std::string& text, int priority, int fontSize, Fonts::fontEnum font)
{
	init(text, priority, fontSize, font);
}

void Word::init(const std::string& text, int priority, int fontSize, Fonts::fontEnum font)
{
	this->setFont(Fonts::getFont(font));
	this->setString(text);
	this->setCharacterSize(fontSize);
	_priority = priority;
}

bool operator<(const Word& word1, const Word& word2)
{
	return word1._priority < word2._priority;
}

bool operator<=(const Word& word1, const Word& word2)
{
	return word1._priority <= word2._priority;
}

bool operator>(const Word& word1, const Word& word2)
{
	return word1._priority > word2._priority;
}

bool operator>=(const Word& word1, const Word& word2)
{
	return word1._priority >= word2._priority;
}

bool operator==(const Word& word1, const Word& word2)
{
	return word1._priority == word2._priority;
}
