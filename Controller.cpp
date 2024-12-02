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
			{"START", {"SELECT", "INSERT", "CREATE", "DELETE"}},
			{"SELECT", {"*COLUMNS"}},
			{"*COLUMNS", {"*COLUMNS", "FROM"}},
			{"FROM", {"*TABLE"}},
			{"*TABLE", {"END", "WHERE"}},
			{"INSERT", {"INTO"}},
			{"INTO", {"*INSERT_TABLE"}},
			{"*INSERT_TABLE", {"*INSERT_COLUMNS"}},
			{"*INSERT_COLUMNS", {"*INSERT_COLUMNS", "VALUES"}},
			{"VALUES", {"*VALUES"}},
			{"*VALUES", {"*VALUES", "END"}},
			{"CREATE", {"TABLE"}},
			{"TABLE", {"*CREATE_TABLE"}},
			{"*CREATE_TABLE", {"*CREATE_COLUMNS"}},
			{"*CREATE_COLUMNS", {"*CREATE_COLUMNS", "END"}},
			{"DELETE", {"FROM"}},
			{"WHERE", {"*CONDITION"}},
			{"*CONDITION", {"*CONDITION", "END"}},
			{"LAUNCH", {"*LAUNCH"}}
		}
	);
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

		if (event.text.unicode == 13) //unicode for enter key is 13
		{
			std::vector<std::string> tokens = Tokenizer::tokenize(_model->getText());

			std::vector<Query> convertedTokens = _parser.convertTokens(tokens);
			if (_parser.checkPath(convertedTokens))
			{
				std::cout << "valid path\n";
				_db.run(convertedTokens, tokens);
			}
			else
			{
				std::cout << "invalid path\n";
				_view->_searchBox.setErrorMessage("Invalid syntax");
			}

			_model->setText("");
		}
		else if (c == '\b')
		{
			_model->backspace();
			prioritize();
			_view->_searchBox.clearErrorMessage();
		}

		else if (c == '\t')
		{
			if(_model->getText().size() > 0)
			{
				_model->setLastWord(_sorter.prioritize(_model->getLastWord())[0].getString());
				_view->_searchBox.clearErrorMessage();
			}
		}
		else
		{
			_model->setText(_model->getText() + c);
			prioritize();
			_view->_searchBox.clearErrorMessage();
		}

		_view->_searchBox.setText(_model->getText());

	}
}

void Controller::prioritize()
{
	_view->updateList(_sorter.prioritize(_model->getLastWord()));
}