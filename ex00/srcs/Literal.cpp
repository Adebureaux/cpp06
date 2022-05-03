#include "../includes/Literal.hpp"

Literal::Literal() {}

Literal::Literal(std::string str) {}

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
