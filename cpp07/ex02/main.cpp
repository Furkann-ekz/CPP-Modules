#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<int> arr(5);

		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i * 2;

		for (unsigned int i = 0; i < arr.size(); i++)
			cout << "arr[" << i << "] = " << arr[i] << endl;

		cout << "\nOut-of-bound index'e erişim deneniyor:" << endl;
		cout << arr[5] << endl;
	}
	catch (std::exception &e)
	{
		cout << "Exception caught: " << e.what() << endl;
	}

	Array<int> a(3);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i + 1;

	Array<int> b(a);
	cout << "\nCopy constructor test:" << endl;

	for (unsigned int i = 0; i < b.size(); i++)
		cout << "b[" << i << "] = " << b[i] << endl;

	Array<int> c;
	c = a;
	cout << "\nAssignment operator test:" << endl;

	for (unsigned int i = 0; i < c.size(); i++)
		cout << "c[" << i << "] = " << c[i] << endl;

	return 0;
}