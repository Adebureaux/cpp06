#include "../includes/Literal.hpp"

Literal::Literal() {}

Literal::Literal(const Literal &other)
{
	*this = other;
}

Literal &Literal::operator=(const Literal &other)
{
	this->conv = other.conv;
	return (*this);
}

Literal::~Literal() {}

void Literal::findType(std::string av)
{
	std::cout << av << std::endl;
	std::cout << std::atof(av.c_str()) << std::endl;
	// literal.argv = av[1];
	// // Check type :
	// // Char
	// // Int
	// // Float
	// // Double
	// if (!literal.argv.find('f'))
	// 	std::cout << "it's a float" << std::endl;
}
