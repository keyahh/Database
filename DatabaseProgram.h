#ifndef DATABASEPROGRAMH
#define DATABASEPROGRAMH

#include "Controller.h"
#include "View.h"
#include "Model.h"

class DatabaseProgram
{
private:
	sf::RenderWindow _window;
	Model _model;
	View _view;
	Controller _controller;
	sf::Clock _clock;
	float dt = 0.f;

public:
	DatabaseProgram();

	void run();
};

#endif