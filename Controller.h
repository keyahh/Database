#ifndef CONTROLLERH
#define CONTROLLERH

#include "View.h"
#include "WordSort.h"
#include "Graph.h"
#include "Tokenizer.h"
#include "Database.h"

class Controller
{
private:
	View* _view = nullptr;
	Model* _model = nullptr;

	WordSort _sorter;
	Graph _parser;
	Database _db;

	void prioritize();
public:
	Controller();
	Controller(View& viewPtr, Model& modelPtr);
	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif