#include "MutantStack.hpp"

void pdf_test(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

int main()
{
	pdf_test();
	std::cout << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(42);
	mstack.push(99);

	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Top element after pop(): " << mstack.top() << std::endl;

	std::cout << "Elements in the stack: ";
	MutantStack<int>::iterator it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	return 0;
}