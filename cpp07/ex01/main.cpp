#include "iter.hpp"

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	cout << "Integer array: ";
	iter(intArray, 5, printElement<int>);
	cout << endl;

	string strArray[] = {"Hello", "World", "42"};
	cout << "String array: ";
	iter(strArray, 3, printElement<string>);
	cout << endl;

	return 0;
}