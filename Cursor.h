#ifndef CURSORH
#define CURSORH

#include "SFML/Graphics.hpp"

class Cursor : public sf::RectangleShape
{
private:
	bool _visible = true;
	float maxBlinkDelay = .5f, blinkTime = .0f;
	sf::Color _color;
	void toggleVisible();

public:
	Cursor();
	Cursor(float width, float height, sf::Color color, float blinkTime);
	void init(float width, float height, sf::Color color, float blinkTime);

	void update(float dt);
	void enteredText();
};

#endif