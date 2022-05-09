#ifndef LITERAL_HPP
# define LITERAL_HPP
#include <iostream>
#include <string>
#include <cstdlib>

class Literal
{
	public:
	Literal();
	Literal(std::string str);
	Literal(const Literal &other);
	Literal &operator=(const Literal &other);
	~Literal();

	void findType(std::string av);

	private:
	std::string	argv;
	void*		conv;
};
#endif
