#ifndef CONFIGURATION_HPP
# define CONFIGURATION_HPP

#include <iostream>
#include <map>
#include <exception>
#include <fstream>

class Configuration
{
	private:
		std::map<std::string, std::string>	contents;
		std::ifstream	confFile;
	public:
		Configuration();
		Configuration(Configuration &w);
		Configuration &operator=(Configuration &w);
		~Configuration();
		void	CheckConfFile(std::string str);
};

class ConfException : public std::exception
{
	public:
		virtual const char* what() const throw();
};
#endif