#ifndef MODELH
#define MODELH

#include "Spreadsheet.h"
#include "TableManager.h"
#include <sstream>

class Model
{
private:
	//std::vector<Spreadsheet> _spreadsheets;
	TableManager _tableManager;
	std::string _text, _label;

public:
	friend class Controller;
	Model();
	void init();
	//void addNewSpreadsheet(int rows, int cols, const std::string& label);
	//void addSpreadsheet(Spreadsheet& spreadsheet);

	const std::string& getText() const;
	const std::string& getLabel() const;
	std::string getLastWord() const;
	void setLastWord(const std::string& word);
	void setText(const std::string& text);
	void setLabel(const std::string& label);
	void addTable(const Table& table);
	void backspace();
	//const std::vector<Spreadsheet>& getSpreadsheets() const;

};

#endif