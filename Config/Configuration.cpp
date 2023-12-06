#include "Configuration.hpp"

Configuration::Configuration()
{
}

Configuration::Configuration(Configuration &w)
{
	w.contents = this->contents;
}

Configuration &Configuration::operator=(Configuration &w)
{
	w.contents = this->contents;
}

Configuration::~Configuration()
{
}

void	Configuration::CheckConfFile(std::string str)
{
	confFile.open(str, std::ios::in);
	if (!this->confFile)
		throw (ConfException());
}

const char* ConfException::what() const throw()
{
	return ("File doesnt exist or wrong permissions");
}