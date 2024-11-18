#ifndef CELLH
#define CELLH

#include <string>
#include "SFML/Graphics.hpp"
#include "Helper/Fonts.h"
#include "Helper/MouseEvents.h"
#include "Helper/Position.h"
#include "Helper/ColorPalette.h"

class Cell : public sf::RectangleShape
{
private:
	sf::Text _text;
	sf::Color _borderColor = ColorPalette::defaultGray;
	sf::Color _boxColor = sf::Color::White;
	bool _isSelected = false;

public:
	Cell(int width = 0, int height = 0, const std::string& text = "");

	void init(int width, int height, const std::string& text = "", const sf::Color& boxColor = sf::Color::White, const sf::Color& borderColor = ColorPalette::defaultGray);
	void updateBorderColor(const sf::Color& newColor);
	void updateBoxColor(const sf::Color& newColor);

	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event event);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& pos);
};

#endif