#ifndef TABLEMANAGER
#define TABLEMANAGER

#include <unordered_map>
#include "Table.h"

class TableManager : public std::unordered_map<std::string, Table>
{
private:

public:
	TableManager();

	std::string addTable(const Table& table);
	std::string insertRow(const std::string& tableName, const std::vector<std::string>& columns, 
		const std::vector<std::string>& values);
	std::string deleteData(const std::string& tableName, const std::pair<std::string, std::string>& condition, const std::string& operation = "=");
	std::string deleteTable(const std::string& tableName);
	const Table& getTable(const std::string& tableName) const;
	Table* getTablePtr(const std::string& tableName);
	bool colsExist(const std::string& tableName, const std::vector<std::string>& colNames);
	void printTable(const std::string& tableName);
	bool hasTable(const std::string& tableName);
};

#endif
