#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>
#include <string>
#include <cstdlib>
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

	double stof(const char *s);
	void conversion(std::string literal);
	void printChar(void);
	void printInt(void);
	void printFloat(void);
	void printDouble(void);

	private:
	double _val;
};
#endif
