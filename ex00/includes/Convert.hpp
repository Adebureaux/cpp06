#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

class Convert
{
	public:
	Convert();
	Convert(std::string literal);
	Convert(const Convert &other);
	Convert &operator=(const Convert &other);
	~Convert();

	void conversion(std::string literal);
	void printChar(void);
	void printInt(void);

	private:
	double _val;
};
#endif
