#include "View.h"

View::View()
{
}

View::View(Model& model)
{
	init(model);
}

void View::init(Model& model)
{
	_modelPtr = &model;
	for (int i = 0; i < _modelPtr->getSpreadsheets().size(); ++i)
	{
		_spreadsheets.push_back(SpreadsheetView(_modelPtr->getSpreadsheets()[i]));
	}
}

void View::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (auto& s : _spreadsheets)
	{
		window.draw(s);
	}
}
