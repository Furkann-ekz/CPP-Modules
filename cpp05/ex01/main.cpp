#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 10);
		Form form("form", 5, 20);

		cout << form << endl;

		alice.signForm(form);
		cout << form << endl;

		Bureaucrat gurney("Gurney", 4);
		gurney.signForm(form);
		cout << form << endl;

	}
	catch (exception &e)
	{
		std::cerr << e.what() << endl;
	}

	return 0;
}
