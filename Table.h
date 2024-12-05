#ifndef TABLEH
#define TABLEH

#include <map>
#include <string>
#include <vector>
#include <iostream>

class Table : public std::multimap<std::string, std::string>
{
private:
	std::string _name;
	std::vector<std::string> _cols;

	bool matchCondition(const std::string& first, const std::string& second, const std::string& operation);

public:
	Table(const std::string& name = "");
	Table(const std::string& name, const std::vector<std::string>& colNames);
	const std::string& getName() const;
	std::string addEntry(const std::string& column, const std::string& entry);
	std::vector<std::string> getData(const std::string& column);
	void deleteData(const std::pair<std::string, std::string>& condition, const std::string& operation);

	std::map<std::string, std::vector<std::string>> getSelectedCols(const std::vector<std::string>& colNames, const std::pair<std::string, std::string>& condition = {}, const std::string& operation = "=");

	friend std::ostream& operator<<(std::ostream& cout, const Table& table);
};

#endif