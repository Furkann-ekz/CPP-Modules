#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Alice", 1);
		cout << b << endl;

		b.incrementGrade();
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Bureaucrat c("Bob", 150);
		cout << c << endl;

		c.decrementGrade();
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Bureaucrat d("Charlie", 42);
		cout << d << endl;

		d.incrementGrade();
		cout << d << endl;

		d.decrementGrade();
		cout << d << endl;
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
