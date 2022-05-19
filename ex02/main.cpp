#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch ((rand() % 3) + 1)
	{
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
	}
	return (NULL);
}

void identify(Base * p)
{
	A * a = dynamic_cast<A*>(p);
	B * b = dynamic_cast<B*>(p);
	C * c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "Address of A: " << a << std::endl;
	else if (b)
		std::cout << "Address of B: " << b << std::endl;
	else if (c)
		std::cout << "Address of C: " << c << std::endl;
}

void identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Address of A: " << &p << std::endl;
	}
	catch (std::exception) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Address of B: " << &p << std::endl;
	}
	catch (std::exception) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Address of C: " << &p << std::endl;
	}
	catch (std::exception) {}
}

int main(void)
{
	srand(time(NULL));
	Base * r1 = generate();
	Base * r2 = generate();
	Base * r3 = generate();

	identify(r1);
	identify(r2);
	identify(r3);

	std::cout << std::endl;

	identify(*r1);
	identify(*r2);
	identify(*r3);

	delete r1;
	delete r2;
	delete r3;
	return (0);	
}
