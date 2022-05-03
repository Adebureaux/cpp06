#ifndef LITERAL_HPP
# define LITERAL_HPP
#include <iostream>
#include <string>

class Literal
{
	public:
	Literal();
	Literal(std::string str);
	Literal(const Literal &other);
	Literal &operator=(const Literal &other);
	~Literal();

	private:
	std::string	argv;
	void*		conv;
};
#endif
