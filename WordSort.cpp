#include "WordSort.h"

WordSort::WordSort()
{
}

WordSort::WordSort(const std::string& filePath)
{
	_reader = FileReader(filePath);
}

const std::vector<std::string>& WordSort::getWords() const
{
	return _reader.getWords();
}

Word WordSort::rankWord(const std::string& text, const std::string& word)
{
	int priority = levenshtein(lowercase(text), lowercase(word));
	//int priority = strDifference(lowercase(text), lowercase(word));
	return Word(word, priority);
}

int WordSort::levenshtein(const std::string& victim, const std::string& target)
{
	if (victim == target)
		return 10001;

	int targetSize = target.size();
	std::vector<std::vector<int>> grid = createGrid(targetSize);

	for (int i = 1; i <= victim.size(); ++i)
	{
		grid[1][0] = i + 1;

		for (int j = 1; j <= targetSize; ++j)
		{
			if (victim[i - 1] == target[j - 1])
				grid[1][j] = grid[0][j - 1];

			else
				grid[1][j] = 1 + std::min(grid[1][j-1], std::min(grid[0][j], grid[0][j-1]));
		}
		grid[0] = grid[1];
	}

	return 10000 - grid[1][targetSize];
}

std::vector<std::vector<int>> WordSort::createGrid(int targetSize)
{
	std::vector<std::vector<int>> grid(2, std::vector<int>(targetSize + 1, 0));
	for (int i = 0; i <= targetSize; ++i)
		grid[0][i] = i;

	return grid;
}

int WordSort::strDifference(const std::string& victim, const std::string& target)
{
	if (victim == target)
		return 10001;
	else
	{
		int difference = std::abs((int)(victim.length() - target.length()));

		std::string longest = findLongerWord(victim, target), shortest = findShorterWord(victim, target);
		
		for (int i = 0; i < victim.size(); ++i)
		{
			for (int j = 0; j < target.size(); ++j)
			{

			}
		}

		return 10000 - difference;
	}
}

const std::string& WordSort::findLongerWord(const std::string& victim, const std::string& target)
{
	if (victim.length() >= target.length())
		return victim;
	return target;
}

const std::string& WordSort::findShorterWord(const std::string& victim, const std::string& target)
{
	if (victim.length() <= target.length())
		return victim;
	return target;
}

std::string WordSort::lowercase(const std::string& word)
{
	std::string ans = "";
	for (auto& c : word)
	{
		ans.push_back(std::tolower(c));
	}
	return ans;
}

const std::vector<Word>& WordSort::prioritize(const std::string& text)
{
	_sortedWords.clear();
	Heap<Word> heap;
	for (int i = 0; i < _reader.getWords().size(); ++i)
	{
		heap.push(rankWord(text, _reader.getWords()[i]));
	}

	for(int i = 0; i < 3; ++i)
	{
		_sortedWords.push_back(heap.top());
		heap.pop();
	}

	return _sortedWords;
}
