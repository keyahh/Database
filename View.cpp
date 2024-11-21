#include "View.h"

View::View()
{
}

View::View(Model& model, int rows, int cols)
{
	init(model, rows, cols);
}

void View::init(Model& model, int rows, int cols)
{

}

void View::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (auto& s : _spreadsheets)
	{
		window.draw(s);
	}
}
