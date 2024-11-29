#ifndef SEARCHBOXH
#define SEARCHBOXH

#include <iostream>
#include "Cursor.h"
#include "Helper/Fonts.h"
#include "Helper/Position.h"
#include <string>

class SearchBox : public sf::RectangleShape
{
private:
	sf::Text _text;
	sf::Text _label;
	Cursor _cursor;

	void enterInput(char c);
	void backspace();
	void adjustCursor();

public:
	SearchBox(float width = 0.f, float height = 0.f, int fontSize = 0.f, const std::string& label = "");
	void init(float width, float height, int fontSize, const std::string& label);
	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event& event);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& pos);

	void setText(const std::string& text);
	std::string getText();


};

#endif