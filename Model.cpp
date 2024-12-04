#include "Model.h"

Model::Model()
{

}

void Model::init()
{

}

//void Model::addNewSpreadsheet(int rows, int cols, const std::string& label)
//{
//	_spreadsheets.push_back(Spreadsheet(rows, cols, label));
//}
//
//void Model::addSpreadsheet(Spreadsheet& spreadsheet)
//{
//	_spreadsheets.push_back(spreadsheet);
//}

const std::string& Model::getText() const
{
	return _text;
}

const std::string& Model::getLabel() const
{
	return _label;
}

std::string Model::getLastWord() const
{
	std::string temp;

	std::stringstream ss(_text);

	while (ss >> temp)
	{
	}

	return temp;
}

void Model::setLastWord(const std::string& word)
{
	std::string temp;
	std::stringstream ss(_text);
	std::vector<std::string> words;

	while (ss >> temp)
	{
		words.push_back(temp);
	}
	words[words.size() - 1] = word;
	_text.clear();

	for (auto& w : words)
	{
		_text.append(w + " ");
	}
	_text.pop_back();
}

void Model::setText(const std::string& text)
{
	_text = text;
}

void Model::setLabel(const std::string& label)
{
	_label = label;
}

void Model::addTable(const Table& table)
{
	_tableManager.addTable(table);
}

void Model::backspace()
{
	if (_text.size() > 0)
	{
		_text.pop_back();
	}
}

void Model::updateHistory()
{
	_history.push_back(_text);
	_histIndex = _history.size() - 1;
}

void Model::upArr()
{
	if (_histIndex >= 0 && !_history.empty())
	{
		_text = _history[_histIndex];
		if(_histIndex > 0)
			--_histIndex;
	}
}

void Model::downArr()
{
	if (_histIndex < _history.size() && !_history.empty())
	{
		_text = _history[_histIndex];
		if (_histIndex < _history.size() - 1)
			++_histIndex;
	}
}

//const std::vector<Spreadsheet>& Model::getSpreadsheets() const
//{
//	return _spreadsheets;
//}
