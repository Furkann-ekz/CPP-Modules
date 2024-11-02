#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	string		command;

	cout << "Welcome to the PhoneBook Application!" << endl;
	cout << "Available commands: ADD, SEARCH, EXIT" << endl;
	while (true)
	{
		cout << "Enter a command: ";
		std::getline(std::cin, command);

		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
		{
			cout << "Exiting PhoneBook Application. Goodbye!" << endl;
			break;
		}
		else
			cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << endl;
	}
}
