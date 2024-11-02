#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "iostream"
# include "limits"
# include "string"
# include "iomanip"

using	std::cout;
using	std::string;
using	std::endl;
using	std::cin;
using	std::getline;

class	Contact
{
	private:
		string	name;
		string	surname;
		string	nick;
		string	number;
		string	secret;
	public:
		Contact();
		void	set_Contact(string name, string surname, string nick, string number, string secret);
		string	get_values(int x);
};

#endif