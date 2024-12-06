#ifndef DATABASEEXCEPTIONH
#define DATABASEEXCEPTIONH

class DatabaseException
{
private:
	const char* _msg;

public:
	DatabaseException(const char* msg = "");
	const char* what() const;
};

#endif