#include "Controller.h"

Controller::Controller()
{
}

Controller::Controller(View& view, Model& model)
	: _view(&view), _model(&model)
{
}

void Controller::update(float dt)
{
}

void Controller::eventHandler(sf::RenderWindow& window, sf::Event event)
{
}
