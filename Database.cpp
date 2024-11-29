#include "Database.h"

Database::Database()
{
	_window.create(sf::VideoMode(1920, 1080), "Database");
    //_model.addNewSpreadsheet(10, 10, "test");
    _view.init(_model);
    _controller = Controller(_view, _model);
}

void Database::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();

            _controller.eventHandler(_window, event);
        }

        dt = _clock.restart().asSeconds();

        _window.clear();
        _window.draw(_view);
        _controller.update(dt);
        _window.display();
    }
}
