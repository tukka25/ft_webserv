# include "webserv.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac == 2)
    {
        std::cout << "On" << std::endl;
    }
    else
    {
        std::cerr << "Invalid Number Of Agruments" << std::endl;
        return (1);
    }
}
