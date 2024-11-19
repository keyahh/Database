#ifndef SPREADSHEETH
#define SPREADSHEETH

#include "Cell.h"

class Spreadsheet : public sf::Drawable
{
private:
	int _rows = 0, _cols = 0, _cellWidth = 0, _cellHeight = 0;
	std::vector<std::vector<Cell>> _cells;

	void arrange();
public:
	Spreadsheet(int rows = 0, int cols = 0, int cellWidth = 0, int cellHeight = 0);
	void init(int rows = 2, int cols = 2, int cellWidth = 40, int cellHeight = 20);

	virtual void setPosition(const sf::Vector2f& pos);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif