#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "string"

using std::string;
using std::endl;
using std::cout;
using std::exception;

class Bureaucrat
{
	private:
		const string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const string n, int grade);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat();

		const string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
