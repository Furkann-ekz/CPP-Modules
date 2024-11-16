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
			cout << "For 'DEBUG':\t1\nFor 'INFO':\t2\nFor 'WARNING':\t3\nFor 'ERROR':\t4\nChoose a level: ";
			getline(cin, input);
			cout << endl;
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