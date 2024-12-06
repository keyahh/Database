#ifndef SPREADSHEETH
#define SPREADSHEETH

#include "Cell.h"
#include "Row.h"
#include "DBToken.h"
#include "Table.h"
#include <vector>
#include <iostream>
#include <map>

class Spreadsheet
{
private:
	std::string _label;
	//Row _header;
	//std::vector<Row> _cellRows;
	std::vector<std::vector<std::string>> _cells;
	int _rows = 0, _cols = 0;

public:
	Spreadsheet(int rows = 0, int cols = 0, const std::string& label = "");
	Spreadsheet(int rows, int cols, const std::map<std::string, std::vector<std::string>>& data);
	Spreadsheet(const Table& table);
	void init(int rows = 0, int cols = 0, const std::string& label = "");

	void setCell(int row, int col, const std::string& data);
	void setLabel(const std::string& label);
	void setRows(int rows);
	void setCols(int cols);
	const std::string& getCell(int row, int col) const;
	/*const std::vector<Row>& getCells() const;
	const Row& getRow(int index) const;
	const Cell& getHeader(int index) const;
	const std::string& getLabel() const;*/
	const int getRows() const;
	const int getCols() const;
};

#endif