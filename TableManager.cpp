#include "TableManager.h"

TableManager::TableManager()
{
}

void TableManager::addTable(const Table& table)
{
	if (!contains(table.getName()))
		insert({ table.getName(), table});
}

void TableManager::insertRow(const std::string& tableName, const std::vector<std::string>& columns, const std::vector<std::string>& values)
{
	if (columns.size() != values.size())
		return;

	if (contains(tableName))
	{
		for (int i = 0; i < columns.size(); ++i)
		{
			at(tableName).addEntry(columns[i], values[i]);
		}
	}
}

void TableManager::deleteData(const std::string& tableName, const std::pair<std::string, std::string>& condition, const std::string& operation)
{
	if (contains(tableName))
	{
		at(tableName).deleteData(condition, operation);
	}
}

void TableManager::deleteTable(const std::string& tableName)
{
	if (contains(tableName))
		erase(tableName);
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
