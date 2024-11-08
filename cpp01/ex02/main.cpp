#include "iostream"

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*p = &s;
	std::string	&r = s;

	std::cout << "String adres: " << &s << std::endl;
	std::cout << "Pointer adress: " << p << std::endl;
	std::cout << "Referance adress: " << &r << std::endl;

	std::cout << "String: " << s << std::endl;
	std::cout << "Pointer: " << *p << std::endl;
	std::cout << "Referance: " << r << std::endl;
}
