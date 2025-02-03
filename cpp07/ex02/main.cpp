#include "Array.hpp"

#define RANGE 15
int main(void)
{
	Array<int> numbers_null;
	Array<std::string> chr_null;
	
	Array<int> numbers(RANGE);
	std::srand(std::time(NULL));
	
	for (int i = 0; i < RANGE; i++)
	{
		
		try
		{
		   numbers[i] = std::rand();
		}
		catch(const std::exception& e)
		{
			cerr << "Exception: " << e.what() << endl;
		}
	}
	for (int i = 0; i < RANGE; i++)
	{
		cout << numbers[i] << endl;
	}
	

	Array<double> numbers_d(RANGE);
	for (int i = 0; i < RANGE; i++)
	{
		
		try
		{
		   numbers_d[i] = std::rand();
		}
		catch(const std::exception& e)
		{
			cerr << "Exception: " << e.what() << endl;
		}
	}
	 for (int i = 0; i < RANGE; i++)
	{
		cout << numbers_d[i] << endl;
	}

	Array<char> chr(RANGE);
	for (int i = 0; i < RANGE; i++)
	{
		try
		{
			int randomNumber = std::rand() % 26;
			chr[i] = 'A' + randomNumber;
		}
		catch(const std::exception& e)
		{
			cerr << e.what() << endl;
		}
	}
	for (int i = 0; i < RANGE; i++)
	{
		cout << chr[i] << endl;
	}

	try
	{
		cout << "numbers size: " << numbers.size() << endl;
		numbers[20] = 5;
	}
	catch(const std::exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		numbers[RANGE] = 0;
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	try
	{
		chr[RANGE] = 'A';
	}
	catch(const std::exception& e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}