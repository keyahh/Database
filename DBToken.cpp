#include "DBToken.h"

DBToken::DBToken(Query query)
	: command(query)
{
}

DBToken::DBToken(const std::vector<std::string>& data)
	: data(data)
{
}
