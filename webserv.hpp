#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>

struct sockaddr_in address;
fd_set	fr, fw, fe;
// struct	socklen_t *addrlen;

class Webserv
{
	// private:

	// public:
	// 	Webserv();
	// 	Webserv(Webserv &w);
	// 	Webserv &operator=(Webserv &w);
	// 	~Webserv();
};

#endif