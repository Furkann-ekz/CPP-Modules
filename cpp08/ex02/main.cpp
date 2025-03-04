#include "MutantStack.hpp"

void testFromPdf()
{
	cout << "Testing MutantStack with test from the PDF" << endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	cout << "Top element: " << mstack.top() << endl;
	mstack.pop();
	cout << "Size of mstack: " <<  mstack.size() << endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	cout << "Elements of mstack: " << endl;
	while (it != ite)
	{
		cout << *it << endl;
		++it;
	}
	std::stack<int> s(mstack);

}

void testIterator()
{
	cout <<  "Starting the test of mine for iterator feature." << endl;
	MutantStack<int> stack;

	stack.push(10);
	cout << "Adding 10 to stack." << endl;
	stack.push(20);
	cout << "Adding 20 to stack." << endl;
	stack.push(30);
	cout << "Adding 30 to stack." << endl;

	MutantStack<int>::iterator it = stack.begin();
	
	cout << "First element of stack: " << *it << endl;
	if (*it != 10)
	   { std::cerr << "Test failed: Iterator should point to 10" << endl; return; }
	
	++it;
	cout << "Secont element of stack: " << *it << endl;
	if (*it != 20)
		{ std::cerr << "Test failed: Iterator should point to 20" << endl; return; }
	
	++it;
	cout << "Third element of stack: " << *it << endl;
	if (*it != 30)
		{ std::cerr << "Test failed: Iterator should point to 30" << endl; return; }

	++it;
	if (it != stack.end())
		{ std::cerr << "Test failed: Iterator should be at the end after moving past the last element" << endl; return; }

	cout << "Iterator test passed!" << endl;
}

int main()
{
	testFromPdf();
	testIterator();
	return 0;
}