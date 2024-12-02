#include "Database.h"

Database::Database()
{
}

void Database::run(const std::vector<Query>& queries, const std::vector<std::string>& tokens)
{
	std::vector<DBToken> dbtokens = parse(queries, tokens);
	if (dbtokens[0].command == Query::CREATE)
	{
		createTable(dbtokens);
	}
}

std::vector<DBToken> Database::parse(const std::vector<Query>& queries, const std::vector<std::string>& tokens)
{
	std::vector<DBToken> dbtokens;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (isCommand(queries[i]))
		{
			dbtokens.emplace_back(DBToken(queries[i]));
		}
		else
		{
			dbtokens.push_back(getVariables(tokens[i]));
		}
	}

	return dbtokens;
}

DBToken Database::getVariables(const std::string& str)
{
	if (str[0] == '(')
	{

	}
	else
	{

	}
	return DBToken();
}

bool Database::isCommand(Query q)
{
	return (q != Query::TABLE_VAR && q != Query::COLUMN_VAR
		&& q != Query::CREATE_TABLE && q != Query::CREATE_COLUMNS
		&& q != Query::INSERT_TABLE && q != Query::INSERT_COLUMNS
		&& q != Query::VALUES_VAR);
}

void Database::createTable(const std::vector<DBToken>& dbtokens)
{
}