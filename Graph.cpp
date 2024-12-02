#include "Graph.h"

Graph::Graph(int verticesCount)
{
	init(verticesCount);
}

Graph::Graph(const std::unordered_map<std::string, std::set<std::string>>& map, int verticesCount)
	: _verticesCount(verticesCount)
{
	//init(verticesCount);

	for (auto& segment : map)
	{
		addEdge(segment.first, segment.second);
	}
}

void Graph::init(int verticesCount)
{
	/*_adjMatrix = std::vector<std::vector<bool>>
		(verticesCount, std::vector<bool>(verticesCount, false));*/
	_verticesCount = verticesCount;
}

Query Graph::translate(const std::string& str)
{
	if (str == "START")
		return Query::START;
	else if (str == "SELECT")
		return Query::SELECT;
	else if (str == "INSERT")
		return Query::INSERT;
	else if (str == "CREATE")
		return Query::CREATE;
	else if (str == "TABLE")
		return Query::TABLE;
	else if (str == "COLUMNS")
		return Query::COLUMNS;
	else if (str == "FROM")
		return Query::FROM;
	else if (str == "INTO")
		return Query::INTO;
	else if (str == "END")
		return Query::END;
	else if (str == "*TABLE")
		return Query::TABLE_VAR;
	else if (str == "*COLUMNS")
		return Query::COLUMN_VAR;
	else if (str == "*INSERT_TABLE")
		return Query::INSERT_TABLE;
	else if (str == "*INSERT_COLUMNS")
		return Query::INSERT_COLUMNS;
	else if (str == "*CREATE_COLUMNS")
		return Query::CREATE_COLUMNS;
	else if (str == "*VALUES")
		return Query::VALUES_VAR;
	else if (str == "VALUES")
		return Query::VALUES;
	else if (str == "*CREATE_TABLE")
		return Query::CREATE_TABLE;
	else if (str == "DELETE")
		return Query::DELETE;
	else if (str == "WHERE")
		return Query::WHERE;
	else if (str == "*CONDITION")
		return Query::CONDITION_VAR;
	else if (str == "LAUNCH")
		return Query::LAUNCH;
	else if (str == "*LAUNCH")
		return Query::LAUNCH_VAR;
	else
		return Query::UNKNOWN;
}

void Graph::addEdge(const std::string& source, const std::set<std::string>& targetSet)
{
	Query sourceQuery = translate(source);
	std::set<Query> newSet;
	for(auto& t : targetSet)
	{
		Query target = translate(t);
		newSet.insert(target);

		/*if (sourceQuery < _verticesCount && 0 <= sourceQuery && target < _verticesCount && 0 <= target)
		{
			_adjMatrix[sourceQuery][target] = true;
		}*/
	}
	_edges.insert({sourceQuery, newSet});
}

bool Graph::isEdge(Query source, Query target)
{
	//return _adjMatrix[source][target];
	if (_edges.contains(source))
	{
		return _edges[source].contains(target);
	}

	return false;
}

std::set<Query> Graph::getNeighbors(Query vertex)
{
	/*std::set<Query> neighbors;
	for (int i = 0; i < _verticesCount; ++i)
	{
		if (_adjMatrix[vertex][i])
			neighbors.insert(Query(i));
	}
	return neighbors;*/
	return _edges[vertex];
}

Query Graph::validateVar(Query var, Query prev)
{
	switch (prev)
	{
	case Query::TABLE:
		return Query::CREATE_TABLE;
	case Query::CREATE_TABLE:
		return Query::CREATE_COLUMNS;
	case Query::FROM:
		return Query::TABLE_VAR;
	case Query::INTO:
		return Query::INSERT_TABLE;
	case Query::SELECT:
		return Query::COLUMN_VAR;
	case Query::INSERT_TABLE:
		return Query::INSERT_COLUMNS;
	case Query::VALUES:
		return Query::VALUES_VAR;
	case Query::WHERE:
		return Query::CONDITION_VAR;
	}

	return Query::UNKNOWN;
}

Query Graph::validateVarList(const std::string& token, Query prev)
{
	if (token.back() != ')')
		return Query::UNKNOWN;

	else
	{
		switch (prev)
		{
		case Query::CREATE_TABLE:
			return Query::CREATE_COLUMNS;
		}
	}
	return Query();
}

std::vector<Query> Graph::convertTokens(const std::vector<std::string>& tokens)
{
	std::vector<Query> res;

	for (int i = 0; i < tokens.size(); ++i)
	{
		Query temp = translate(tokens[i]);

		if (temp != Query::UNKNOWN)
			res.push_back(temp);

		else
		{
			if(i >= 1)
			{
				/*if(tokens[i][0] == '(')
					temp = validateVarList(tokens[i], res[i - 1]);
				else
					temp = validateVar(temp, res[i - 1]);*/

				temp = validateVar(temp, res[i - 1]);
				if (temp != Query::UNKNOWN)
					res.push_back(temp);
			}
		}
	}

	return res;
}

bool Graph::checkPath(const std::vector<Query>& tokens)
{
	//first command must stem from START
	if(tokens.size() > 0)
	{
		if (!isEdge(Query::START, tokens[0]))
			return false;

		else
		{
			int a = 0, b = 1;
			while (b < tokens.size())
			{
				if (!isEdge(tokens[a], tokens[b]))
					return false;
				++a;
				++b;
			}

			//last command must connect to END
			if (isEdge(tokens.back(), Query::END))
				return true;

			return false;
		}
	}

	return false;
}