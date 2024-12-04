#include "SpreadsheetView.h"

SpreadsheetView::SpreadsheetView(int rows, int cols, int cellWidth, int cellHeight)
{
	init(rows, cols, cellWidth, cellHeight);
}

SpreadsheetView::SpreadsheetView(const Spreadsheet& spreadsheet)
{
	init(spreadsheet.getRows(), spreadsheet.getCols(), 100, 50);

	//copy over data
	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			//_cells[i][j].setText(spreadsheet.getRow(i-1).getCell(j).getText());
			_cells[i][j].setText(spreadsheet.getCell(i, j));
		}
	}

	//copy headers
	//for (int i = 0; i < _cols; ++i)
	//{
	//	//std::cout << spreadsheet.getHeader(i).getText() << std::endl;
	//	_cells[0][i].setText(spreadsheet.getHeader(i).getText());
	//}
}

void SpreadsheetView::init(int rows, int cols, int cellWidth, int cellHeight)
{
	_rows = rows;
	_cols = cols;
	_cellWidth = cellWidth;
	_cellHeight = cellHeight;
	_cells = std::vector<std::vector<CellView>>(rows + 1, 
		std::vector<CellView>(cols, CellView(cellWidth, cellHeight)));

	arrange();
}

void SpreadsheetView::arrange()
{
	if(_cells[0].size() > 0)
	{
		sf::Vector2f pos = _cells[0][0].getPosition();

		//set cell positions
		pos = _cells[0][0].getPosition();
		float baseX = pos.x;

		for (int i = 0; i < _rows; ++i)
		{
			for (int j = 0; j < _cols; ++j)
			{
				_cells[i][j].setPosition(pos);
				pos.x += _cellWidth + 1.f;
			}
			pos.x = baseX;
			pos.y += _cellHeight + 1.f;
		}
	}
}

void SpreadsheetView::setPosition(const sf::Vector2f& pos)
{
	if(!_cells[0].empty())
	{
		_cells[0][0].setPosition(pos);
		arrange();
	}
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