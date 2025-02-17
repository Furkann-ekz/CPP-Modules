#include "EasyFind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> numbers;
	for (int i = 1; i <= 5; ++i)
		numbers.push_back(i * 10);
	
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 100);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}