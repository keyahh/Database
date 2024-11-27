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
	_cellRows = std::vector<Row>(rows, Row(cols));
	_header = Row(_cols);
	for (int i = 1; i < cols; ++i)
	{
		std::cout << "inserted str " << i << ": " << std::string(1, (char)(i + 64)) << std::endl;
		_header.setCellData(i, std::string(1, (char)(i + 64)));
	}
	//_cells = std::vector<std::vector<Cell>>(rows, std::vector<Cell>(cols, Cell()));
}

void Spreadsheet::setCell(int row, int col, const std::string& data)
{
	if (row < _rows && 0 <= row && col < _cols && 0 <= col)
		_cellRows[row].setCellData(col, data);
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

const std::vector<Row>& Spreadsheet::getCells() const
{
	return _cellRows;
}

const Row& Spreadsheet::getRow(int index) const
{
	return _cellRows[index];
}

const Cell& Spreadsheet::getHeader(int index) const
{
	return _header.getCell(index);
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