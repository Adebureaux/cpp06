#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cmath>
#include <iomanip>

class Convert
{
	public:
	Convert();
	Convert(std::string literal);
	Convert(const Convert &other);
	Convert &operator=(const Convert &other);
	~Convert();

	void	printChar(void) const;
	void 	printInt(void) const;
	void 	printFloat(void) const;
	void 	printDouble(void) const;
	double	stringToDouble(const std::string & literal, std::string & endptr);

	private:
	double	_val;
	int		_precision;
};
#endif
