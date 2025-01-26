#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern					intern;
		Bureaucrat				bureaucrat("Darly", 30);
		PresidentialPardonForm	pardonForm("Maggie");
		RobotomyRequestForm		robotomyForm("Jesus");
		ShrubberyCreationForm	shrubberyForm("home");

		AForm *aform;
		aform = intern.makeForm("robotomy request", "David");
		cout << endl;
		bureaucrat.signForm(shrubberyForm);
		bureaucrat.signForm(robotomyForm);
		bureaucrat.signForm(pardonForm);

		cout << endl;
		bureaucrat.executeForm(shrubberyForm);
		bureaucrat.executeForm(robotomyForm);
		bureaucrat.executeForm(pardonForm);

		bureaucrat.signForm(*aform);
		bureaucrat.executeForm(*aform);

		delete aform;
	}
	catch (const exception &e)
	{
		cout << "Exception occurred: " << e.what() << endl;
	}
	return 0;
}
