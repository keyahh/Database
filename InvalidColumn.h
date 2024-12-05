#ifndef INVALIDCOLUMNH
#define INVALIDCOLUMNH

#include <exception>

class InvalidColumn : public std::exception
{
private:
	const char* _msg;
public:
	InvalidColumn(const char* msg = "");
	const char* what() const;
};

#endif