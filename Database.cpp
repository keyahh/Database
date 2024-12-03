#include "Database.h"

Database::Database()
{
}

void Database::run(const std::vector<Query>& queries, const std::vector<std::string>& tokens)
{
	std::vector<DBToken> dbtokens = parse(queries, tokens);

	for (auto& db : dbtokens)
	{
		std::cout << db << "\n";
	}

	switch (dbtokens[0].command)
	{
	case(Query::CREATE):
		createTable(dbtokens);
		break;
	case(Query::SELECT):
		select(dbtokens);
		break;
	case(Query::INSERT):
		insert(dbtokens);
		break;
	case(Query::DELETE):
		deleteData(dbtokens);
		break;
	}
}

const Table& Database::getTable(const std::string& tableName) const
{
	return _tbleMgr.getTable(tableName);
}

std::vector<DBToken> Database::parse(const std::vector<Query>& queries, const std::vector<std::string>& tokens)
{
	std::vector<DBToken> dbtokens;
	for (int i = 0; i < tokens.size(); ++i)
	{
		if (isCommand(queries[i]))
		{
			dbtokens.push_back(DBToken(queries[i]));
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
	//get list of variables
	if (str[0] == '(')
	{
		return DBToken(cutStr(str, ','));
	}

	//single variable
	return DBToken({ str });
}

std::vector<std::string> Database::cutStr(const std::string& str, char delimiter)
{
	std::string phrase = str;
	phrase.erase(phrase.begin());
	phrase.erase(phrase.begin() + (phrase.size() - 1));

	if (phrase.find(delimiter) == std::string::npos)
		return { phrase };

	std::vector<std::string> temp;
	int previous = 0, dlIndex = 0;

	while (phrase.find(delimiter, previous + 1) != std::string::npos) {
		dlIndex = phrase.find(delimiter, previous);
		temp.push_back(phrase.substr(previous, dlIndex - previous));
		previous += (dlIndex - previous) + 1;
	}

	temp.push_back(phrase.substr(previous));

	return temp;
}

std::pair<std::string, std::string> Database::findPair(const std::string& str, char delimiter)
{
	if (str.find(delimiter) == std::string::npos)
		return {};
	
	int index = str.find(delimiter);
	return std::pair<std::string, std::string>(str.substr(0, index), str.substr(index + 1));
}

bool Database::isCommand(Query q)
{
	return (q != Query::TABLE_VAR && q != Query::COLUMN_VAR
		&& q != Query::CREATE_TABLE && q != Query::CREATE_COLUMNS
		&& q != Query::INSERT_TABLE && q != Query::INSERT_COLUMNS
		&& q != Query::VALUES_VAR && q != Query::CONDITION_VAR);
}

void Database::createTable(const std::vector<DBToken>& dbtokens)
{
	if(dbtokens.size() == 3)
		_tbleMgr.addTable(Table(dbtokens[2].data[0], {}));

	_tbleMgr.addTable(Table(dbtokens[2].data[0], dbtokens[3].data));
}

void Database::select(const std::vector<DBToken>& dbtokens)
{
}

void Database::insert(const std::vector<DBToken>& dbtokens)
{
	//insertRow(name, columns list, values list)
	_tbleMgr.insertRow(dbtokens[2].data[0], dbtokens[3].data, dbtokens[5].data);
}

void Database::deleteData(const std::vector<DBToken>& dbtokens)
{
	std::pair<std::string, std::string> condition = findPair(dbtokens[4].data[0], '=');
	_tbleMgr.deleteData(dbtokens[2].data[0], condition);
}
