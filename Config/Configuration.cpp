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