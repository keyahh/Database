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

public:
	friend class Controller;

	View();
	View(Model& model);
	void init(Model& model);
	void setSearchBoxPos(const sf::Vector2f& position);
	void updateList(const std::vector<Word>& words);
	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif