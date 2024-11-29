#ifndef WORDSORT
#define WORDSORT

#include "FileReader.h"
#include "Heap.h"
#include "Word.h"

class WordSort
{
private:
	FileReader _reader;
	std::vector<Word> _sortedWords;
	Word rankWord(const std::string& text, const std::string& word);
	int levenshtein(const std::string& word1, const std::string& word2);
	std::vector<std::vector<int>> createGrid(int size);
	int strDifference(const std::string& word1, const std::string& word2);
	const std::string& findLongerWord(const std::string& word1, const std::string& word2);
	const std::string& findShorterWord(const std::string& word1, const std::string& word2);
	std::string lowercase(const std::string& word);
public:
	WordSort();
	WordSort(const std::string& filePath);
	const std::vector<Word>& prioritize(const std::string& text);
	const std::vector<std::string>& getWords() const;
};

#endif