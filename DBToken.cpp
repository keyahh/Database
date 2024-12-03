#include "DBToken.h"

DBToken::DBToken(Query query)
	: command(query)
{
}

DBToken::DBToken(const std::vector<std::string>& data)
	: data(data)
{
}

std::ostream& operator<<(std::ostream& cout, const DBToken& dbtoken)
{
	if (dbtoken.data.empty())
		return cout << dbtoken.command;

	for (auto& s : dbtoken.data)
	{
		cout << s << " ";
	}

	return cout;
}
