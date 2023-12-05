#ifndef CONFIGURATION_HPP
# define CONFIGURATION_HPP

#include <iostream>
#include <map>

class Configuration
{
	private:
		std::map<std::string, std::string>	contents;
	public:
		Configuration();
		Configuration(Configuration &w);
		Configuration &operator=(Configuration &w);
		~Configuration();
};

#endif