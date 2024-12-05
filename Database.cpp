#include "Database.h"

Database::Database()
{
}

void Database::run(const std::vector<Query>& queries, const std::vector<std::string>& tokens)
{
	std::vector<DBToken> dbtokens = parse(queries, tokens);

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

const bool& Database::hasSelected() const
{
	return _hasSelected;
}

const Spreadsheet& Database::getSelectedSpreadsheet() const
{
	return _selectedSheet;
}

const std::string& Database::getErrorMsg() const
{
	return _errorMsg;
}

void Database::clearErrorMsg()
{
	_errorMsg = "";
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
	int index = str.find(delimiter);
	if (str.find(delimiter) == std::string::npos)
		return {};
	
	return std::pair<std::string, std::string>(str.substr(0, index), str.substr(index + 1));
}

std::pair<std::string, std::string> Database::findPair(const std::string& str, const std::string& delimiter)
{
	int index = str.find(delimiter);
	if (index == std::string::npos)
		return {};
	
	return std::pair<std::string, std::string>(str.substr(0, index), str.substr(index + delimiter.size()));
}

bool Database::isCommand(Query q)
{
	return (q != Query::TABLE_VAR && q != Query::COLUMN_VAR
		&& q != Query::CREATE_TABLE && q != Query::CREATE_COLUMNS
		&& q != Query::INSERT_TABLE && q != Query::INSERT_COLUMNS
		&& q != Query::VALUES_VAR && q != Query::CONDITION_VAR);
}

std::string Database::findOperation(const std::string& str)
{
	if (str.find(">=") != std::string::npos)
		return ">=";
	else if (str.find("<=") != std::string::npos)
		return "<=";
	else if (str.find("=") != std::string::npos)
		return "=";
	else if (str.find(">") != std::string::npos)
		return ">";
	else if (str.find("<") != std::string::npos)
		return "<";
}

void Database::createTable(const std::vector<DBToken>& dbtokens)
{
	if (dbtokens.size() == 3)
		_errorMsg = _tbleMgr.addTable(Table(dbtokens[2].data[0], {}));

	_errorMsg = _tbleMgr.addTable(Table(dbtokens[2].data[0], dbtokens[3].data));
}

void Database::select(const std::vector<DBToken>& dbtokens)
{
	_selectedTable = nullptr;
	_selectedCols.clear();

	std::string tableName = dbtokens[3].data[0];

	if (!_tbleMgr.contains(dbtokens[3].data[0]))
	{
		_errorMsg = "No table named \'" + dbtokens[3].data[0] + "\' found";
		return;
	}
	
	//_tbleMgr.printTable(tableName);
	_selectedTable = _tbleMgr.getTablePtr(tableName);

	if (_selectedTable)
	{
		if (_tbleMgr.colsExist(tableName, dbtokens[1].data))
		{
			if (dbtokens.size() > 5)
			{
				std::string operation = findOperation(dbtokens[5].data[0]);
				std::pair<std::string, std::string> condition = findPair(dbtokens[5].data[0], operation);

			}
			else
			{
				_selectedCols = dbtokens[1].data;
				int rowCount = 0;
				for (int i = 0; i < _selectedCols.size(); ++i)
				{
					int curCount = _selectedTable->count(_selectedCols[i]);
					if (rowCount < curCount)
						rowCount = curCount;
				}

				_selectedSheet = Spreadsheet(rowCount, _selectedCols.size(),
					_selectedTable->getSelectedCols(dbtokens[1].data));
			}
		}
	}
}

void Database::insert(const std::vector<DBToken>& dbtokens)
{
	//insertRow(name, columns list, values list)
	_errorMsg = _tbleMgr.insertRow(dbtokens[2].data[0], dbtokens[3].data, dbtokens[5].data); 
}

void Database::deleteData(const std::vector<DBToken>& dbtokens)
{
	if(dbtokens.size() > 3) //delete on condition
	{
		std::string operation = findOperation(dbtokens[4].data[0]);
		std::pair<std::string, std::string> condition = findPair(dbtokens[4].data[0], operation);
		_errorMsg = _tbleMgr.deleteData(dbtokens[2].data[0], condition, operation);

		//_tbleMgr.printTable(dbtokens[2].data[0]);
	}
	else //delete whole table
	{
		_errorMsg = _tbleMgr.deleteTable(dbtokens[2].data[0]);
	}
}
