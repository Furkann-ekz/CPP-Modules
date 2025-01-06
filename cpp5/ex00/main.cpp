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
		std::cerr << e.what() << endl;
	}

	try
	{
		Bureaucrat c("Bob", 151);
	}
	catch (const exception &e)
	{
		std::cerr << e.what() << endl;
	}

	return 0;
}
