#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int rows, int cols, const std::string& label)
{
	init(rows, cols, label);
}

void Spreadsheet::init(int rows, int cols, const std::string& label)
{
	_rows = rows;
	_cols = cols;
	_label = label;
	_cells = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, Cell()));
}

void Spreadsheet::setCell(int row, int col, const std::string& data)
{
	if (row < _rows && 0 <= row && col < _cols && 0 <= col)
		_cells[row][col].setText(data);
}

void Spreadsheet::setLabel(const std::string& label)
{
	_label = label;
}

void Spreadsheet::setRows(int rows)
{
	_rows = rows;
}

void Spreadsheet::setCols(int cols)
{
	_cols = cols;
}

const std::vector<std::vector<Cell>>& Spreadsheet::getCells() const
{
	return _cells;
}

const std::string& Spreadsheet::getLabel() const
{
	return _label;
}

const int Spreadsheet::getRows() const
{
	return _rows;
}

const int Spreadsheet::getCols() const
{
	return _cols;
}