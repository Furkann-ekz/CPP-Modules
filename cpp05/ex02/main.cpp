#include "PresidentialPardonForm.hpp"


int main(){
    {
        ShrubberyCreationForm scf("House");
        Bureaucrat brt("Süleyman", 145);
        Bureaucrat brt1("Ahmet", 130);
		Bureaucrat brt2("Mehmet", 146);
		brt.executeForm(scf);
		brt1.executeForm(scf);
		brt2.executeForm(scf);  
	}
    std::cout << "---------" << std::endl;
    {
		RobotomyRequestForm rrf("Amazon");
       	Bureaucrat brt("Süleyman", 72);
        Bureaucrat brt1("Ahmet", 45);
		Bureaucrat brt2("Mehmet", 73);
		brt.executeForm(rrf);
		brt1.executeForm(rrf);
		brt2.executeForm(rrf);  
    }
    std::cout << "---------" << std::endl;
    {
    	PresidentialPardonForm ppf("Trump");
       	Bureaucrat brt("Süleyman", 25);
        Bureaucrat brt1("Ahmet", 5);
		Bureaucrat brt2("Mehmet",26);
		brt.executeForm(ppf);
		brt1.executeForm(ppf);
		brt2.executeForm(ppf);  
    }

}