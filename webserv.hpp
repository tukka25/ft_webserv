#ifndef WEBSERV_HPP
# define WEBSERV_HPP

#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <ostream>
#include <sstream>
#include <string>
#include <sys/_endian.h>
#include <sys/_select.h>
#include <sys/_types/_fd_def.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

struct sockaddr_in address;
fd_set	fr, fw, fe;
// socklen_t addrlen =;

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