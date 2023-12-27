#ifndef REQUESTPARSER_HPP
# define REQUESTPARSER_HPP

// #include "webserv.hpp"
#include <string>
#include <map>
#include <iostream>
#include <vector>


// enum requestMethod
// {
// 	GET,
// 	POST,
// };

class RequestParser
{
	private:
		std::string							requestMethod;
		std::string							requestPath;
		std::string							host;
		std::map<std::string, std::string>	requestContent;
		void				setRequestPath(const std::string &str);
		void				setRequestMethod(const std::string &str);
	public:
		RequestParser(const std::string &content);
		void				requestTokenizer(const std::string &requestString);
		void				validateRequesLine(const std::string &requestLine);
		void				setHost(const std::string &hostName);
		const std::string	&getHost() const;
		const std::string	&getRequestMethod() const;
		const std::string	&getRequestPath() const;
		const std::map<std::string, std::string> &getRequestContent() const;
		void				loadRequestContent(const std::vector<std::string> &requestVec);
		std::vector<std::string> splitByString(const std::string &str, const char *del);
		~RequestParser();
};


#endif