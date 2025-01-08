#include "AForm.hpp"

AForm::AForm(std::string _name, int _grdReqSign, int _grdReqExec)
: name(_name), grdReqSign(_grdReqSign), grdReqExec(_grdReqExec)
{}

AForm::AForm(AForm const& AForm)
: name(AForm.name), sign(AForm.sign), grdReqSign(AForm.grdReqSign), grdReqExec(AForm.grdReqExec)
{}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& other){
    if (&other != this){
        this->sign = other.sign;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade Too High!"; }
const char* AForm::GradeTooLowException::what()  const throw() { return "Grade Too Low!"; }
const char* AForm::NotBeSigned::what()           const throw() { return "Not be signed!"; }

std::string AForm::getName()const   { return this->name; }
bool        AForm::getSign()const   { return this->sign; }
int         AForm::getReqSign()const{ return this->grdReqSign; }
int         AForm::getReqExec()const{ return this->grdReqExec; }

void        AForm::beSigned(Bureaucrat const& brt) throw(std::exception) {
    if (brt.getGrade() > this->grdReqSign){
        throw AForm::GradeTooLowException();
    }
    this->sign = true;
}



std::ostream& operator<<(std::ostream& os, AForm const& AForm){
    os << AForm.getName() << ", grade request sign " 
        << AForm.getReqSign() << ", grade request execute "
        << AForm.getReqExec();
    return os;
}