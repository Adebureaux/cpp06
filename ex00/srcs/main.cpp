#include "../includes/Literal.hpp"

int main(int ac, char **av)
{
	Literal literal;

	if (ac < 2)
	{
		std::cout << av[0] << " must have at least one argument to convert" << std::endl;
		return (1);
	}
	literal.findType(av[1]);


	return (0);	
}
