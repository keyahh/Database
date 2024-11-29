#ifndef FILEREADERH
#define FILEREADERH

#include <string>
#include <fstream>
#include <vector>

class FileReader
{
private:
	std::vector<std::string> _words;

public:
	FileReader();
	FileReader(const std::string& filePath);
	const std::vector<std::string>& getWords() const;
};

#endif