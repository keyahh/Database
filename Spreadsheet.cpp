#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int rows, int cols, const std::string& label)
{
	init(rows, cols, label);
}

Spreadsheet::Spreadsheet(int rows, int cols, const std::map<std::string, std::vector<std::string>>& data)
	: _rows(rows), _cols(cols)
{
	_cells = std::vector<std::vector<std::string>>(rows + 1, std::vector<std::string>(cols));
	
	int index = 0;
	for (auto& pair : data)
	{
		_cells[0][index] = pair.first; // set header

		for (int r = 1; r <= pair.second.size(); ++r)
		{
			_cells[r][index] = pair.second[r - 1];
		}
		++index;
	}
}

void Spreadsheet::init(int rows, int cols, const std::string& label)
{
	_rows = rows;
	_cols = cols;
	_label = label;

	_cells = std::vector<std::vector<std::string>>(rows, std::vector<std::string>(cols));

	//_cellRows = std::vector<Row>(rows, Row(cols));
	//_header = Row(_cols);
	for (int i = 1; i < cols; ++i)
	{
		std::cout << "inserted str " << i << ": " << std::string(1, (char)(i + 64)) << std::endl;
		//_header.setCellData(i, std::string(1, (char)(i + 64)));
	}
}

void Spreadsheet::setCell(int row, int col, const std::string& data)
{
	if (row < _rows && 0 <= row && col < _cols && 0 <= col)
		_cells[row][col] = data;
		//_cellRows[row].setCellData(col, data);
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

const std::string& Spreadsheet::getCell(int row, int col) const
{
	if (row >= 0 && row < _rows && col >= 0 && col < _cols)
		return _cells[row][col];
}

//const std::vector<Row>& Spreadsheet::getCells() const
//{
//	return _cellRows;
//}
//
//const Row& Spreadsheet::getRow(int index) const
//{
//	return _cellRows[index];
//}
//
//const Cell& Spreadsheet::getHeader(int index) const
//{
//	return _header.getCell(index);
//}
//
//const std::string& Spreadsheet::getLabel() const
//{
//	return _label;
//}

const int Spreadsheet::getRows() const
{
	return _rows;
}

const int Spreadsheet::getCols() const
{
	return _cols;
}