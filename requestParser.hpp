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
		std::map<std::string, std::string>	requestContent;
	public:
		RequestParser(const std::string &content);
		void	requestTokenizer(const std::string &requestString);
		void	validateRequesLine(const std::string &requestLine);
		void	loadRequestContent(const std::vector<std::string> &requestVec);
		~RequestParser();
};


#endif