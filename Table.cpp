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
	bool found = false;
	for (auto& i : _cols)
	{
		if (i == column)
			found = true;
	}

	if (found)
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

bool Table::matchCondition(const std::string& first, const std::string& second, const std::string& operation)
{
	if (operation == "=")
		return first == second;
	else if (operation == "<")
		return first < second;
	else if (operation == ">")
		return first > second;
	else if (operation == "<=")
		return first <= second;
	else if (operation == ">=")
		return first >= second;

	return false;
}

void Table::deleteData(const std::pair<std::string, std::string>& condition, const std::string& operation)
{
	std::cout << condition.first << std::endl;
	if(count(condition.first) > 0)
	{
		auto range = equal_range(condition.first);

		for (auto itr = range.first; itr != range.second;)
		{
			/*if (itr->second == condition.second)
				itr = erase(itr);*/

			if(matchCondition(itr->second, condition.second, operation))
				itr = erase(itr);

			else
				++itr;
		}
	}
}

std::map<std::string, std::vector<std::string>> Table::getSelectedCols(const std::vector<std::string>& colNames, const std::pair<std::string, std::string>& condition, const std::string& operation)
{
	std::map<std::string, std::vector<std::string>> res;

	for (int i = 0; i < colNames.size(); ++i)
	{
		auto range = equal_range(colNames[i]);
		std::vector<std::string> temp;

		for (auto itr = range.first; itr != range.second; ++itr)
		{
			if (!condition.second.empty())
			{
				if (matchCondition(itr->second, condition.second, operation))
					temp.push_back(itr->second);
			}
			else
				temp.push_back(itr->second);

		}

		res.insert({ colNames[i], temp });
	}

	return res;
}

std::ostream& operator<<(std::ostream& cout, const Table& table)
{
	for (auto& pair : table)
	{
		cout << pair.first << " " << pair.second << std::endl;
	}

	return cout;
}
