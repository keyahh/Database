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
	View(Model& model, int rows = 0, int cols = 0);
	void init(Model& model, int rows = 0, int cols = 0);

	virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif