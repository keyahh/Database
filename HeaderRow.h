#ifndef HEADERROWH
#define HEADERROWH

#include "Cell.h"
#include "CellView.h"
#include <vector>

class HeaderRow : public sf::Drawable
{
private:
	std::vector<CellView> _headerCells;

public:

};

#endif