#pragma once

#include "RobotomyRequestForm.hpp"
#include <ctime>

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const& scf);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

        void    execute(Bureaucrat const& brt) const;        
};