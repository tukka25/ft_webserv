#include "requestParser.hpp"
#include <cctype>
#include <cstddef>
#include <cstring>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

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
	// std::cout << requestString << std::endl;
	for (size_t i = 0; i < tmp.length(); i++)
	{
		line = tmp.substr(0, tmp.find("\r\n"));
		if (tmp.find("\r\n") == std::string::npos)
		{
			requestVec.push_back(line);
			break ;
		}
		// std::cout << "line = " << "{" << line << "}" << std::endl;
		if (line.empty())
			throw (std::runtime_error("Get Error"));
		requestVec.push_back(line);
		tmp = tmp.substr(tmp.find("\r\n") + 2, tmp.length());
		if (tmp.empty() || tmp == "\r\n")
			break ;

	}
	// std::vector<std::string>::iterator it = requestVec.begin();
	// for (;it != requestVec.end(); it++)
	// 	std::cout << "{" << *it << "}" << std::endl;
	// std::cout << "request line = " << requestVec[0] << std::endl;
	validateRequesLine(requestVec[0]);
	loadRequestContent(requestVec);
	// std::cout << std::endl << std::endl;
	// std::map<std::string, std::string>::iterator	t = requestContent.begin();
	// for (;t != requestContent.end(); t++)
	// 	std::cout << "{" << t->first << "}" << "==>" << t->second << std::endl;
	// std::cout << "Method  ==> " << getRequestMethod() << std::endl;
	// std::cout << "Path    ==> " << geturi() << std::endl;
	// std::cout << "Host    ==> " << getHost() << std::endl;
	// std::cout << "Version ==> " << getVersion() << std::endl;
	// std::cout << "Accept  ==> " << getFromRequest("Acept") << std::endl;
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
		if (i == 0 && !token.empty())
			this->setRequestMethod(token);
		if (i == 1 && !token.empty())
		{
			this->validateUri(token);
			this->seturi(token);
		}
		if (i == 2 && !token.empty())
		{
			this->validateVersion(token);
			this->setVersion(token);
		}
		if (!token.empty())
			i++;
	}
	if (i != 3)
		throw (std::runtime_error("400 Bad Request"));
}

void	RequestParser::validateUri(const std::string &str)
{
	if (str.empty() || str.find("/") == std::string::npos)
		throw (std::runtime_error("400 Bad Request"));
}

void	RequestParser::checkArgsNumber(const std::string &arg)
{
	std::string		content;

	if (arg.empty())
		return;
	content = arg;
}

void	RequestParser::searchForHost()
{
	std::map<std::string, std::string>::iterator mapIt = this->requestContent.begin();
	std::string	lowerKey;

	for (;mapIt != this->requestContent.end(); mapIt++)
	{
		lowerKey.resize(mapIt->first.size());
		std::transform(mapIt->first.begin(), mapIt->first.end(), lowerKey.begin(), ::tolower);
		if (lowerKey == "host")
			return ;
	}
	throw (std::runtime_error("400 bad Request"));
}

void	RequestParser::loadRequestContent(const std::vector<std::string> &requestVec)
{
	std::stringstream			ss;
	std::vector<std::string>	splitedTokens;
	std::string					token;
	std::string					value;
	std::string					lowerString;

	if (requestVec.empty())
		throw (std::runtime_error("Invalid Get Contents"));
	std::vector<std::string>::const_iterator	it = requestVec.begin() + 1;
	for (; it != requestVec.end(); it++)
	{
		std::stringstream			ss(*it);
		value = *it;
		token = *it;
		std::getline(ss, token, ':');
		lowerString.resize(token.size());
		std::transform(token.begin(), token.end(), lowerString.begin(), ::tolower);
		if (lowerString  == "host")
			validateHost(value);
		else
			validateValue(value);
		this->requestContent.insert(std::pair<std::string, std::string>(token, value));
	}
	this->searchForHost();
	this->setHost((this->requestContent.find("Host"))->second);
}

void			RequestParser::validateHost(std::string &hostName)
{
	std::string		value;
	std::string		tmp;
	std::stringstream	ss;
	std::string	token;
	std::vector<std::string>			tokens;
	static int i;

	if (i > 0)
		throw (std::runtime_error("400 Bad Request"));
	tmp = hostName;
	if (hostName.empty())
	{
		hostName = "";
		return;
	}
	value = tmp.substr(tmp.find(':') + 1, tmp.length());
	if (value.empty())
		throw (std::runtime_error("400 Bad Request"));
	ss << value;
	while (std::getline(ss, token, ' '))
	{
		if (!token.empty())
			tokens.push_back(token);
	}
	if (tokens.size() != 1)
		throw (std::runtime_error("400 Bad Request"));
	if (tokens[0][0] == ':')
		throw (std::runtime_error("400 Bad Request"));
	hostName = tokens[0];
	i++;
}

void	RequestParser::validateValue(std::string &hostName)
{
	std::string		value;
	std::string		tmp;

	value = hostName;
	tmp = hostName;
	if (hostName.empty())
	{
		hostName = "";
		return;
	}
	if (tmp.find(':') == std::string::npos && tmp.find(' ') != std::string::npos)
		throw (std::runtime_error("400 Bad Request"));
	value = tmp.substr(tmp.find(':') + 1, tmp.length());
	if (value.empty() || value == hostName)
		hostName = "";
	else
		hostName = value;
}

bool	RequestParser::checkVersionNumber(const std::string &str)
{
	if (str.length() == 3 && std::isdigit(str[0]) && str[1] == '.' && std::isdigit(str[2]))
	{
		float version = std::stof(str);
		if (version >= 1 && version <= 1.9)
			return true;
		else
			throw (std::runtime_error("505 HTTP Version Not Supported"));
	}
	return false;
}

void	RequestParser::validateVersion(const std::string &version)
{
	if (version.empty() || version.find("/") == std::string::npos || version.find(".") == std::string::npos)
		throw (std::runtime_error("400 Bad Request"));
	if (std::count(version.begin(), version.end(), '.') != 1)
		throw (std::runtime_error("400 Bad Request"));
	std::stringstream	ss(version);
	std::string			token;
	int					i = 0;
	while (std::getline(ss, token, '/'))
	{
		if (i == 0 && token != "HTTP")
			throw (std::runtime_error("400 Bad Request"));
		if (i == 1)
		{
			if (!this->checkVersionNumber(token))
				throw (std::runtime_error("400 Bad Request"));
		}
		i++;

	}
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

const std::string	&RequestParser::getFromRequest(const std::string &key) const
{
	static std::string	s = "";
	if (this->requestContent.find(key) != this->requestContent.end())
		return (this->requestContent.find(key)->second);
	else
		return (s);
}


void	RequestParser::setVersion(const std::string &str)
{
	this->version = str;
}

const std::string &RequestParser::getVersion() const
{
	return (this->version);
}

const std::string	&RequestParser::getHost() const
{
	return (this->host);
}

void	RequestParser::seturi(const std::string &str)
{
	this->uri = str;
}

void	RequestParser::setRequestMethod(const std::string &str)
{
	this->requestMethod = str;
}

const std::string	&RequestParser::getRequestMethod() const
{
	return (this->requestMethod);
}

const std::string	&RequestParser::geturi() const
{
	return (this->uri);
}

const std::map<std::string, std::string> &RequestParser::getRequestContent() const
{
	return (this->requestContent);
}

RequestParser::~RequestParser()
{
}