#include "../includes/Literal.hpp"

int main(int ac, char **av)
{
	Litteral literal;

	if (ac < 2)
	{
		std::cout << av[0] << " must have at least one argument to convert" << std::endl;
		return (1);
	}

	literal.argv = av[1];
	// Check type :
	// Char
	// Int
	// Float
	// Double
	if (!literal.argv.find('f'))
		std::cout << "it's a float" << std::endl;

	return (0);	
}
