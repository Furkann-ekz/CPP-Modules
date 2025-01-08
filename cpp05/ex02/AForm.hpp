#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool  sign;
        const int grdReqSign;
        const int grdReqExec;
    public:
        AForm(std::string name, int grdReqSign, int grdReqExec);
        AForm(AForm const& AForm);
        virtual ~AForm();
        AForm& operator=(AForm const& other);

        class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
        class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };
        class NotBeSigned           : public std::exception { public: const char* what() const throw(); };

        std::string getName()       const;
        bool        getSign()       const;
        int         getReqSign()    const;
        int         getReqExec()    const;

        void        beSigned(Bureaucrat const& brt) throw(std::exception);
        void        cntrlSign(Bureaucrat const& brt) throw(std::exception);

        virtual void execute(Bureaucrat const& brt) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm const& AForm);