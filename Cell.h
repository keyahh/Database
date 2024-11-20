#ifndef CELLH
#define CELLH

#include <string>

class Cell
{
private:
	std::string _text;

public:
	Cell(const std::string& text = "");

	const std::string& getText() const;
	void setText(const std::string& text);
};

#endif