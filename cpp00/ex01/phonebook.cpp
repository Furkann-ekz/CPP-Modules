#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->id = 1;
	this->max = 0;
}

int	ft_isdigit(const string &str)
{
	size_t	i = -1;
	while (++i < str.length())
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}

int	ft_atoi(const string &str)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (str[i] - 48) + (10 * count);
		i++;
	}
	return (count * sign);
}

void	PhoneBook::add(void)
{
	string	name;
	string	surname;
	string	nick;
	string	number;
	string	secret;

	while (1)
	{
		cout << "Name: ";
		getline(cin, name);
		if (name.empty())
			continue ;
		cout << "Surname: ";
		getline(cin, surname);
		if (surname.empty())
			continue ;
		cout << "Nick Name: ";
		getline(cin, nick);
		if (nick.empty())
			continue ;
		cout << "Phone Number: ";
		getline(cin, number);
		if (ft_isdigit(number) == 0 || number.empty())
			continue ;
		cout << "Darkest Secret: ";
		getline(cin, secret);
		if (secret.empty())
			continue ;
		this->conts[this->id++].set_Contact(name, surname, nick, number, secret);
		if (this->id == 9)
			this->id = 1;
		if (this->max < 8)
			this->max++;
		break ;
	}
}

void PhoneBook::search(void)
{
	int		index;
	int		i = 0;
	string	input;

	cout << endl << "     Index|      Name|   Surname|  Nickname" << endl;
	cout << "-----------------------------------------------" << endl;

	while (i++ < this->max)
	{
		cout << std::setw(10) << i << "|";
		if (this->conts[i].get_values(0).length() > 9)
			cout << std::setw(10) << this->conts[i].get_values(0).substr(0, 9) + "." << "|";
		else
			cout << std::setw(10) << this->conts[i].get_values(0) << "|";

		if (this->conts[i].get_values(1).length() > 9)
			cout << std::setw(10) << this->conts[i].get_values(1).substr(0, 9) + "." << "|";
		else
			cout << std::setw(10) << this->conts[i].get_values(1) << "|";

		if (this->conts[i].get_values(2).length() > 9)
			cout << std::setw(10) << this->conts[i].get_values(2).substr(0, 9) + "." << "|" << endl;
		else
			cout << std::setw(10) << this->conts[i].get_values(2) << "|" << endl;
	}

	while (true)
	{
		cout << "Please enter the index of the contact you want to view: ";
		std::getline(cin, input);

		if (!input.empty() && std::isdigit(input[0]))
		{
			index = std::stoi(input);
			if (index >= 1 && index <= this->max)
			{
				cout << "Name: " << this->conts[index].get_values(0) << endl;
				cout << "Surname: " << this->conts[index].get_values(1) << endl;
				cout << "Nickname: " << this->conts[index].get_values(2) << endl;
				cout << "Phone Number: " << this->conts[index].get_values(3) << endl;
				cout << "Darkest Secret: " << this->conts[index].get_values(4) << endl;
				break;
			}
			else
				cout << "Invalid index. Please try again." << endl;
		}
		else
			cout << "Invalid input. Please enter a valid index." << endl;
	}
}
