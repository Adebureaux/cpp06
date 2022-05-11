#ifndef BASE_HPP
# define BASE_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
	Base();
	Base(const Base &other);
	Base &operator=(const Base &other);
	~Base();

	private:
};

#endif
