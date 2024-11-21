#ifndef CONTROLLERH
#define CONTROLLERH

#include "View.h"

class Controller
{
private:
	View* _view = nullptr;
	Model* _model = nullptr;

public:
	Controller();
	Controller(View& viewPtr, Model& modelPtr);
	void update(float dt);
	void eventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif