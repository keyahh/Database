#include "InvalidColumn.h"

InvalidColumn::InvalidColumn(const char* msg)
	:_msg(msg)
{
}

const char* InvalidColumn::what() const
{
	return _msg;
}
