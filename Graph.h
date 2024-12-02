#ifndef GRAPH
#define GRAPH

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <initializer_list>
#include "Queries.h"

class Graph
{
private:
	std::unordered_map<Query, std::set<Query>> _edges;
	int _verticesCount = 0;
	Query translate(const std::string& str);
	Query validateVar(Query var, Query prev);
	Query validateVarList(const std::string& token, Query prev);

public:
	Graph(int verticesCount = 18);
	Graph(const std::unordered_map<std::string, std::set<std::string>>& map, int verticesCount = 18);
	void init(int verticesCount);

	void addEdge(const std::string& source, const std::set<std::string>& targetSet);
	bool isEdge(Query source, Query target);
	std::set<Query> getNeighbors(Query vertex);
	std::vector<Query> convertTokens(const std::vector<std::string>& tokens);
	bool checkPath(const std::vector<Query>& tokens);
};

#endif
