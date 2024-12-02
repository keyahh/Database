#include "Table.h"

Table::Table(const std::string& name)
	: _name(name)
{
}

const std::string& Table::getName() const
{
	return _name;
}

void Table::addEntry(const std::string& column, const std::string& entry)
{
	if (contains(column))
	{
		this->insert({ column, entry });
	}
}

std::vector<std::string> Table::getData(const std::string& column)
{
	if (contains(column))
	{
		std::vector<std::string> data;

		for (auto& pair : *this)
		{
			if (pair.first == column)
				data.push_back(pair.second);
		}

		return data;
	}
}
