#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// struct sockaddr_in 
// { 
//     __uint8_t         sin_len; 
//     sa_family_t       sin_family; 
//     in_port_t         sin_port; 
//     struct in_addr    sin_addr; 
//     char              sin_zero[8]; 
// };

int main(int ac, char **av)
{
	int server_fd = 0;
	struct sockaddr_in address;
	struct	socklen_t *addrlen;
	server_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (!server_fd)
	{
		printf("Can't Create a Socket");
		return (1);
	}
	memset(&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY); 
	address.sin_port = htons(40000);
	if (bind(server_fd,(struct sockaddr *)&address,sizeof(address)) < 0) 
	{ 
		printf("Can't bind to a Socket");
		return 1; 
	}
	if (listen(server_fd, 5) < 0)
	{
		printf("Cant listen to Socket");
		return (1);
	}
	int new_socket = 0;
	while (1)
	{
		printf("Sheel mn alserver\n\n");
		new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
		if (!new_socket)
		{
			printf("Cant accept to Socket");
			return (1);
		}
		char *msg = malloc(10000);
		if (!msg)
			return (0);
		int read_bytes = read(new_socket, msg, 1000);
		if (read_bytes < 0)
		{
			printf("nothing to print");
			return (1);
		}
		printf("%s\n", msg);
		// free(msg);
		char *send_to = malloc(10000);
		if (!send_to)
			return (0);
		send_to = "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 180\n\n\n<h1 >testing</h1>\n\n<h1 style=""color:Tomato;"">Hello World</h1>\n<p style=""color:DodgerBlue;"">Lorem ipsum...</p>\n<p style=""color:MediumSeaGreen;"">Ut wisi enim...</p>\n";
		// printf("%s\n", send_to);
		write (new_socket, send_to, strlen(send_to));
		
		// free send_to
		// if (send_to)
		// 	free(send_to);
	}
		close(new_socket);
	printf("fd value = %d", server_fd);
}

// <h1 style="color:Tomato;">Hello World</h1>\n<p style="color:DodgerBlue;">Lorem ipsum...</p>\n<p style="color:MediumSeaGreen;">Ut wisi enim...</p>