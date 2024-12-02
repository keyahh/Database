#ifndef TABLEH
#define TABLEH

#include <map>
#include <string>
#include <vector>

class Table : public std::multimap<std::string, std::string>
{
private:
	std::string _name;
public:
	Table(const std::string& name = "");
	const std::string& getName() const;
	void addEntry(const std::string& column, const std::string& entry);
	std::vector<std::string> getData(const std::string& column);
};

#endif