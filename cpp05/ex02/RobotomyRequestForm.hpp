#pragma once

#include "ShrubberyCreationForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const& scf);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

        void    execute(Bureaucrat const& brt) const;        
};