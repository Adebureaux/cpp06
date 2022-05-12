#include "../includes/Convert.hpp"

Convert::Convert() : _val(0), _precision(1) {}

Convert::Convert(std::string literal) : _precision(1)
{
	std::string endptr;

	if (!std::isdigit(literal[0]) && !literal[1])
		_val = static_cast<int>(literal[0]);
	else
	{
		_val = stringToDouble(literal, endptr);
		if ((endptr[0] && (endptr[0] != 'f' || endptr[1])) || literal.length() > 300)
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
	this->_precision = other._precision;
	return (*this);
}

Convert::~Convert() {}

void Convert::printChar(void) const
{
	std::cout << "char   : ";
	if (isnan(this->_val))
		std::cout << "Impossible" << std::endl;
	else if (_val >= 32 && _val <= 127)
		std::cout << "'" << static_cast<char>(_val) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void Convert::printInt(void) const
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

void Convert::printFloat(void) const
{
	std::cout << "float  : ";
	std::cout << std::setprecision(_precision) << std::fixed << static_cast<float>(_val) << 'f' << std::endl;
}

void Convert::printDouble(void) const
{
	std::cout << "double : ";
	std::cout << std::setprecision(_precision) << std::fixed << static_cast<double>(_val) << std::endl;
}

double Convert::stringToDouble(const std::string & literal, std::string & endptr)
{
	int		i = 0;
	int		e = 0;
	int		c = 0;
	int		sign = 1;
	double	val = 0.0;

	// Handle sign
	if (literal[i] == '+')
		i++;
	else if (literal[i] == '-')
	{
		i++;
		sign = -1;
	}
	// Handle inf
	if (literal.substr(i, 3) == "inf")
	{
		i += 3;
		val = std::numeric_limits<double>::infinity();
	}
	// Handle nan
	else if (literal.substr(i, 3) == "nan")
	{
		i += 3;
		val = std::numeric_limits<double>::quiet_NaN();
	}
	// Convert string into a double
	else
	{
		while ((c = literal[i++]) && isdigit(c))
		{
			val = val * 10.0 + (c - '0');
		}
		if (c == '.')
		{
			_precision = 0;
			while ((c = literal[i++]) && isdigit(c))
			{
				val = val * 10.0 + (c - '0');
				e--;
				_precision++;
			}
		}
		while (e > 0)
		{
			val *= 10.0;
			e--;
		}
		while (e < 0)
		{
			val *= 0.1;
			e++;
		}
		i--;
	}
	// Set endptr and return converted value
	endptr = literal.substr(i);
	return (val * sign);
}
