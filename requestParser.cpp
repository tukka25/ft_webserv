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
		tmp = tmp.substr(tmp.find("\r\n") + 2, tmp.length());
		// tmp =  tmp.substr(2, tmp.length());
		if (tmp.empty() || tmp == "\r\n")
			break ;

	}
	std::vector<std::string>::iterator	it = requestVec.begin();
	for (;it != requestVec.end(); it++)
		std::cout << "{" << *it << "}" << std::endl;
	validateRequesLine(requestVec[0]);
	loadRequestContent(requestVec);
	std::cout << std::endl << std::endl;
	std::map<std::string, std::string>::iterator	t = requestContent.begin();
	for (;t != requestContent.end(); t++)
		std::cout << "{" << t->first << "}" << "==>" << t->second << std::endl;
	std::cout << "Method ==> " << getRequestMethod() << std::endl;
	std::cout << "Path   ==> " << getRequestPath() << std::endl;
	std::cout << "Host   ==> " << getHost() << std::endl;
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
		if (i == 0 && std::find(possibleMethods.begin(), possibleMethods.end(), token) == possibleMethods.end())
			throw (std::runtime_error(token + " Is Unkown Method")); //400 bad request
		if (i == 0)
			this->setRequestMethod(token);
		if (i == 1)
			this->setRequestPath(token);
		i++;
	}
}

void	RequestParser::loadRequestContent(const std::vector<std::string> &requestVec)
{
	std::stringstream			ss;
	std::vector<std::string>	splitedTokens;

	if (requestVec.empty())
		throw (std::runtime_error("Invalid Get Contents"));
	std::vector<std::string>::const_iterator	it = requestVec.begin() + 1;
	for (; it != requestVec.end(); it++)
	{
		splitedTokens = splitByString(*it, ": ");
		if (splitedTokens.size() < 2)
			throw (std::runtime_error("Bad Request"));
		this->requestContent.insert(std::pair<std::string, std::string>(splitedTokens[0], splitedTokens[1]));
	}
	if (this->requestContent.find("Host") == this->requestContent.end())
		throw (std::runtime_error("Bad Request")); // 400 bad request
	this->setHost((this->requestContent.find("Host"))->second);
}

std::vector<std::string> RequestParser::splitByString(const std::string &str, const char *del)
{
	std::vector<std::string>	tokens;
	std::string					splitedString;
	std::string					save;

	save = str;
	for (size_t i = 0; i < save.length(); i++)
	{
		if (save.find(del) != std::string::npos)
		{
			splitedString = save.substr(0, save.find(del));
			save = save.substr(save.find(del), save.length());
		}
		else
		{
		 	splitedString = save.substr(0, save.length());
			save = "";
		}
		if (save.length() >= 2)
			save = save.substr(2, save.length());
		tokens.push_back(splitedString);
		if (save.empty() || save.length() == 1)
			break ;
	}
	if (!save.empty())
	{
		splitedString = save.substr(0, save.length());
		tokens.push_back(splitedString);
	}
	return (tokens);
}

void	RequestParser::setHost(const std::string &hostName)
{
	this->host = hostName;
}

const std::string	&RequestParser::getHost() const
{
	return (this->host);
}

void	RequestParser::setRequestPath(const std::string &str)
{
	this->requestPath = str;
}

void	RequestParser::setRequestMethod(const std::string &str)
{
	this->requestMethod = str;
}

const std::string	&RequestParser::getRequestMethod() const
{
	return (this->requestMethod);
}

const std::string	&RequestParser::getRequestPath() const
{
	return (this->requestPath);
}

const std::map<std::string, std::string> &RequestParser::getRequestContent() const
{
	return (this->requestContent);
}

RequestParser::~RequestParser()
{
}