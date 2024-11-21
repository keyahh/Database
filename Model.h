#ifndef MODELH
#define MODELH

#include "Spreadsheet.h"

class Model
{
private:
	std::vector<Spreadsheet> _spreadsheets;

public:
	friend class Controller;
	Model();
	void init();
	void addNewSpreadsheet(int rows, int cols, const std::string& label);
	void addSpreadsheet(Spreadsheet& spreadsheet);

	const std::vector<Spreadsheet>& getSpreadsheets() const;

};

#endif