#ifndef CELLVIEWH
#define CELLVIEWH

#include <string>
#include "SFML/Graphics.hpp"
#include "Helper/Fonts.h"
#include "Helper/MouseEvents.h"
#include "Helper/Position.h"
#include "Helper/ColorPalette.h"

class CellView : public sf::RectangleShape
{
private:
	sf::Text _text;
	sf::Color _borderColor = ColorPalette::defaultGray;
	sf::Color _boxColor = sf::Color::White;
	bool _isSelected = false, _canEdit = true;

public:
	CellView(int width = 0, int height = 0, const std::string& text = "", bool canEdit = true);
	CellView(int width, int height, const std::string& text, 
		const sf::Color& boxColor, const sf::Color& borderColor, bool canEdit);

	void init(int width, int height, const std::string& text = "", 
		const sf::Color& boxColor = sf::Color::White, 
		const sf::Color& borderColor = ColorPalette::defaultGray, 
		bool canEdit = true);
	void updateBorderColor(const sf::Color& newColor);
	void updateBoxColor(const sf::Color& newColor);
	void setText(const std::string& text);
	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event event);

	void setCanEdit(bool edit);
	const bool getCanEdit() const;

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
	virtual void setPosition(const sf::Vector2f& pos);
	virtual void setSize(const sf::Vector2f& size);
};

#endif