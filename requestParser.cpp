#include "requestParser.hpp"
#include <cstddef>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

RequestParser::RequestParser(const std::string &requestParser)
{
	if (requestParser.empty())
		throw (std::runtime_error("Error While Getting The Request"));
	this->requestTokenizer(requestParser);
}

void RequestParser::requestTokenizer(const std::string &requestString)
{
	std::stringstream	ss(requestString);
	std::string			line;

	while (std::getline(ss, line, '\n'))
	{
		std::cout << line << std::endl;
		for (size_t i = 0; i < line.length(); i++)
		{
			std::cout << "\'" << line[i] << "\'" << std::endl;
		}
	}
}

RequestParser::~RequestParser()
{
}