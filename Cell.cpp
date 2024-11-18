#include "Cell.h"

Cell::Cell(int width, int height, const std::string& text)
{
	init(width, height, text);
}

void Cell::init(int width, int height, const std::string& text, const sf::Color& boxColor, const sf::Color& borderColor)
{
	this->setSize({ width, height });
	this->setFillColor(boxColor);
	this->setOutlineColor(borderColor);
	this->setOutlineThickness(2.f);
	_text.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	_text.setString(text);
}

void Cell::updateBorderColor(const sf::Color& newColor)
{
	this->setOutlineColor(newColor);
}

void Cell::updateBoxColor(const sf::Color& newColor)
{
	this->setFillColor(newColor);
}

void Cell::update(float dt)
{
	
}

void Cell::eventHandler(sf::RenderWindow& window, sf::Event event)
{
	if(event.type == sf::Event::MouseButtonPressed)
	{
		if (MouseEvents::isHovered(*this, window))
		{
			_isSelected = true;
			sf::RectangleShape::setOutlineColor(ColorPalette::highlightBlue);
		}
		else
		{
			_isSelected = false;
			sf::RectangleShape::setOutlineColor(ColorPalette::defaultGray);
		}
	}
}

void Cell::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(_text);
}

void Cell::setPosition(const sf::Vector2f& pos)
{
	sf::RectangleShape::setPosition(pos);
	_text.setPosition({ pos.x + 4.f, pos.y + (this->getGlobalBounds().height / 5) });
}