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
	_searchBox.init(1480.f, 100.f, 40, "");
	_searchBox.setPosition({ 200.f, 100.f });

	/*for (int i = 0; i < _modelPtr->getSpreadsheets().size(); ++i)
	{
		_spreadsheets.push_back(SpreadsheetView(_modelPtr->getSpreadsheets()[i]));
	}*/
}

void View::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

	window.draw(_searchBox);

	/*for (auto& s : _spreadsheets)
	{
		window.draw(s);
	}*/

	window.draw(_displaySheet);

	if(_showSuggestions)
	{
		for (auto& s : _suggestions)
		{
			window.draw(s);
		}
	}
}

void View::setSearchBoxPos(const sf::Vector2f& position)
{
	_searchBox.setPosition(position);
}

void View::updateList(const std::vector<Word>& words)
{
	_suggestions.clear();
	sf::Vector2f pos = { _searchBox.getPosition().x, _searchBox.getPosition().y + _searchBox.getSize().y + 5.f };
	for (int i = 0; i < words.size(); ++i)
	{
		_suggestions.push_back(words[i]);
		_suggestions[i].setPosition(pos);
		pos.y += 25.f;
	}
}

void View::clearSuggestionsList()
{
	_suggestions.clear();
}

std::string View::getTopSuggestion() const
{
	std::string res = std::string(_suggestions.front().getString());
	//std::cout << res << std::endl;
	return res;
}

void View::showSuggestions(bool toggle)
{
	_showSuggestions = toggle;
}

void View::updateDisplaySheet(const Spreadsheet& sheet)
{
	_displaySheet = SpreadsheetView(sheet);
}
