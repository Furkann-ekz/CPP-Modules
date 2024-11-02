#include "Contact.hpp"

Contact::Contact()
{
	this->name = "";
	this->surname = "";
	this->nick = "";
	this->number = "";
	this->secret = "";
}

void	Contact::set_Contact(string name, string surname, string nick, string number, string secret)
{
	this->name = name;
	this->surname = surname;
	this->nick = nick;
	this->number = number;
	this->secret = secret;
}

string	Contact::get_values(int x)
{
	if (x == 0)
		return (this->name);
	else if (x == 1)
		return (this->surname);
	else if (x == 2)
		return (this->nick);
	else if (x == 3)
		return (this->number);
	else if (x == 4)
		return (this->secret);
	return ("");
}
