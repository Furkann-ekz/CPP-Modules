#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat alice("Alice", 10);
		Form form("FormA", 5, 20);

		cout << form << endl;

		alice.signForm(form);

		cout << form << endl;

		try
		{
			Form invalidForm("InvalidForm", 0, 200);
		}
		catch (const exception &e)
		{
			cout << e.what() << endl;
		}

		Bureaucrat bob("Bob", 50);
		try
		{
			bob.signForm(form);
		}
		catch (const exception &e)
		{
			cout << e.what() << endl;
		}
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

