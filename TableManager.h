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
	void insertRow(const std::string& tableName, const std::vector<std::string>& columns, 
		const std::vector<std::string>& values);
	void deleteData(const std::string& tableName, const std::pair<std::string, std::string>& condition);
	const Table& getTable(const std::string& tableName) const;
	Table* getTablePtr(const std::string& tableName);
	bool colsExist(const std::string& tableName, const std::vector<std::string>& colNames);
	void printTable(const std::string& tableName);
};

#endif
