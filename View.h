#ifndef VIEWH
#define VIEWH

#include "Model.h"
#include "SpreadsheetView.h"

class View : public sf::Drawable
{
private:
	Model* _modelPtr = nullptr;
	std::vector<SpreadsheetView> _spreadsheets;

public:
	friend class Controller;

	View();
	View(Model& model);
	void init(Model& model);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif