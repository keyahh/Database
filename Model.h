#ifndef MODELH
#define MODELH

#include <string>

class Model
{
private:
	std::string _text, _label;

public:
	friend class Controller;
	Model(int rows = 0, int cols = 0, const std::string& text = "", const std::string& label = "");
};

#endif