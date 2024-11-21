#include "Row.h"

Row::Row(int cols)
{
	init(cols);
}

void Row::init(int cols)
{
	_cells = std::vector<Cell>(cols, Cell());
}

void Row::addCell(const Cell& cell)
{
	_cells.push_back(cell);
}

const std::vector<Cell>& Row::getCells() const
{
	return _cells;
}

const Cell& Row::getCell(int index) const
{
	return _cells[index];
}

void Row::setCellData(int index, const std::string& data)
{
	_cells[index].setText(data);
}
