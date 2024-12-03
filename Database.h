#ifndef DATABASEH
#define DATABASEH

#include "TableManager.h"
#include "Queries.h"
#include "DBToken.h"

class Database
{
private:
	TableManager _tbleMgr;

	void createTable(const std::vector<DBToken>& dbtokens);
	void select(const std::vector<DBToken>& dbtokens);
	void insert(const std::vector<DBToken>& dbtokens);
	void deleteData(const std::vector<DBToken>& dbtokens);
	std::vector<DBToken> parse(const std::vector<Query>& queries, const std::vector<std::string>& tokens);
	DBToken getVariables(const std::string& str);
	std::vector<std::string> cutStr(const std::string& str, char delimiter); //returns vector of substrs split by every instance of delimiter
	std::pair<std::string, std::string> findPair(const std::string& str, char delimiter); //returns pair split from str on the first instance of delimiter
	bool isCommand(Query q);

public:
	Database();
	void run(const std::vector<Query>& queries, const std::vector<std::string>& tokens);
	const Table& getTable(const std::string& tableName) const;
};

#endif