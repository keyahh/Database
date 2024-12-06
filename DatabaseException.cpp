#include "DatabaseException.h"

DatabaseException::DatabaseException(const char* msg)
	: _msg(msg)
{
}

const char* DatabaseException::what() const
{
	return _msg;
}
