#ifndef ROWH
#define ROWH

#include "Cell.h"
#include <vector>

class Row
{
private:
	std::vector<Cell> _cells;

public:
	Row(int cols = 0);
	void init(int cols);
	void addCell(const Cell& cell);
	const std::vector<Cell>& getCells() const;

	const Cell& getCell(int index) const;
	void setCellData(int index, const std::string& data);
};

#endif