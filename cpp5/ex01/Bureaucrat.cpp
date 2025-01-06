#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(10) {}

Bureaucrat::Bureaucrat(const string n, int grade) : name(n), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const string& Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

void Bureaucrat::signForm(Form &form)
{
    try
	{
        form.beSigned(*this);
        cout << name << " signed " << form.getName() << endl;
    }
	catch (exception &e)
	{
        cout << name << " couldn't sign " << form.getName() << " because " << e.what() << endl;
    }
}