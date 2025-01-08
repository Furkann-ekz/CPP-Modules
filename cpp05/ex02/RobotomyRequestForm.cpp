#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) :
AForm(_target, 72, 45), target(_target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& scf) :
AForm(scf.target, scf.getReqSign(), scf.getReqExec()), target(scf.target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other){
    if (&other != this){
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& brt) const{
    if (getSign() != true && brt.getGrade() > getReqSign())
        throw AForm::NotBeSigned();
    if (brt.getGrade() > this->getReqExec())
        throw AForm::GradeTooLowException();
    static int i;
    if (i % 2 == 0){
        std::cout << "Bızzz " << target << " has been robotomized" << std::endl;
    }else{
        std::cout << target << " robotomy failed" << std::endl;
    }
    i++;
}