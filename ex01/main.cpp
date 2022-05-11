#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main(void)
{
	Data ptr;

	ptr.n = 42;
	std::cout << ptr.n << std::endl << std::endl;

	uintptr_t raw = serialize(&ptr);
	std::cout << "0x" << std::hex << raw << std::endl;
	std::cout << &ptr << std::endl << std::endl;

	Data *ptr_raw = deserialize(raw);
	std::cout << std::dec << ptr_raw << std::endl;
	std::cout << ptr_raw->n << std::endl;
	return (0);	
}
