#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;

	public:
		Form();
		Form(const string& name, int signGrade, int executeGrade);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
