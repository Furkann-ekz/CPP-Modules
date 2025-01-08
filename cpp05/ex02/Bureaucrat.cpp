#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& _name, int _grade): name(_name){
    if (_grade < 1){
        throw Bureaucrat::GradeTooHighException();
    }else if (_grade > 150){
        throw Bureaucrat::GradeTooLowException();
    }else{
        this->grade = _grade;
    }
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other){
    if (this != &other){
        this->grade = other.getGrade();
    }
    return (*this);
}

std::string Bureaucrat::getName() const { return (this->name); }
int         Bureaucrat::getGrade() const { return (this->grade); }

void        Bureaucrat::incrementGrade() { grade - 1 < 1 ? throw Bureaucrat::GradeTooHighException() : grade -= 1; }
void        Bureaucrat::decrementGrade() { grade + 1 > 150 ? throw Bureaucrat::GradeTooLowException() : grade += 1; }


const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Garde too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Garde too low"; }

void        Bureaucrat::signForm(AForm& form){
    try{
        form.beSigned(*this);
        std::cout << *this << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << *this << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
    }
}

void        Bureaucrat::executeForm(AForm const& form){
    try{
        form.execute(*this);
        std::cout << *this << " executed " << form << std::endl;
    }catch(const std::exception& e){
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src){
    os << src.getName() + ", bureaucrat grade " << src.getGrade();
    return (os);
}