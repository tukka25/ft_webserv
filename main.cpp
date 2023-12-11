# include "webserv.hpp"


int main(int ac, char **av)
{
    // struct sockaddr_in address;
    (void)av;
    if (ac == 2)
    {
        int socket_fd;
        socket_fd = socket(PF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0)
        {
            std::cout << "Cant create a Socket" << std::endl;
            return (1);
        }
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_ANY); 
        address.sin_port = htons(40000);
        if (bind(socket_fd,  (sockaddr *)&address, sizeof(address)) < 0)
        {
            std::cout << "Can't Bind The Socket" << std::endl;
            return (1);
        }
        if (listen(socket_fd, 5) < 0)
        {
            printf("Cant listen to Socket");
            return (1);
        }
        int new_socket = 0;
        // while (1)
        // {
            printf("Sheel mn alserver\n\n");
            new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
            if (!new_socket)
            {
                printf("Cant accept to Socket");
                return (1);
            }
            // char *msg = malloc(10000);
            std::string msg;
            // if (!msg)
            //     return (0);
            int read_bytes = read(new_socket, msg.c_str(), 1000);
            if (read_bytes < 0)
            {
                printf("nothing to print");
                return (1);
            }
            // printf("%s\n", msg);
            // free(msg);
            // char *send_to = malloc(10000);
            // if (!send_to)
            //     return (0);
            // send_to = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
            // printf("%s\n", send_to);
            // write (new_socket, send_to, strlen(send_to));
            
            // free send_to
            // if (send_to)
            //     free(send_to);
        // }
            // close(new_socket);
        printf("fd value = %d", socket_fd);
    }
    else
    {
        std::cerr << "Invalid Number Of Agruments" << std::endl;
        return (1);
    }
}
