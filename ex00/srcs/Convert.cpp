#include "../includes/Convert.hpp"

Convert::Convert() {}

Convert::Convert(std::string literal)
{
	char	*endptr;

	if (!std::isdigit(literal[0]) && !literal[1])
		_val = static_cast<int>(literal[0]);
	else
	{
		_val = std::strtod(literal.c_str(), &endptr);
		if (endptr[0] && (endptr[0] != 'f' || endptr[1]))
		{
			std::cout << "wrong argument" << std::endl;
			std::exit(1);
		}
	}
	printChar();
	printInt();
}

Convert::Convert(const Convert &other)
{
	*this = other;
}

Convert &Convert::operator=(const Convert &other)
{
	this->_val = other._val;
	return (*this);
}

Convert::~Convert() {}

void Convert::printChar(void)
{
	std::cout << "char: ";
	if (_val >= 32 && _val <= 127)
		std::cout << static_cast<char>(_val) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void Convert::printInt(void)
{
	std::cout << "Int: ";
	if (this->_val < static_cast<double>(INT_MIN))
		std::cout << "underflow" << std::endl;
	else if (this->_val > static_cast<double>(INT_MAX))
		std::cout << "overflow" << std::endl;
	else
		std::cout << static_cast<int>(_val) << std::endl;
}

// char	*endptr;
// double	val;

// BEFORE
// std::cout << literal << std::endl;

// CHECK CHAR
// if (std::isdigit(literal[0]))
// 	std::cout << "is not numerical" << std::endl;
// val = std::strtod(literal.c_str(), &endptr);

// AFTER
// std::cout << val << std::endl;
// std::cout << endptr << std::endl;
// std::cout << std::strerror(errno) << std::endl;
// literal.argv = av[1];
// // Check type :
// // Char
// // Int
// // Float
// // Double
// if (!literal.argv.find('f'))
// 	std::cout << "it's a float" << std::endl;
