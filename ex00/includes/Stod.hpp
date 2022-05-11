#ifndef STOD_HPP
# define STOD_HPP

#include <iostream>
#include <string>

class Stod
{
	public:
	Stod();
	Stod(char *str, char **ptr);
	Stod(const Stod &other);
	Stod &operator=(const Stod &other);
	~Stod();

	double d;
};

#endif
