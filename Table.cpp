#include "Table.h"

Table::Table(const std::string& name)
	: _name(name)
{
}

Table::Table(const std::string& name, const std::vector<std::string>& colNames)
	:_name(name), _cols(colNames)
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

void Table::deleteData(const std::pair<std::string, std::string>& condition)
{
	if(count(condition.first) > 0)
	{
		auto range = equal_range(condition.first);

		for (auto itr = range.first; itr != range.second;)
		{
			if (itr->second == condition.second)
				itr = erase(itr);
			else
				++itr;
		}
	}
}
