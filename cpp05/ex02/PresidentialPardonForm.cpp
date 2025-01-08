#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) :
AForm(_target, 25, 5), target(_target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& scf) :
AForm(scf.target, scf.getReqSign(), scf.getReqExec()), target(scf.target){}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other){
    if (&other != this){
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& brt) const{
    if (getSign() != true && brt.getGrade() > getReqSign())
        throw AForm::NotBeSigned();
    if (brt.getGrade() > this->getReqExec())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}