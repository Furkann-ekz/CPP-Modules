#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const string &formName, const string &target)
{
	const string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*formCreators[3])(const string &) = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			cout << "Intern creates " << formName << endl;
			return formCreators[i](target);
		}
	}
	cout << "Error: Form name \"" << formName << "\" does not exist." << endl;
	return NULL;
}