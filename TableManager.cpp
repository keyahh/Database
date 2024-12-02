#include "TableManager.h"

TableManager::TableManager()
{
}

void TableManager::addTable(const Table& table)
{
	if (!contains(table.getName()))
		insert({ table.getName(), table});
}

const Table& TableManager::getTable(const std::string& tableName) const
{
	if (contains(tableName))
		return at(tableName);
}
