#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->id = 1;
	this->max = 1;
}

int	ft_isdigit(const string &str)
{
	size_t	i = -1;
	while (++i < str.length())
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	return (0);
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

string	get_no_empty_values(string value)
{
	string	str;

	while (1)
	{
		cout << value;
		getline(cin, str);
		if (!(str.empty()) && !(value == "Phone Number: "))
			break ;
		else if (value == "Phone Number: ")
			if (!(ft_isdigit(str)) && !(str.empty()))
				break ;
	}
	return (str);
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
		surname = get_no_empty_values("Surname: ");
		nick = get_no_empty_values("Nick Name: ");
		number = get_no_empty_values("Phone Number: ");
		secret = get_no_empty_values("Darkest Secret: ");
		this->conts[this->id - 1].set_Contact(name, surname, nick, number, secret);
		this->id++;
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

	while (i < this->max)
	{
		cout << std::setw(10) << i + 1 << "|";
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
		i++;
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
				cout << "Name: " << this->conts[index - 1].get_values(0) << endl;
				cout << "Surname: " << this->conts[index - 1].get_values(1) << endl;
				cout << "Nickname: " << this->conts[index - 1].get_values(2) << endl;
				cout << "Phone Number: " << this->conts[index - 1].get_values(3) << endl;
				cout << "Darkest Secret: " << this->conts[index - 1].get_values(4) << endl;
				break;
			}
			else
				cout << "Invalid index. Please try again." << endl;
		}
		else
			cout << "Invalid input. Please enter a valid index." << endl;
	}
}
