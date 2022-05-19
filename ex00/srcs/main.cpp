#include "../includes/Convert.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << av[0] << " must have one (and only one) argument to convert" << std::endl;
		return (1);
	}
	Convert obj(av[1]);
	return (0);
}
