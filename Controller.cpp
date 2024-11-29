#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(View& view, Model& model)
	: _view(&view), _model(&model)
{
	_sorter = WordSort("queries.txt");
}

void Controller::update(float dt)
{
}

void Controller::eventHandler(sf::RenderWindow& window, sf::Event event)
{
	if(event.type == sf::Event::TextEntered)
	{
		char c = static_cast<char>(event.text.unicode);
		if (std::isalpha(c))
		{
			_model->setText(_model->getText() + c);
			_view->_searchBox.setText(_model->getText());
			prioritize();
		}
		else if (c == '\b')
		{
			_model->backspace();
			_view->_searchBox.setText(_model->getText());
			prioritize();
		}
	}
}

void Controller::prioritize()
{
	_view->updateList(_sorter.prioritize(_model->getLastWord()));
}