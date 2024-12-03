#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Queries.h"

struct DBToken
{
	Query command = Query::UNKNOWN;
	std::vector<std::string> data;

	DBToken(Query query = Query::UNKNOWN);
	DBToken(const std::vector<std::string>& data);

	friend std::ostream& operator<<(std::ostream& cout, const DBToken& dbtoken);
};