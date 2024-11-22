#include "CellView.h"

CellView::CellView(int width, int height, const std::string& text, bool canEdit)
{
	init(width, height, text, sf::Color::White, ColorPalette::defaultGray, canEdit);
}

CellView::CellView(int width, int height, const std::string& text, const sf::Color& boxColor, const sf::Color& borderColor, bool canEdit)
{
	init(width, height, text, boxColor, borderColor, canEdit);
}

void CellView::init(int width, int height, const std::string& text, const sf::Color& boxColor, const sf::Color& borderColor, bool canEdit)
{
	this->setSize(sf::Vector2f( width, height ));
	this->setFillColor(boxColor);
	this->setOutlineColor(borderColor);
	this->setOutlineThickness(2.f);
	_text.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);
}

void CellView::updateBorderColor(const sf::Color& newColor)
{
	this->setOutlineColor(newColor);
}

void CellView::updateBoxColor(const sf::Color& newColor)
{
	this->setFillColor(newColor);
}

void CellView::setText(const std::string& text)
{
	_text.setString(text);
}

void CellView::update(float dt)
{
	
}

void CellView::eventHandler(sf::RenderWindow& window, sf::Event event)
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

void CellView::setCanEdit(bool edit)
{
	_canEdit = edit;
}

const bool CellView::getCanEdit() const
{
	return _canEdit;
}

void CellView::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(_text);
}

void CellView::setPosition(const sf::Vector2f& pos)
{
	sf::RectangleShape::setPosition(pos);
	_text.setPosition({ pos.x + 4.f, pos.y + (this->getGlobalBounds().height / 5) });
}

void CellView::setSize(const sf::Vector2f& size)
{
	sf::RectangleShape::setSize(size);
	sf::Vector2f pos = getPosition();
	_text.setPosition({ pos.x + 4.f, pos.y + (this->getGlobalBounds().height / 5) });
}
