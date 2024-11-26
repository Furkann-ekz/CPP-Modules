#include "iostream"

using std::string;
using std::cout;
using std::endl;

int	main()
{
	string	s = "HI THIS IS BRAIN";
	string	*p = &s;
	string	&r = s;

	cout << "String adres:\t\t" << &s << endl;
	cout << "Pointer adress:\t\t" << p << endl;
	cout << "Referance adress:\t" << &r << endl;

	cout << endl;

	cout << "String:\t\t" << s << endl;
	cout << "Pointer:\t" << *p << endl;
	cout << "Referance:\t" << r << endl;
	cout << endl;
}
