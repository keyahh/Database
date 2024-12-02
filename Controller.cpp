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
			{"TABLE", {"*CREATE_TABLE"}},
			{"*CREATE_TABLE", {"*CREATE_COLUMNS"}},
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

		if (event.text.unicode == 13) //unicode for enter key is 13
		{
			std::vector<std::string> tokens = Tokenizer::tokenize(_model->getText());
			/*for (auto& x : tokens)
				std::cout << x << std::endl;*/
			std::vector<Query> convertedTokens = _parser.convertTokens(tokens);
			if (_parser.checkPath(convertedTokens))
			{
				std::cout << "valid path\n";
			}
			else
			{
				std::cout << "invalid path\n";

			}


			_model->setText("");
		}
		else if (c == '\b')
		{
			_model->backspace();
			prioritize();
		}

		else if (c == '\t')
		{
			_model->setLastWord(_sorter.prioritize(_model->getLastWord())[0].getString());
		}
		else
		{
			_model->setText(_model->getText() + c);
			prioritize();
		}

		_view->_searchBox.setText(_model->getText());

	}
}

void Controller::prioritize()
{
	_view->updateList(_sorter.prioritize(_model->getLastWord()));
}