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
	std::vector<std::vector<bool>> _adjMatrix;
	std::unordered_map<Query, std::set<Query>> _edges;
	int _verticesCount = 0;
	void depthFirst(std::vector<bool>& visited, Query vertex);
	Query translate(const std::string& str);
	bool isConnected(const std::string& a, const std::string& b);

public:
	Graph(int verticesCount = 16);
	Graph(const std::unordered_map<std::string, std::set<std::string>>& map, int verticesCount = 16);
	void init(int verticesCount);

	void addVertex();
	void addEdge(const std::string& source, const std::set<std::string>& targetSet);
	bool isEdge(Query source, Query target);
	std::set<Query> getNeighbors(Query vertex);
	bool checkPath(const std::vector<std::string>& tokens);

	void depthFirst(Query vertex);
};

#endif
