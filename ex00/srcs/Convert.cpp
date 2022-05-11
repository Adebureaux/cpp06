#include "../includes/Convert.hpp"

Convert::Convert() {}

Convert::Convert(std::string literal)
{
	char	*endptr;

	if (!std::isdigit(literal[0]) && !literal[1])
		_val = static_cast<int>(literal[0]);
	else
	{
		// Should use an other way to convert ...
		// Use an atof and add endptr !
		//_val = std::strtod(literal.c_str(), &endptr);
		if (endptr[0] && (endptr[0] != 'f' || endptr[1]))
		{
			std::cout << "cannot convert : wrong argument" << std::endl;
			std::exit(1);
		}
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
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
	std::cout << "char   : ";
	if (isnan(this->_val))
		std::cout << "Impossible" << std::endl;
	else if (_val >= 32 && _val <= 127)
		std::cout << static_cast<char>(_val) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void Convert::printInt(void)
{
	std::cout << "int    : ";
	if (isnan(this->_val))
		std::cout << "Impossible" << std::endl;
	else if (this->_val < static_cast<double>(INT_MIN))
		std::cout << "Underflow" << std::endl;
	else if (this->_val > static_cast<double>(INT_MAX))
		std::cout << "Overflow" << std::endl;
	else
		std::cout << static_cast<int>(_val) << std::endl;
}

void Convert::printFloat(void)
{
	std::cout << "float  : ";
	std::cout << std::setprecision(1) << std::fixed << static_cast<float>(_val) << 'f' << std::endl;
}

void Convert::printDouble(void)
{
	std::cout << "double : ";
	std::cout << std::setprecision(1) << std::fixed << static_cast<double>(_val) << std::endl;
}
