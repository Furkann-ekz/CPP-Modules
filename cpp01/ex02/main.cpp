#include "iostream"

using std::string;
using std::cout;
using std::endl;

int	main()
{
	string	s = "HI THIS IS BRAIN";
	string	*p = &s;
	string	&r = s;

	cout << "String adres: " << &s << endl;
	cout << "Pointer adress: " << p << endl;
	cout << "Referance adress: " << &r << endl;

	cout << "String: " << s << endl;
	cout << "Pointer: " << *p << endl;
	cout << "Referance: " << r << endl;
}
