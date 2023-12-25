#include "requestParser.hpp"
#include <cstddef>
#include <cstring>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

RequestParser::RequestParser(const std::string &requestParser)
{
	if (requestParser.empty())
		throw (std::runtime_error("Error While Getting The Request"));
	this->requestTokenizer(requestParser);
}

void RequestParser::requestTokenizer(const std::string &requestString)
{
	// std::stringstream	ss(requestString);
	std::string			line;
	std::string			tmp = requestString;
	std::vector<std::string>	requestVec;
	std::cout << requestString << std::endl;
	for (size_t i = 0; i < tmp.length(); i++)
	{
		line = tmp.substr(0, tmp.find("\r\n"));
		if (line.empty())
			throw (std::runtime_error("Get Error"));
		requestVec.push_back(line);
		std::cout << "line = " << line << std::endl;
		tmp = tmp.substr(tmp.find("\r\n") + 2, tmp.length());
		std::cout << "tmp = " << tmp << std::endl;
		// tmp =  tmp.substr(2, tmp.length());
		if (tmp.empty() || tmp == "\r\n")
			break ;

	}
	std::vector<std::string>::iterator	it = requestVec.begin();
	for (;it != requestVec.end(); it++)
		std::cout << "{" << *it << "}" << std::endl;
	validateRequesLine(requestVec[0]);
	loadRequestContent(requestVec);
	std::map<std::string, std::string>::iterator	t = requestContent.begin();
	for (;t != requestContent.end(); t++)
	{
		std::cout << "{" << t->first << "}" << "==>" << t->second << std::endl;
	}
	// }
}

void	RequestParser::validateRequesLine(const std::string &requestLine)
{
	if (requestLine.empty())
		throw (std::runtime_error("Missing Method Type"));
	std::string					token;
	std::stringstream			ss(requestLine);
	std::vector<std::string>	possibleMethods;
	int							i = 0;

	possibleMethods.push_back("GET");
	possibleMethods.push_back("POST");
	possibleMethods.push_back("DELETE");
	while (std::getline(ss, token, ' '))
	{
		std::cout << "token = " << token << std::endl;
		if (i == 0 && std::find(possibleMethods.begin(), possibleMethods.end(), token) == possibleMethods.end())
			throw (std::runtime_error(token + " Is Unkown Method")); //400 bad request
		i++;
	}
}

void	RequestParser::loadRequestContent(const std::vector<std::string> &requestVec)
{
	std::stringstream	ss;
	std::string			token;
	std::string			tmp;
	std::string			host;
	char				*ptr;
	char				*t = NULL;
	int					i = 0;

	if (requestVec.empty())
		throw (std::runtime_error("Invalid Get Contents"));
	std::vector<std::string>::const_iterator	it = requestVec.begin() + 1;
	for (; it != requestVec.end(); it++)
	{
		// ss << *it;
		i = 0;
		// while (std::getline(ss, token, ':'))
		// {
		// 	std::cout << "token in = " << token << std::endl;
		// 	if (i == 0)
		// 		tmp = token;
		// 	if (tmp == "Host" && i != 0)
		// 		host = token;
		// 	// if (tok)
		// 	i++;
		// }
		// ss.clear();
		// if (tmp == "Host")
		// 	token = host + token;
		ptr = std::strtok(t, ": ");
		while (ptr != NULL)
		{
			if (i == 0)
				tmp = t;
			token = ptr;
			ptr = strtok(NULL, ": ");
			i++;
		}
		std::cout << "tmp = " << tmp << std::endl;
		std::cout << "token = " << token << std::endl;
		// this->requestContent.insert(std::pair<std::string, std::string>(tmp, token));
	}
	// if (this->requestContent.find("Host") == this->requestContent.end())
	// 	throw (std::runtime_error("No Host"));
}

RequestParser::~RequestParser()
{
}