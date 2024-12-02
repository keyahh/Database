#ifndef TABLEMANAGER
#define TABLEMANAGER

#include <unordered_map>
#include "Table.h"

class TableManager : public std::unordered_map<std::string, Table>
{
private:

public:
	TableManager();

	void addTable(const Table& table);
	const Table& getTable(const std::string& tableName) const;
};

#endif
