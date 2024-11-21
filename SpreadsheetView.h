#ifndef SPREADSHEETVIEWH
#define SPREADSHEETVIEWH

#include "Spreadsheet.h"
#include "CellView.h"

class SpreadsheetView : public sf::Drawable
{
private:
	int _rows = 0, _cols = 0, _cellWidth = 0, _cellHeight = 0;
	std::vector<std::vector<CellView>> _cells;

	void arrange();
public:
	SpreadsheetView(int rows = 0, int cols = 0, int cellWidth = 0, int cellHeight = 0);
	SpreadsheetView(const Spreadsheet& spreadsheet);
	void init(int rows = 2, int cols = 2, int cellWidth = 200, int cellHeight = 100);

	virtual void setPosition(const sf::Vector2f& pos);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif