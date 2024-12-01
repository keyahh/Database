#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(View& view, Model& model)
	: _view(&view), _model(&model)
{
	_sorter = WordSort("queries.txt");
	_parser = Graph(
		{
			{"START", {"SELECT", "INSERT", "CREATE"}},
			{"SELECT", {"*COLUMNS"}},
			{"*COLUMNS", {"*COLUMNS", "FROM"}},
			{"FROM", {"*TABLE"}},
			{"*TABLE", {"END"}},
			{"INSERT", {"INTO"}},
			{"INTO", {"*INSERT_TABLE"}},
			{"*INSERT_TABLE", {"*INSERT_COLUMNS"}},
			{"*INSERT_COLUMNS", {"*INSERT_COLUMNS", "VALUES"}},
			{"VALUES", {"*VALUES"}},
			{"*VALUES", {"*VALUES", "END"}},
			{"CREATE", {"TABLE"}},
			{"TABLE", {"*CREATE_COLUMNS"}},
			{"*CREATE_COLUMNS", {"*CREATE_COLUMNS", "END"}}
		}
	);

	//std::cout << _parser.checkPath({ "START", "INSERT", "INTO", "*INSERT_TABLE", "*INSERT_COLUMNS", "VALUES", "*VALUES", "END" });

}

void Controller::update(float dt)
{
	if (!_model->getText().empty())
	{
		if (_model->getLastWord() == _view->getTopSuggestion())
			_view->showSuggestions(false);
		else
			_view->showSuggestions(true);
	}
	else
	{
		_view->showSuggestions(false);
	}
}

void Controller::eventHandler(sf::RenderWindow& window, sf::Event event)
{
	if(event.type == sf::Event::TextEntered)
	{
		char c = static_cast<char>(event.text.unicode);

		if (std::isalpha(c) || c == ' ')
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

		else if (c == '\t')
		{
			_model->setLastWord(_sorter.prioritize(_model->getLastWord())[0].getString());
			_view->_searchBox.setText(_model->getText());
		}
	}
}

void Controller::prioritize()
{
	_view->updateList(_sorter.prioritize(_model->getLastWord()));
}