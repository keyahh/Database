#include "Cursor.h"

Cursor::Cursor()
{
}

Cursor::Cursor(float width, float height, sf::Color color, float blinkTime)
{
	init(width, height, color, blinkTime);
}

void Cursor::init(float width, float height, sf::Color color, float blinkTime)
{
	maxBlinkDelay = blinkTime;
	_color = color;
	setSize({ width, height });
	setFillColor(color);

}

void Cursor::toggleVisible()
{
	blinkTime = 0.f;
	_visible = !_visible;
	if (_visible)
	{
		setFillColor(_color);
	}
	else
	{
		setFillColor(sf::Color::Transparent);
	}
}

void Cursor::update(float dt)
{
	blinkTime += dt;
	if (blinkTime >= maxBlinkDelay)
	{
		toggleVisible();
	}
}

void Cursor::enteredText()
{
	_visible = true;
	blinkTime = 0.f;
	setFillColor(_color);
}