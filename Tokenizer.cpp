#include "Tokenizer.h"

std::vector<std::string> Tokenizer::tokenize(const std::string& input)
{
    std::vector<std::string> tokens;
    std::string temp;
    std::stringstream ss(input);

    while (ss >> temp)
    {
        tokens.push_back(temp);
    }

    return tokens;
}
