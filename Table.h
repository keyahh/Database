#ifndef TABLEH
#define TABLEH

#include <map>
#include <string>
#include <vector>

class Table : public std::multimap<std::string, std::string>
{
private:
	std::string _name;
	std::vector<std::string> _cols;

public:
	Table(const std::string& name = "");
	Table(const std::string& name, const std::vector<std::string>& colNames);
	const std::string& getName() const;
	void addEntry(const std::string& column, const std::string& entry);
	std::vector<std::string> getData(const std::string& column);
};

#endif