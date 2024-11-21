#include "Model.h"

Model::Model()
{

}

void Model::addNewSpreadsheet(int rows, int cols, const std::string& label)
{
	_spreadsheets.push_back(Spreadsheet(rows, cols, label));
}

void Model::addSpreadsheet(Spreadsheet& spreadsheet)
{
	_spreadsheets.push_back(spreadsheet);
}

const std::vector<Spreadsheet>& Model::getSpreadsheets() const
{
	return _spreadsheets;
}
