#ifndef VIEWH
#define VIEWH

#include "Model.h"
#include "SpreadsheetView.h"
#include "SearchBox.h"
#include "Word.h"

class View : public sf::Drawable
{
private:
	Model* _modelPtr = nullptr;
	std::vector<SpreadsheetView> _spreadsheets;
	SearchBox _searchBox;
	std::vector<sf::Text> _suggestions;
	bool _showSuggestions = true;

public:
	friend class Controller;

	View();
	View(Model& model);
	void init(Model& model);
	void setSearchBoxPos(const sf::Vector2f& position);
	void updateList(const std::vector<Word>& words);
	void clearSuggestionsList();
	std::string getTopSuggestion() const;
	void showSuggestions(bool toggle);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif