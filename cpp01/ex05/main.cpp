#include "Harl.hpp"

string	inputvalue()
{
	string	input;


	if (input.empty())
	{
		while (input.empty())
			cin >>input;
	}
	return (input);
}

int main()
{
	Harl	harl;
	string	input;

	while (1)
	{
		while (1)
		{
			cout << "1\n2\n3\n4\nChoose a level: ";
			getline(cin, input);
			if (!(input.empty()))
				break ;
		}
		if (input == "exit")
			break;
		if (!cin.good())
		{
			cout << endl;
			break;
		}
		harl.complain(input);
	}
	return (0);
}