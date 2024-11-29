#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::FileReader(const std::string& filePath)
{
	std::ifstream fin;
	fin.open(filePath);
	if (fin.fail())
	{
		exit(1);
	}

	std::string temp;
	while (std::getline(fin, temp))
	{
		_words.push_back(temp);
	}
	fin.close();
}

const std::vector<std::string>& FileReader::getWords() const
{
	return _words;
}
