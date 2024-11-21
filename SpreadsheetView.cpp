#include "SpreadsheetView.h"

SpreadsheetView::SpreadsheetView(int rows, int cols, int cellWidth, int cellHeight)
{
	init(rows, cols, cellWidth, cellHeight);
}

SpreadsheetView::SpreadsheetView(const Spreadsheet& spreadsheet)
{
	init(spreadsheet.getRows(), spreadsheet.getCols(), 40, 20);

	//copy over data
	for (int i = 1; i <= _rows; ++i)
	{
		for (int j = 1; j <= _cols; ++j)
		{
			_cells[i][j].setText(spreadsheet.getRow(i-1).getCell(j-1).getText());
		}
	}

	//copy headers
	for (int i = 1; i < +_rows; ++i)
	{
		_cells[0][i].setText(spreadsheet.getHeader(i - 1).getText());
	}
}

void SpreadsheetView::init(int rows, int cols, int cellWidth, int cellHeight)
{
	_rows = rows;
	_cols = cols;
	_cellWidth = cellWidth;
	_cellHeight = cellHeight;
	_cells = std::vector<std::vector<CellView>>(rows + 1, 
		std::vector<CellView>(cols + 1, CellView(cellWidth, cellHeight)));

	arrange();
}

void SpreadsheetView::arrange()
{
	_cells[0][0].setSize(sf::Vector2f(10.f, _cellHeight));
	sf::Vector2f pos = _cells[0][0].getPosition();

	//format row indicators
	for (int i = 1; i < _rows + 1; ++i)
	{
		_cells[i][0].setSize(sf::Vector2f(10.f, _cellHeight));

		pos.y += _cellHeight + 1.f;
		_cells[i][0].setPosition(pos);
		_cells[i][0].setText(std::to_string(i));
	}

	//write header
	for (int i = 1; i < _rows + 1; ++i)
	{
		_cells[0][i].setText(std::to_string((char)i + 64));
	}

	//set cell positions
	pos = _cells[0][0].getPosition();
	pos.x += 11.f;
	float baseX = pos.x;

	for (int i = 1; i < _rows + 1; ++i)
	{
		for (int j = 1; j < _cols + 1; ++j)
		{
			_cells[i][j].setPosition(pos);
			pos.x += _cellWidth + 1.f;
		}
		pos.x = baseX;
		pos.y += _cellHeight + 1.f;
	}
}

void SpreadsheetView::setPosition(const sf::Vector2f& pos)
{
}

void SpreadsheetView::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (int i = 0; i < _cells.size(); ++i)
	{
		for (int j = 0; j < _cells[i].size(); ++j)
		{
			window.draw(_cells[i][j]);
		}
	}
}