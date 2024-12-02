#include "SearchBox.h"

SearchBox::SearchBox(float width, float height, int fontSize, const std::string& label)
{
	init(width, height, fontSize, label);
}

void SearchBox::init(float width, float height, int fontSize, const std::string& label)
{
	setSize({ width,height });
	setFillColor(sf::Color::Black);
	setOutlineColor(sf::Color::White);
	setOutlineThickness(2.f);

	_text.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	_text.setCharacterSize(fontSize);
	_text.setFillColor(sf::Color::White);
	_text.setString("");
	_text.setPosition({this->getPosition().x + 4.f, this->getPosition().y / 5.f});

	_label.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	_label.setString(label);
	_label.setCharacterSize(fontSize);
	_label.setFillColor(sf::Color::White);
	Position::center(*this, _label);
	_label.setPosition({ _label.getPosition().x, this->getGlobalBounds().top - _label.getGlobalBounds().height });

	_errorMessage.setFont(Fonts::getFont(Fonts::OPEN_SANS_REGULAR));
	_errorMessage.setCharacterSize(fontSize);
	_errorMessage.setFillColor(sf::Color::Red);
	_errorMessage.setString("");
	_errorMessage.setPosition({ this->getPosition().x + 4.f, this->getPosition().y + this->getSize().y + fontSize});

	_cursor.init(2, height - 2.f, sf::Color::White, 0.5f);
}

void SearchBox::enterInput(char c)
{
	std::string textString = _text.getString();
	_text.setString(textString + c);
	adjustCursor();
}

void SearchBox::backspace()
{
	std::string textString = _text.getString();
	if(textString.size() > 0)
	{
		textString.pop_back();
		_text.setString(textString);
		adjustCursor();
	}
}

void SearchBox::adjustCursor()
{
	float farRightTextPos = _text.getPosition().x + _text.getGlobalBounds().width + 4.f;
	_cursor.setPosition({ farRightTextPos, _cursor.getPosition().y });
	_cursor.enteredText();
}

void SearchBox::update(float dt)
{
	_cursor.update(dt);
}

void SearchBox::eventHandler(sf::RenderWindow& window, sf::Event& event)
{
	char c = static_cast<char>(event.text.unicode);
	if (std::isalpha(c))
	{
		enterInput(std::tolower(c));
	}
	else if (c == '\b')
	{
		backspace();
	}
}

void SearchBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	sf::RectangleShape parent = *this;
	window.draw(parent);
	window.draw(_cursor);
	window.draw(_text);
	window.draw(_label);
	window.draw(_errorMessage);
}

void SearchBox::setPosition(const sf::Vector2f& pos)
{
	sf::RectangleShape::setPosition(pos);
	_text.setPosition({ pos.x + 4.f, pos.y + (this->getGlobalBounds().height / 5)});
	Position::center(*this, _label);
	_label.setPosition({ _label.getPosition().x, this->getGlobalBounds().top - _label.getGlobalBounds().height * 2 });
	_cursor.setPosition({_cursor.getPosition().x + (pos.x - _cursor.getPosition().x), pos.y});
	_errorMessage.setPosition({ this->getPosition().x + 4.f, this->getPosition().y + this->getSize().y });
}

void SearchBox::setErrorMessage(const std::string& message)
{
	_errorMessage.setString(message);
}

void SearchBox::clearErrorMessage()
{
	_errorMessage.setString("");
}

void SearchBox::setText(const std::string& text)
{
	_text.setString(text);
	adjustCursor();
}

std::string SearchBox::getText()
{
	std::string s = _text.getString();
	return s;
}
