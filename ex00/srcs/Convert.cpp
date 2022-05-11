#include "../includes/Convert.hpp"

Convert::Convert() {}

double Convert::stof(const char *s)
{
  double a = 0.0;
  int e = 0;
  int c;
  while ((c = *s++) != '\0' && isdigit(c)) {
    a = a*10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  if (c == 'e' || c == 'E') {
    int sign = 1;
    int i = 0;
    c = *s++;
    if (c == '+')
      c = *s++;
    else if (c == '-') {
      c = *s++;
      sign = -1;
    }
    while (isdigit(c)) {
      i = i*10 + (c - '0');
      c = *s++;
    }
    e += i*sign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}

Convert::Convert(std::string literal)
{
	//char	*endptr;

	if (!std::isdigit(literal[0]) && !literal[1])
		_val = static_cast<int>(literal[0]);
	else
	{
		// Should use an other way to convert ...
		// Use an atof and add endptr !
		//_val = std::strtod(literal.c_str(), &endptr);
		_val = stof(literal.c_str());
		_val = nan(NULL);
		// if (endptr[0] && (endptr[0] != 'f' || endptr[1]))
		// {
		// 	std::cout << "cannot convert : wrong argument" << std::endl;
		// 	std::exit(1);
		// }
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
