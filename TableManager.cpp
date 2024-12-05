#include "TableManager.h"

TableManager::TableManager()
{
}

std::string TableManager::addTable(const Table& table)
{
	if (!contains(table.getName()))
	{
		insert({ table.getName(), table });
		return "";
	}
	return "Another table with the name \'" + table.getName() + "\' already exists";
}

std::string TableManager::insertRow(const std::string& tableName, const std::vector<std::string>& columns, const std::vector<std::string>& values)
{
	if (columns.size() != values.size())
		return std::to_string(values.size()) + " values for " + std::to_string(columns.size()) + " columns";

	if (contains(tableName))
	{
		std::string temp;
		for (int i = 0; i < columns.size(); ++i)
		{
			temp = at(tableName).addEntry(columns[i], values[i]);
		}
		return temp;
	}
	return "No table with the name \'" + tableName + "\' can be found";
}

std::string TableManager::deleteData(const std::string& tableName, const std::pair<std::string, std::string>& condition, const std::string& operation)
{
	if (contains(tableName))
	{
		at(tableName).deleteData(condition, operation);
		return "";
	}
	return "No table with the name \'" + tableName + "\' can be found";
}

std::string TableManager::deleteTable(const std::string& tableName)
{
	if (contains(tableName))
	{
		erase(tableName);
		return "";
	}
	return "No table with the name \'" + tableName + "\' can be found";
}

const Table& TableManager::getTable(const std::string& tableName) const
{
	if (contains(tableName))
		return at(tableName);
}

Table* TableManager::getTablePtr(const std::string& tableName)
{
	if (contains(tableName))
		return &(at(tableName));

	return nullptr;
}

bool TableManager::colsExist(const std::string& tableName, const std::vector<std::string>& colNames)
{
	if (contains(tableName))
	{
		for (auto& c : colNames)
		{
			if (!at(tableName).contains(c))
				return false;
		}

		return true;
	}

	return false;
}

void TableManager::printTable(const std::string& tableName)
{
	if (contains(tableName))
	{
		std::cout << at(tableName);
	}
}

bool TableManager::hasTable(const std::string& tableName)
{
	return contains(tableName);
}
