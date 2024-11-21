#ifndef DATABASEH
#define DATABASEH

#include "Controller.h"
#include "View.h"
#include "Model.h"

class Database
{
private:
	sf::RenderWindow _window;
	Model _model;
	View _view;
	Controller _controller;
	sf::Clock _clock;
	float dt = 0.f;

public:
	Database();

	void run();
};

#endif