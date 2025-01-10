#include "Form.hpp"

Form::Form() : name("Form"), isSigned(false), signGrade(1), executeGrade(1) {} 

Form::Form(const string &name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
	{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade) {}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->isSigned = src.isSigned;
	return *this;
}

Form::~Form() {}

string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getSignGrade() const
{
	return (signGrade);
}

int Form::getExecuteGrade() const
{
	return (executeGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
	os << "Form " << f.getName();
	os << ", signed: " << (f.getIsSigned() ? "true" : "false");
	os << ", sign grade: " << f.getSignGrade();
	os << ", execute grade: " << f.getExecuteGrade() << endl;
	return (os);
}
