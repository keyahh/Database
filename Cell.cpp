#include "Cell.h"

Cell::Cell(const std::string& text)
	: _text(text)
{
}

const std::string& Cell::getText() const
{
	return _text;
}

void Cell::setText(const std::string& text)
{
	_text = text;
}
