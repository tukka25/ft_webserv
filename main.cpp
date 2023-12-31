#include "requestParser.hpp"
# include "webserv.hpp"
#include <exception>

int main(int ac, char **av)
{
    // RequestParser   s
    // struct sockaddr_in address;
    (void)av;
    (void)ac;
    try
    {
        RequestParser   parser("GET  /////  HTTP/1.1      \r\nHost:     localhost:90900\r\ndjfkj\r\n");
        std::cout << "Success" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // if (ac == 2)
    // {
        // int socket_fd;
        // socket_fd = socket(PF_INET, SOCK_STREAM, 0);
        // if (socket_fd < 0)
        // {
        //     std::cout << "Cant create a Socket" << std::endl;
        //     return (1);
        // }
        // memset(&address, 0, sizeof(address));
        // address.sin_family = AF_INET;
        // address.sin_addr.s_addr = htonl(INADDR_ANY); 
        // address.sin_port = htons(std::atoi(av[1]));
        // if (bind(socket_fd,  (sockaddr *)&address, sizeof(address)) < 0)
        // {
        //     std::cout << "Can't Bind The Socket" << std::endl;
        //     return (1);
        // }
        // if (listen(socket_fd, 15) < 0)
        // {
        //     printf("Cant listen to Socket");
        //     return (1);
        // }
        // int new_socket = 0;
        // while (1)
        // {
            // printf("Sheel mn alserver\n\n");
            // socklen_t addrlen = sizeof(address);
            // new_socket = accept(socket_fd, (struct sockaddr *)&address, &addrlen);
            // if (new_socket < 0)
            // {
            //     printf("Cant accept to Socket");
            //     return (1);
            // }
            // // char *msg = malloc(10000);
            // char msg[10000];
            // memset(msg, 0, sizeof(msg));
            // msg[9999] = '\0';
            // if (!msg)
            //     return (0);
            // int read_bytes = recv(new_socket, msg, sizeof(msg), 0);
            // std::cout << "heere" << std::endl;
            // RequestParser   parser("\r\n");
            // exit(0);
            // if (read_bytes < 0)
            // {
            //     printf("nothing to print");
            //     return (1);
            // }
            // std::cout << msg << std::endl;
            // std::string send_to;
            // std::string tmp;
            // std::string file;
            // std::string type;
            // // char *send_to[10000];
            // // send_to[9999] = 0;
            // tmp = msg;
            // tmp = tmp.substr(0, tmp.find('\n'));
            // // std::cout << "tmp = " << tmp << std::e
            // std::stringstream ss(tmp);
            // int i = 0;
            // while (ss >> tmp)
            // {
            //     if (i == 1)
            //     {
            //         file = tmp;
            //         break;
            //     }
            //     i++;
            // }
            // std::cout << ss. << std::endl;
            // std::cout << "tmp = "  << tmp << std::endl;
            // file = tmp;
        //     std::cout << "file u = " << file << std::endl;
        //     send_to += "HTTP/1.1 200 OK\r\n";
        //     type = "text/html";
        //     if (file == "/")
        //         file = "index.html";
        //     else if (file.substr(file.length() - 4) == ".css")
        //     {
        //         type = "text/css";
        //     }
        //     else if (file.substr(file.length() - 3) == ".js")
        //     {
        //         type = "text/javascript";
        //     }
        //     else if (file.substr(file.length() - 4) == ".png")
        //     {
        //         type = "image/png";
        //     }
        //     else if (file.substr(file.length() - 4) == ".jpg")
        //     {
        //         type = "image/jpg";
        //     }
        //     else if (file.substr(file.length() - 5) == ".jpeg")
        //     {
        //         type = "image/jpeg";
        //     }
        //     else if (file.substr(file.length() - 4) == ".gif")
        //     {
        //         type = "image/gif";
        //     }
        //     else if (file.substr(file.length() - 4) == ".ico")
        //     {
        //         type = "image/x-icon";
        //     }
        //     else if (file.substr(file.length() - 5) == ".json")
        //     {
        //         type = "application/json";
        //     }
        //     else if (file.substr(file.length() - 4) == ".pdf")
        //     {
        //         type = "application/pdf";
        //     }
        //     else if (file.substr(file.length() - 4) == ".svg")
        //     {
        //         type = "image/svg+xml";
        //     }
        //     else if (file.substr(file.length() - 4) == ".txt")
        //     {
        //         type = "text/plain";
        //     }
        //     else if (file.substr(file.length() - 5) == ".woff")
        //     {
        //         type = "font/woff";
        //     }
        //     else if (file.substr(file.length() - 6) == ".woff2")
        //     {
        //         type = "font/woff2";
        //     }
        //     else if (file.substr(file.length() - 4) == ".xml")
        //     {
        //         type = "application/xml";
        //     }
        //     else if (file.substr(file.length() - 5) == ".webp")
        //     {
        //         type = "image/webp";
        //     }
        //     else
        //         file = file.substr(1, file.length() - 1);
        //     std::cout << "file = "  << file << std::endl;
        //     send_to += "Content-Type: ";
        //     send_to += type;
        //     send_to += "\r\n\r\n";
        //     std::cout << send_to << std::endl;
        //     std::ifstream f(file);
        //     if (f.fail ())
        //         exit(1);
        //     std::string r;
        //     while (std::getline(f, r))
        //     {
        //         send_to += r;
        //     }
        //     std::cout << send_to << std::endl;
        //     send(new_socket, send_to.c_str(), send_to.length(), 0);
        //     // send_to = "HTTP/1.1 200 OK\nContent-Type:text/html\nContent-Length: 180\n\n\n<h1 >testing</h1>\n\n<h1 style=""color:Tomato;"">Hello World</h1>\n<p style=""color:DodgerBlue;"">Lorem ipsum...</p>\n<p style=""color:MediumSeaGreen;"">Ut wisi enim...</p>\n";

        //     // printf("%s\n", msg);
        //     // free(msg);
        //     // char *send_to = malloc(10000);
        //     // if (!send_to)
        //     //     return (0);
        //     // send_to = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        //     // printf("%s\n", send_to);
        //     // write (new_socket, send_to, strlen(send_to));
            
        //     // free send_to
        //     // if (send_to)
        //     //     free(send_to);
        //     close(new_socket);
        // }
        // printf("fd value = %d", socket_fd);
    // else
    // {
    //     std::cerr << "Invalid Number Of Agruments" << std::endl;
    //     return (1);
    // }
}
