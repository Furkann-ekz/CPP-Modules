#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& scf);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);

        void    execute(Bureaucrat const& brt) const;        
};